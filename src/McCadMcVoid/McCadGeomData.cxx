#include "McCadGeomData.hxx"

#include <McCadDiscDs_DiscSolid.hxx>
#include <McCadDiscDs_HSequenceOfDiscSolid.hxx>

#include "McCadVoidCellManager.hxx"
#include "McCadConvexSolid.hxx"
#include "McCadGeomPlane.hxx"
#include "McCadGeomCylinder.hxx"
#include "McCadGeomCone.hxx"
#include "McCadGeomSphere.hxx"
#include "McCadGeomTorus.hxx"
#include "McCadGeomRevolution.hxx"

#include <TopoDS.hxx>
#include <TopExp_Explorer.hxx>
#include <Geom_Surface.hxx>
#include <BRep_Tool.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <assert.h>
#include <BRepBndLib.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <algorithm>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <OSD_Path.hxx>
#include <OSD_Protection.hxx>
#include <QStringList>

#include "../McCadTool/McCadMathTool.hxx"
#include "../McCadTool/McCadConvertConfig.hxx"
#include "../McCadTool/McCadGeomTool.hxx"

#include "GProp_GProps.hxx"
#include "BRepGProp.hxx"

McCadGeomData::McCadGeomData()
{
    m_iNumSolid = 0;                   // Initial the number of convex solid.
}

McCadGeomData::McCadGeomData(Handle_TopTools_HSequenceOfShape & solid_list, Standard_Boolean bVoid)
{
    InputData(solid_list,bVoid);
}

McCadGeomData::~McCadGeomData()
{
    if(m_pOutVoid != NULL)
    {
        delete m_pOutVoid;
        m_pOutVoid = NULL;
    }

    vector<McCadSolid *>::iterator iterSld;
    for (iterSld = m_SolidList.begin(); iterSld != m_SolidList.end(); ++iterSld)
    {
        if(*iterSld != NULL)
        {
            delete *iterSld;
            *iterSld = NULL;
        }
    }
    m_SolidList.clear();

    vector<McCadConvexSolid *>::iterator iterConvexSld;
    for (iterConvexSld = m_ConvexSolidList.begin(); iterConvexSld != m_ConvexSolidList.end(); ++iterConvexSld)
    {
        if(*iterConvexSld != NULL)
        {
            delete *iterConvexSld;
            *iterConvexSld = NULL;
        }
    }
    m_ConvexSolidList.clear();

    vector<McCadVoidCell *>::iterator iterVoidCell;
    for (iterVoidCell = m_VoidCellList.begin(); iterVoidCell != m_VoidCellList.end(); ++iterVoidCell)
    {
        if(*iterVoidCell != NULL)
        {
            delete *iterVoidCell;
            *iterVoidCell = NULL;
        }
    }
    m_VoidCellList.clear();

    vector<IGeomFace *>::iterator iterFace;
    for (iterFace = m_GeomSurfList.begin(); iterFace != m_GeomSurfList.end(); ++iterFace)
    {
        if(*iterFace != NULL)
        {
            delete *iterFace;
            *iterFace = NULL;
        }
    }
    m_GeomSurfList.clear();

    vector<McCadTransfCard *>::iterator iterTrfCard;
    for (iterTrfCard = m_TransfCardList.begin(); iterTrfCard != m_TransfCardList.end(); ++iterTrfCard)
    {
        if(*iterTrfCard != NULL)
        {
            delete *iterTrfCard;
            *iterTrfCard = NULL;
        }
    }
    m_TransfCardList.clear();
}


/** ********************************************************************
* @brief Get the material solids from the input file read, and generate
*        the surfaces list.
*
* @param[in] Handle_TopTools_HSequenceOfShape solid_list
* @return void
*
* @date 31/8/2012
* @author  Lei Lu
*********************************************************************/
void McCadGeomData::InputData( Handle_TopTools_HSequenceOfShape & solid_list, Standard_Boolean bGenVoid )
{
    m_listConvexSolid = new TopTools_HSequenceOfShape;      // create a shape list to store the convex material solids
    m_listVoidCell = new TopTools_HSequenceOfShape;         // create a shape list to store the void solids

    Standard_Integer iNumMatSolid = solid_list->Length();
    cout<< iNumMatSolid << "  Solids are read" << endl;

    for(int i = 1; i <= iNumMatSolid; i++)
    {
        cout<<endl;
        cout<<"Processing the "<<i<<" solid of "<<iNumMatSolid<<" solids"<<endl;

        /// TopoDS_Shape theShape = theEntSeq->Value(i).GetSolid();
        TopoDS_Shape theShape = solid_list->Value(i);
        TopExp_Explorer exp;

        /// If the solid is compound solid, explode each its lumps into solids firstly
        if( theShape.ShapeType() == TopAbs_COMPSOLID || theShape.ShapeType() == TopAbs_COMPOUND )
        {
            cout<<"yes. it is compoundsolid;"<<endl;
            int j = 0;
            McCadSolid * pSolidList = new McCadSolid();
            for(exp.Init(theShape,TopAbs_SOLID); exp.More(); exp.Next())
            {
                j++;
                TopoDS_Solid tmpSolid = TopoDS::Solid(exp.Current());
                McCadConvexSolid *pConvexSolid = NULL;             

                Standard_Real solid_mass = McCadGeomTool::GetVolume(tmpSolid);

                if(solid_mass >= 0.01)        // Set the minimum volume tolerance
                {
                    pConvexSolid = new McCadConvexSolid(tmpSolid);
                    pConvexSolid->SetVolume(solid_mass);
                }
                else
                {
                    cout<<"Detected a solid with small volume which is less than 0.01mm3: "<<pConvexSolid->GetVolume()<<endl;
                    continue;
                }

                AddGeomSurfList(pConvexSolid->GetSTLFaceList());    // Travelse the boundary faces, add in face list
                AddGeomAuxSurfList(pConvexSolid->GetSTLFaceList()); // Judge whether need add auxiliary faces
                pSolidList->AddConvexSolid(pConvexSolid);           // Add the convex solid into a complicate solid

                pConvexSolid->DeleteRepeatFaces(bGenVoid);           // Delete the repeated faces of solid

                m_ConvexSolidList.push_back(pConvexSolid);          // Add the convex solid in the solid list
                m_iNumSolid++;
            }
            m_SolidList.push_back(pSolidList);
        }
        // If the solid is single solid, add to convex solid list directly
        else if( theShape.ShapeType() == TopAbs_SOLID)
        {
            TopoDS_Solid tmpSolid = TopoDS::Solid(solid_list->Value(i));
            McCadConvexSolid *pConvexSolid = NULL;
            McCadSolid * pSolidList = new McCadSolid();

            GProp_GProps GP;
            BRepGProp::VolumeProperties(tmpSolid, GP);

            if(GP.Mass() >= 0.01)        // Set the minimum volume tolerance
            {
                pConvexSolid = new McCadConvexSolid(tmpSolid);
                pConvexSolid->SetVolume(GP.Mass());
            }
            else
            {
                cout<<"Detected a solid with small volume: "<<pConvexSolid->GetVolume()<<endl;
                continue;
            }          

            AddGeomSurfList(pConvexSolid->GetSTLFaceList());    // Travelse the boundary faces, add in face list
            AddGeomAuxSurfList(pConvexSolid->GetSTLFaceList()); // Judge whether need add auxiliary faces
            pSolidList->AddConvexSolid(pConvexSolid);           // Add the convex solid into a complicate solid

            pConvexSolid->DeleteRepeatFaces(bGenVoid);                  // Delete the repeated faces of solid
            m_ConvexSolidList.push_back(pConvexSolid);          // Add the convex solid in the solid list
            m_iNumSolid++;
            m_SolidList.push_back(pSolidList);            
        }

    }
    cout<<endl;
    return;
}



/** ********************************************************************
* @brief Traverse the boundary faces of solid and add into geometery surface list.
*
* @param const vector<McCadExtFace*> & theExtFaceList
* @return void
*
* @date 31/8/2012
* @author  Lei Lu
*********************************************************************/
void McCadGeomData::AddGeomSurfList(const vector<McCadExtFace*> & theExtFaceList)
{
    /* travelse the extend faces list */
    for (unsigned int i = 0; i < theExtFaceList.size(); i++)
    {
        McCadExtFace *pExtFace = theExtFaceList[i];

        TopLoc_Location loc;
        Handle(Geom_Surface) geom_surface = BRep_Tool::Surface(*pExtFace, loc);
        GeomAdaptor_Surface surf_adoptor(geom_surface);

        /* Generate the geometry surface interface based on the type of sufaces */
        IGeomFace * pGeomFace = NULL;
        switch (surf_adoptor.GetType())
        {
            case GeomAbs_Plane:
            {
                pGeomFace = new McCadGeomPlane(surf_adoptor);
                break;
            }
            case GeomAbs_Cylinder:
            {
                pGeomFace = new McCadGeomCylinder(surf_adoptor);
                break;
            }
            case GeomAbs_Cone:
            {
                pGeomFace = new McCadGeomCone(surf_adoptor);
                if(((McCadGeomCone *)pGeomFace)->HaveTransfCard() )
                {
                    ((McCadGeomCone *)pGeomFace)->AddTransfCard(this);// lei lu 131209
                }
                break;
            }
            case GeomAbs_Sphere:
            {
                pGeomFace = new McCadGeomSphere(surf_adoptor);
                break;
            }
            case GeomAbs_Torus:
            {
                pGeomFace = new McCadGeomTorus(surf_adoptor);
                break;
            }
            case GeomAbs_SurfaceOfRevolution:
            {
                pGeomFace = new McCadGeomRevolution(surf_adoptor);
                break;
            }
            case GeomAbs_BezierSurface:
            {
                cout << "Surface is not analytic (BezierSurface) " << endl;
                break;
            }
            case GeomAbs_BSplineSurface:
            {
                cout << "Surface is not analytic (BSplineSurface) " << endl;
                break;
            }
            case GeomAbs_SurfaceOfExtrusion:
            {
                cout << "Surface is not analytic (SurfaceOfRevolution) " << endl;
                break;
            }
            case GeomAbs_OffsetSurface:
            {
                cout << "Surface is not analytic (OffsetSurface) " << endl;
                break;
            }
            case GeomAbs_OtherSurface:
            {
                cout << "Surface is not analytic " << endl;
                break;
            }
            default:break;
        }

        if (!pGeomFace) // If geometry face didn't generated, the face should be spline surface.
        {
            return;
        }

        Standard_Boolean bExist = Standard_False; // Assume that the geometry surface didn't existed in the face list

        /* Travelse the geometry face list, add the new surface generated into the list.
           if the face with same geometry is existed already,no need to add more */
        vector<IGeomFace *>::iterator iterPos;
        for (iterPos = m_GeomSurfList.begin(); iterPos != m_GeomSurfList.end(); ++iterPos)
        {
            IGeomFace * pIterFace = *iterPos;
            if(pGeomFace->IsEqual( pIterFace ))
            {
                bExist = Standard_True;         // The geometry suface has already existed in list.
                if (pGeomFace->IsReversed())    // If the face orientation is different, reverse the new added surface.
                {
                    pExtFace->Reverse();
                }

                pExtFace->SetFaceNum(pIterFace->GetSurfNum()); // Set the surface number to be same.
                delete pGeomFace;               // Delete the point of geometry face and keep the extend surface.
                pGeomFace = NULL;
                break;
            }
        }

        /* If there are no repeated surface, add the surface into the list.*/
        if (Standard_False == bExist)
        {
            // use the serial number in geometry surface list as Face-Surface relationship number.
            int iNum = m_GeomSurfList.size();

            // Set the code number of McCadExtFace and GeomSurface, it will help to match them.
            // If the geometry surface orientation is reversed, make it to be forword.
            if (pGeomFace->IsReversed())
            {
                //cout<<"fanzhuan"<<pGeomFace->GetExpression()<<endl;
                pExtFace->Reverse();
            }
            pExtFace->SetFaceNum(iNum + 1);         //  Set the face number
            pGeomFace->SetSurfNum(iNum + 1);        //  Set the surface number, it is same to face number

            m_GeomSurfList.push_back(pGeomFace);    // Add the geometry surface into geometry face list.
        }
    }
}



/** ********************************************************************
* @brief Travelse the boundary surfaces of solid, calculate whether it
*        need add auxiliary faces,if need add them into geometery
*        surface list.
*
* @param const vector<McCadExtFace*> & theExtFaceList
* @return void
*
* @date 31/8/2012
* @author  Lei Lu
*********************************************************************/
void McCadGeomData::AddGeomAuxSurfList(const vector<McCadExtFace*> & theExtFaceList)
{
    for (unsigned int i = 0; i < theExtFaceList.size(); i++)
    {
        McCadExtFace * pExtFace = theExtFaceList[i];
        assert(pExtFace);
        vector<McCadExtFace*> AuxFaceList = pExtFace->GetAuxFaces(); // Calculate the face's auxiliary faces

        if(AuxFaceList.size() == 0) // if there are no auxiliary surface
        {
            continue;
        }
        else                        // Add the auxiliary faces into geometry face list
        {
            AddGeomSurfList(AuxFaceList);
        }
    }
}



/** ********************************************************************
* @brief Set the manager pointer of data object
*
* @param McCadVoidCellManager * pManager
* @return void
*
* @date 11/12/2013
* @author  Lei Lu
*********************************************************************/
void McCadGeomData::SetManager(const McCadVoidCellManager * pManager)
{
     m_pManager = pManager;
}



/** ********************************************************************
* @brief Sort the surfaces, the weight of surfaces is calculated by
*        function-compare
*
* @param
* @return void
*
* @date 31/8/2012
* @author  Lei Lu
***********************************************************************/
void McCadGeomData::SortSurface()
{
    sort(m_GeomSurfList.begin(),m_GeomSurfList.end(),compare); // Sort the geometry surface list.
    cout<<endl;
    cout<< "There are " <<m_GeomSurfList.size()<<" faces in face list"<<endl;
}


/** ********************************************************************
* @brief Update the face number, and generate a map to record the new
*        face number and old face number.
*
* @param const vector<McCadExtFace*> & theExtFaceList
* @return void
*
* @date 31/8/2012
* @author  Lei Lu
***********************************************************************/
void McCadGeomData::UpdateFaceNum()
{
    Standard_Integer iSurfNumNew;
    Standard_Integer iSurfNumOld;

    for(unsigned int i = 0; i < m_GeomSurfList.size(); i++)
    {
        IGeomFace * pFace = m_GeomSurfList.at(i);
        iSurfNumNew = i+1;
        iSurfNumOld = pFace->GetSurfNum();
        GenMapSurfNum(iSurfNumOld,iSurfNumNew);
    }

    try
    {
        /** Update the face number of solids, voids and outer spaces. */
        for (unsigned int i = 0; i < m_SolidList.size(); i++)
        {
            McCadSolid * pSolid = m_SolidList.at(i);
            assert(pSolid);

            for(int j = 0; j < pSolid->GetConvexSolidList().size(); j++)
            {
                McCadConvexSolid *pConvexSolid = pSolid->GetConvexSolidList().at(j);
                assert(pConvexSolid);
                pConvexSolid->ChangeFaceNum(this);
            }
        }

        for (unsigned int i = 0; i < m_VoidCellList.size(); i++)
        {
            McCadVoidCell * pVoid = m_VoidCellList.at(i);
            assert(pVoid);

            pVoid->ChangeFaceNum(this);    // Update the surface number after sorting the surface list.
        }

        if (m_pManager->GenVoid())
        {
            assert(m_pOutVoid);
            m_pOutVoid->ChangeFaceNum(this); // Update the face number.
        }
    }
    catch(...)
    {
        cout << "#McCadGeomData :: Update surfaces number FAILED\n";
    }
}


vector <McCadConvexSolid *> McCadGeomData::GetConvexSolid()
{
    return m_ConvexSolidList;
}


vector <McCadTransfCard *> McCadGeomData::GetTransfCard()
{
    return m_TransfCardList;
}


int McCadGeomData::AddTransfCard(gp_Ax3 theAxis, gp_Pnt theApex)
{
    int iTrNum;
    McCadTransfCard *pTrCard = new McCadTransfCard(theAxis,theApex);
    iTrNum = m_TransfCardList.size() + 1;
    pTrCard->SetTrNum(iTrNum);
    m_TransfCardList.push_back(pTrCard);

    return iTrNum;
}


Standard_Boolean McCadGeomData::GenMapSurfNum(Standard_Integer iSurfNumOld,Standard_Integer iSurfNumNew)
{
    pair<Standard_Integer,Standard_Integer>(iSurfNumOld,iSurfNumNew);
    pair<map<Standard_Integer,Standard_Integer>::iterator,bool> result;
    result = m_mapSurfNum.insert(pair<Standard_Integer,Standard_Integer>(iSurfNumOld,iSurfNumNew));

    if(result.second)
    {
        return Standard_True;
    }
    else
    {
        return Standard_False;
    }
}


Standard_Integer McCadGeomData::GetNewFaceNum(Standard_Integer iOldNum)
{
    map<Standard_Integer,Standard_Integer>::iterator iter;
    iter = m_mapSurfNum.find(iOldNum);
    if (iter != m_mapSurfNum.end())
    {
        return iter->second;
    }
}


/** ********************************************************************
* @brief Calculate the weight of each surface according to the surface
*        type and parameters.
*
* @param TCollection_AsciiString theFileName
* @return void
*
* @date 31/8/2012
* @author  Lei Lu
***********************************************************************/
Standard_Boolean compare(const IGeomFace * surfA, const IGeomFace * surfB)
{
    return surfA->Compare(surfB);
}

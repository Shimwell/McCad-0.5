#ifndef MCCADSPLITCONEPLN_HXX
#define MCCADSPLITCONEPLN_HXX

#include <vector>

#include "McCadAstSurfPlane.hxx"
#include "McCadBndSurfCone.hxx"
#include "McCadDcompSolid.hxx"

using namespace std;

class McCadSplitConePln
{
public:

    void* operator new(size_t,void* anAddress)
    {
        return anAddress;
    }
    void* operator new(size_t size)
    {
        return Standard::Allocate(size);
    }
    void  operator delete(void *anAddress)
    {
        if (anAddress) Standard::Free((Standard_Address&)anAddress);
    }

    McCadSplitConePln();
    ~McCadSplitConePln();

public:

    /**< Generate assiste splitting surfaces and add into the assisted surface list */
    void GenSplitSurfaces( McCadDcompSolid *& pSolid );

private:

    /**< Create splitting surfaces through the given straight edge */
    McCadAstSurfPlane* CrtSplitSurfThroughEdge(McCadBndSurfCone *& pConeFace,McCadEdge *& pEdge);
    /**< Create splitting surfaces through the given two straight edges */
    McCadAstSurfPlane* CrtSplitSurfThroughTwoEdges(McCadEdge *& pEdgeA, McCadEdge *& pEdgeB);

    /**< Create the splitting surfaces based on a give cone surface */
    void CrtSplitSurfaces(McCadBndSurfCone *& pConeFace, vector<McCadAstSurface *> &astFace_list);

    /**< Search the common straight edge of given cone and plane  */
    Standard_Boolean FindComLineEdge(McCadBndSurfCone *& pSurfCone,
                                     McCadBndSurface *& pSurfPln);

    Standard_Real CalCurveRadian(McCadBndSurface *& pBndCone);      /**< Calculate the radian of curved surface */
   // void MergeSurfaces(vector<McCadAstSurface*> & theAstFaceList);  /**< Merge the repeated surfaces */

private:
    Standard_Real m_fLength;            /**< The length of input solid which deside the size of created splitting surface */


};

#endif // MCCADSPLITCONEPLN_HXX


#ifndef MCCADBNDSURFCONE_HXX
#define MCCADBNDSURFCONE_HXX
#include "McCadBndSurface.hxx"

#include <gp_Ax3.hxx>

class McCadBndSurfCone : public McCadBndSurface
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

    McCadBndSurfCone();
    McCadBndSurfCone(const TopoDS_Face & theFace);
    ~McCadBndSurfCone();

public:

    /**< Detect the collision between cone and triangles */
    virtual Standard_Boolean TriangleCollision(McCadTriangle *& triangle, POSITION & eSide);
    /**< Generate the extended cone */
    void GenExtCone(Standard_Real length);

    /**< If the two surfaces can be fused or not */
    virtual Standard_Boolean CanFuseSurf(McCadBndSurface *& pSurf);
    /**< Fuse the surfaces which are connected and have same geometries*/
    virtual TopoDS_Face FuseSurfaces(McCadBndSurface *& pSurf);
    /**< The point is on the surface if the distance between them less than tolerence */
    virtual Standard_Boolean IsPntOnSurf(gp_Pnt &thePnt, Standard_Real disTol);

    /**< Add the edge connects cone and plane for adding assited splitting surface */
    void AddConePlnSplitEdge(McCadEdge *& pEdge);
    vector<McCadEdge*> GetConePlnSplitEdgeList() const;     /**< Get the splitting edge list */
    Standard_Real GetRadian() const;                        /**< Get the radian of cone */
    gp_Pnt GetPeak() const;                                 /**< Get the peak of cone */

private:

    gp_Dir m_Dir;                   /**< Direction of axis  */
    gp_Ax3 m_Axis;                  /**< Coordinate of cone */
    gp_Pnt m_Apex;                  /**< Top point of cone  */
    Standard_Real m_SemiAngle;      /**< SemiAngle of cone  */

    Standard_Real m_ConeLength;     /**< The length of new created cone */

    Standard_Boolean m_bHasAstSplitSurfaces;/**< If the cylinder has assisted splitting surface */
    Bnd_Box m_ConeBndBox;                   /**< The boundary box of whole cylinder */
    TopoDS_Face m_coneSurf;                 /**< The created new cone */

    /**< The list of edge that connect cylinder and plane and can be added splitting surface */
    vector<McCadEdge*> m_ConePlnSplitEdgeList;
    Standard_Real m_Radian;                     /**< The radian of cone */

};





#endif // MCCADBNDSURFCONE_HXX

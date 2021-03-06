// File generated by CPPExt (Value)
//
//                     Copyright (C) 1991 - 2000 by  
//                      Matra Datavision SA.  All rights reserved.
//  
//                     Copyright (C) 2001 - 2004 by
//                     Open CASCADE SA.  All rights reserved.
// 
// This file is part of the Open CASCADE Technology software.
//
// This software may be distributed and/or modified under the terms and
// conditions of the Open CASCADE Public License as defined by Open CASCADE SA
// and appearing in the file LICENSE included in the packaging of this file.
//  
// This software is distributed on an "AS IS" basis, without warranty of any
// kind, and Open CASCADE SA hereby disclaims all such warranties,
// including without limitation, any warranties of merchantability, fitness
// for a particular purpose or non-infringement. Please see the License for
// the specific terms and conditions governing rights and limitations under the
// License.

#ifndef _McCadDiscDs_DiscFace_HeaderFile
#define _McCadDiscDs_DiscFace_HeaderFile

#ifndef _TopoDS_Face_HeaderFile
#include <TopoDS_Face.hxx>
#endif
#ifndef _Handle_TColgp_HSequenceOfPnt_HeaderFile
#include <Handle_TColgp_HSequenceOfPnt.hxx>
#endif
#ifndef _Bnd_Box_HeaderFile
#include <Bnd_Box.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _GeomAbs_SurfaceType_HeaderFile
#include <GeomAbs_SurfaceType.hxx>
#endif
class TColgp_HSequenceOfPnt;
class TopoDS_Face;
class Bnd_Box;


#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif


//! \brief A discretized face, i.e. a face with discrete sample points.


class McCadDiscDs_DiscFace  {

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
 // Methods PUBLIC
 // 

//! discrete face class <br>
//!  Face with points on it <br>
//! <br>
Standard_EXPORT McCadDiscDs_DiscFace();


//! <br>
Standard_EXPORT McCadDiscDs_DiscFace(const TopoDS_Face& theFace);


Standard_EXPORT   void SetFace(const TopoDS_Face& theFace) ;


Standard_EXPORT   TopoDS_Face GetFace() const;


Standard_EXPORT   Standard_Boolean IsDiscret() const;


Standard_EXPORT   void SetPoints(const Handle(TColgp_HSequenceOfPnt)& thePntSeq) ;


Standard_EXPORT   Handle_TColgp_HSequenceOfPnt GetPoints() const;


Standard_EXPORT   void SetBBox(const Bnd_Box& theBBox) ;


Standard_EXPORT   Bnd_Box GetBBox() const;


Standard_EXPORT   Standard_Integer NbOfPoints() const;


Standard_EXPORT   Standard_Real FaceArea() const;


Standard_EXPORT   GeomAbs_SurfaceType FaceSurfaceType() const;





protected:

 // Methods PROTECTED
 // 


 // Fields PROTECTED
 //


private: 

 // Methods PRIVATE
 // 


 // Fields PRIVATE
 //
TopoDS_Face myFace;
Handle_TColgp_HSequenceOfPnt myVoxelSeq;
Bnd_Box myBBox;


};





// other Inline functions and methods (like "C++: function call" methods)
//


#endif

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

#ifndef _McCadCSGAdapt_ShapeAnalyser_HeaderFile
#define _McCadCSGAdapt_ShapeAnalyser_HeaderFile

#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif
class TopoDS_Shape;


#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif


class McCadCSGAdapt_ShapeAnalyser  {

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

//! analysis and repair of shapes <br>
Standard_EXPORT McCadCSGAdapt_ShapeAnalyser();


Standard_EXPORT McCadCSGAdapt_ShapeAnalyser(const TopoDS_Shape& theShape);


Standard_EXPORT   void Init(const TopoDS_Shape& theShape) ;


Standard_EXPORT   void SetTolerance(const Standard_Real theTol) ;


Standard_EXPORT   Standard_Real GetTolerance() const;


Standard_EXPORT   void PrintContent(Standard_OStream& theStream) const;


Standard_EXPORT   void PrintInfo(Standard_OStream& theStream) const;


Standard_EXPORT   void ScaleShape(const Standard_Real theFactor) ;


Standard_EXPORT   TopoDS_Shape Shape() const;





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
TopoDS_Shape myShape;


};





// other Inline functions and methods (like "C++: function call" methods)
//


#endif

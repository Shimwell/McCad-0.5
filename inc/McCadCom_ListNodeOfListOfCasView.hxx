// File generated by CPPExt (Transient)
//
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

#ifndef _McCadCom_ListNodeOfListOfCasView_HeaderFile
#define _McCadCom_ListNodeOfListOfCasView_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Handle_McCadCom_ListNodeOfListOfCasView_HeaderFile
#include <Handle_McCadCom_ListNodeOfListOfCasView.hxx>
#endif

#ifndef _Handle_McCadCom_CasView_HeaderFile
#include <Handle_McCadCom_CasView.hxx>
#endif
#ifndef _TCollection_MapNode_HeaderFile
#include <TCollection_MapNode.hxx>
#endif
#ifndef _TCollection_MapNodePtr_HeaderFile
#include <TCollection_MapNodePtr.hxx>
#endif
class McCadCom_CasView;
class McCadCom_ListOfCasView;
class McCadCom_ListIteratorOfListOfCasView;



class McCadCom_ListNodeOfListOfCasView : public TCollection_MapNode {

public:
 // Methods PUBLIC
 // 

McCadCom_ListNodeOfListOfCasView(const Handle(McCadCom_CasView)& I,const TCollection_MapNodePtr& n);

  Handle_McCadCom_CasView& Value() const;
//Standard_EXPORT ~McCadCom_ListNodeOfListOfCasView();




 // Type management
 //
 Standard_EXPORT const Handle(Standard_Type)& DynamicType() const;
 //Standard_EXPORT Standard_Boolean	       IsKind(const Handle(Standard_Type)&) const;

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
Handle_McCadCom_CasView myValue;


};

#define Item Handle_McCadCom_CasView
#define Item_hxx <McCadCom_CasView.hxx>
#define TCollection_ListNode McCadCom_ListNodeOfListOfCasView
#define TCollection_ListNode_hxx <McCadCom_ListNodeOfListOfCasView.hxx>
#define TCollection_ListIterator McCadCom_ListIteratorOfListOfCasView
#define TCollection_ListIterator_hxx <McCadCom_ListIteratorOfListOfCasView.hxx>
#define Handle_TCollection_ListNode Handle_McCadCom_ListNodeOfListOfCasView
#define TCollection_ListNode_Type_() McCadCom_ListNodeOfListOfCasView_Type_()
#define TCollection_List McCadCom_ListOfCasView
#define TCollection_List_hxx <McCadCom_ListOfCasView.hxx>

#include <TCollection_ListNode.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_ListNode
#undef TCollection_ListNode_hxx
#undef TCollection_ListIterator
#undef TCollection_ListIterator_hxx
#undef Handle_TCollection_ListNode
#undef TCollection_ListNode_Type_
#undef TCollection_List
#undef TCollection_List_hxx


// other Inline functions and methods (like "C++: function call" methods)
//


#endif
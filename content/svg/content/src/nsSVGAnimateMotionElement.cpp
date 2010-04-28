/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is the Mozilla SVG project.
 *
 * The Initial Developer of the Original Code is Brian Birtles.
 * Portions created by the Initial Developer are Copyright (C) 2005
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Brian Birtles <birtles@gmail.com>
 *   Chris Double  <chris.double@double.co.nz>
 *   Daniel Holbert <dholbert@mozilla.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "nsSVGAnimationElement.h"
#include "nsIDOMSVGAnimateMotionElement.h"
#include "nsSVGEnum.h"
#include "nsSMILAnimationFunction.h"

#include "nsCOMArray.h"
#include "nsIDOMSVGPathSeg.h"
#include "nsSVGPathSeg.h"
#include "nsSVGPathDataParser.h"


typedef nsSVGAnimationElement nsSVGAnimateMotionElementBase;

class nsSVGAnimateMotionElement : public nsSVGAnimateMotionElementBase,
                                  public nsIDOMSVGAnimateMotionElement
{
protected:
  friend nsresult NS_NewSVGAnimateMotionElement(nsIContent **aResult,
                                                   nsINodeInfo *aNodeInfo);
  nsSVGAnimateMotionElement(nsINodeInfo* aNodeInfo);

  nsSMILAnimationFunction mAnimationFunction;

public:
  // interfaces:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_NSIDOMSVGANIMATEMOTIONELEMENT

  NS_FORWARD_NSIDOMNODE(nsSVGAnimateMotionElementBase::)
  NS_FORWARD_NSIDOMELEMENT(nsSVGAnimateMotionElementBase::)
  NS_FORWARD_NSIDOMSVGELEMENT(nsSVGAnimateMotionElementBase::)
  NS_FORWARD_NSIDOMSVGANIMATIONELEMENT(nsSVGAnimateMotionElementBase::)

  // nsIDOMNode specializations
  virtual nsresult Clone(nsINodeInfo *aNodeInfo, nsINode **aResult) const;

  // nsISMILAnimationElement
  virtual nsSMILAnimationFunction& AnimationFunction();
};

NS_IMPL_NS_NEW_SVG_ELEMENT(AnimateMotion)

//----------------------------------------------------------------------
// nsISupports methods

NS_IMPL_ADDREF_INHERITED(nsSVGAnimateMotionElement,nsSVGAnimateMotionElementBase)
NS_IMPL_RELEASE_INHERITED(nsSVGAnimateMotionElement,nsSVGAnimateMotionElementBase)

NS_INTERFACE_TABLE_HEAD(nsSVGAnimateMotionElement)
  NS_NODE_INTERFACE_TABLE5(nsSVGAnimateMotionElement, nsIDOMNode,
                           nsIDOMElement, nsIDOMSVGElement,
                           nsIDOMSVGAnimationElement,
                           nsIDOMSVGAnimateMotionElement)
  NS_INTERFACE_MAP_ENTRY_CONTENT_CLASSINFO(SVGAnimateElement)
NS_INTERFACE_MAP_END_INHERITING(nsSVGAnimateMotionElementBase)

//----------------------------------------------------------------------
// Implementation

nsSVGAnimateMotionElement::nsSVGAnimateMotionElement(nsINodeInfo *aNodeInfo)
  : nsSVGAnimateMotionElementBase(aNodeInfo)
{
}

//----------------------------------------------------------------------
// nsIDOMNode methods

NS_IMPL_ELEMENT_CLONE_WITH_INIT(nsSVGAnimateMotionElement)

//----------------------------------------------------------------------
// nsISMILAnimationElement methods

nsSMILAnimationFunction&
nsSVGAnimateMotionElement::AnimationFunction()
{
  return mAnimationFunction;
}

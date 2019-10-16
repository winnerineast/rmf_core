/*
 * Copyright (C) 2019 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef SRC__RMF_TRAFFIC__STATICMOTION_HPP
#define SRC__RMF_TRAFFIC__STATICMOTION_HPP

#include "DetectConflictInternal.hpp"

#include <fcl/ccd/motion.h>

namespace rmf_traffic {
namespace internal {

//==============================================================================
// NOTE(MXG): This class was created because we often want to test collisions
// between a moving object and a non-moving object. FCL does not have a built-in
// Motion class for completely static motions, so it makes sense to have a
// MotionBase implementation that's specialized for non-moving objects. This can
// have much more efficient implementations for the interface functions than the
// built-in Motion classes have.
//
// However, we've observed non-deterministic results from at least one collision
// detection test, and the non-determinism seems to be originating inside of
// FCL. For right now, this StaticMotion class will simply wrap one of FCL's
// built-in Motion classes, until the source of the bug can be identified.
//
// TODO(MXG): Revert this back to being a totally custom Motion class when the
// bug is sussed out.

class StaticMotion : public fcl::TranslationMotion
//class StaticMotion : public fcl::MotionBase
{
public:

//  StaticMotion() = default;

  StaticMotion(const Eigen::Isometry2d& tf);

//  bool integrate(double dt) const final;

//  fcl::FCL_REAL computeMotionBound(
//      const fcl::BVMotionBoundVisitor&) const final;

//  fcl::FCL_REAL computeMotionBound(
//      const fcl::TriangleMotionBoundVisitor&) const final;

//  void getCurrentTransform(fcl::Transform3f& tf) const final;

//  void getTaylorModel(fcl::TMatrix3&, fcl::TVector3&) const final;

//private:

//  fcl::Transform3f _tf;

};

} // namespace internal
} // namespace rmf_traffic

#endif // SRC__RMF_TRAFFIC__STATICMOTION_HPP

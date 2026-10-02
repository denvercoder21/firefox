/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_ScrollSnapTargetId_h_
#define mozilla_ScrollSnapTargetId_h_

#include <cstdint>

#include "Units.h"
#include "mozilla/WritingModes.h"
#include "nsPoint.h"
#include "nsTArray.h"

namespace mozilla {

// The id for each scroll snap target element to track the last snapped element.
// 0 means it wasn't snapped on the last scroll operation.
enum class ScrollSnapTargetId : uintptr_t {
  None = 0,
};

struct ScrollSnapTargetIds {
  CopyableTArray<ScrollSnapTargetId> mIdsOnX;
  CopyableTArray<ScrollSnapTargetId> mIdsOnY;
  bool operator==(const ScrollSnapTargetIds&) const = default;
  bool Contains(ScrollSnapTargetId aId) const {
    return mIdsOnX.Contains(aId) || mIdsOnY.Contains(aId);
  }
  const CopyableTArray<ScrollSnapTargetId>& IdsOnInline(WritingMode aWM) const {
    return aWM.IsVertical() ? mIdsOnY : mIdsOnX;
  }
  const CopyableTArray<ScrollSnapTargetId>& IdsOnBlock(WritingMode aWM) const {
    return aWM.IsVertical() ? mIdsOnX : mIdsOnY;
  }
};

struct SnapDestination {
  nsPoint mPosition;
  ScrollSnapTargetIds mTargetIds;
  // The single target selected on each axis, as opposed to mTargetIds which
  // holds every target aligned at mPosition.
  ScrollSnapTargetId mSelectedIdOnX = ScrollSnapTargetId::None;
  ScrollSnapTargetId mSelectedIdOnY = ScrollSnapTargetId::None;

  ScrollSnapTargetId SelectedIdOnInline(WritingMode aWM) const {
    return aWM.IsVertical() ? mSelectedIdOnY : mSelectedIdOnX;
  }
  ScrollSnapTargetId SelectedIdOnBlock(WritingMode aWM) const {
    return aWM.IsVertical() ? mSelectedIdOnX : mSelectedIdOnY;
  }
};

struct CSSSnapDestination {
  CSSPoint mPosition;
  ScrollSnapTargetIds mTargetIds;
};

}  // namespace mozilla

#endif  // mozilla_ScrollSnapTargetId_h_

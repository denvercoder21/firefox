/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_ScrollState_h
#define mozilla_ScrollState_h

#include <cstdint>

#include "mozilla/RefPtr.h"
#include "nsPoint.h"

class nsIContent;

namespace mozilla {

/**
 * The state of a ScrollContainerFrame that outlives the frame itself, either
 * across a frame reconstruction (stored on the element), or across navigations
 * (stored in session history as a PresState).
 */
struct ScrollState {
  // For frames where layout and visual viewport aren't one and the same thing,
  // this is the position of the *visual* viewport.
  nsPoint mScrollPosition;
  // Only meaningful for root scroll frames.
  float mResolution = 1.0f;
  // Scroll event generations are per-PresShell, so they're only restored
  // within the same document, and never end up in session history. The same
  // goes for the snap targets last reported by scrollsnapchange.
  uint32_t mScrollEventGeneration = 0;
  uint32_t mScrollEndEventGeneration = 0;
  uint32_t mScrollSnapChangeEventGeneration = 0;
  RefPtr<nsIContent> mScrollSnapChangeTargetBlock;
  RefPtr<nsIContent> mScrollSnapChangeTargetInline;
  bool mAllowScrollOriginDowngrade = true;
  bool mHasScrollPosition = true;
};

}  // namespace mozilla

#endif

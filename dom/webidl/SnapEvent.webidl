/* -*- Mode: IDL; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The origin of this IDL file is
 * https://www.w3.org/TR/css-scroll-snap-2/
 */

/*
 * The default values for snapTargetBlock and
 * snapTargetInline are not spec-compliant.
 * See discussion: https://github.com/w3c/csswg-drafts/issues/13487
 */
dictionary SnapEventInit : EventInit {
  Node? snapTargetBlock = null;
  Node? snapTargetInline = null;
};

[Pref="layout.css.scroll-snap.snap-event.enabled", Exposed=Window]
interface SnapEvent : Event {
  constructor(DOMString type, optional SnapEventInit eventInitDict = {});
  readonly attribute Node? snapTargetBlock;
  readonly attribute Node? snapTargetInline;
};

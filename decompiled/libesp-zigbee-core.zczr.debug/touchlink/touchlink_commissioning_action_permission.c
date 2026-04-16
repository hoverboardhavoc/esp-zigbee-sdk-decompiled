/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_action_permission
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool touchlink_commissioning_action_permission(touchlink_action_t action,ezb_extaddr_t *ieee_addr)

{
  _Bool _Var1;
  touchlink_commissioning_t *ptVar2;
  
  ptVar2 = touchlink_commissioning_get();
  if (ptVar2->action_permission_cb == (touchlink_action_permission_callback_t)0x0) {
    _Var1 = true;
  }
  else {
    ptVar2 = touchlink_commissioning_get();
    _Var1 = (*ptVar2->action_permission_cb)((ezb_touchlink_action_t)action,ieee_addr);
  }
  return _Var1;
}


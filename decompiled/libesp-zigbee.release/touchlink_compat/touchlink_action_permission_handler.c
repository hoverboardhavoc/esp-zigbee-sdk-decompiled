/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> touchlink_compat.o -> touchlink_action_permission_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool touchlink_action_permission_handler(ezb_touchlink_action_t action,ezb_extaddr_t *ieee_addr)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_00002029,action);
  if ((s_touchlink_action_allowed_cb != (esp_zb_touchlink_action_allowed_callback_t)0x0) &&
     (((iVar2 == 2 || (iVar2 == 3)) || (iVar2 == 1)))) {
                    /* WARNING: Could not recover jumptable at 0x0001002e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    _Var1 = (*s_touchlink_action_allowed_cb)(action);
    return _Var1;
  }
  return true;
}


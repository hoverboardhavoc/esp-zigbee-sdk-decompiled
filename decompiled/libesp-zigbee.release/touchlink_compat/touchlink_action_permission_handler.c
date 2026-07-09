/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> touchlink_compat.o -> touchlink_action_permission_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_action_permission_handler(int param_1)

{
  undefined4 uVar1;
  
  if ((s_touchlink_action_allowed_cb != (code *)0x0) &&
     (((param_1 == 2 || (param_1 == 3)) || (param_1 == 1)))) {
                    /* WARNING: Could not recover jumptable at 0x0001002e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*s_touchlink_action_allowed_cb)();
    return uVar1;
  }
  return 1;
}


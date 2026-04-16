/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_action_permission
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool touchlink_commissioning_action_permission(touchlink_action_t action,ezb_extaddr_t *ieee_addr)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  if (*(int *)(iVar2 + 0x1450) != 0) {
    iVar2 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x000100b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(iVar2 + 0x1450))(action & 0xff,ieee_addr,*(code **)(iVar2 + 0x1450));
    return (_Bool)uVar1;
  }
  return true;
}


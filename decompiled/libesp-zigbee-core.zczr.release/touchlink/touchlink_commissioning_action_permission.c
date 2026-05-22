/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  if (*(int *)(iVar2 + 0x13fc) != 0) {
    iVar2 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x000100b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(iVar2 + 0x13fc))(action & 0xff,ieee_addr,*(code **)(iVar2 + 0x13fc));
    return (_Bool)uVar1;
  }
  return true;
}


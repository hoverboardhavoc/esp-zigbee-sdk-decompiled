/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_commissioning_scan(void)

{
  ezb_err_t eVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  int iVar3;
  uint32_t uVar4;
  
  _Var2 = touchlink_commissioning_task_is_idle();
  eVar1 = 2;
  if (CONCAT31(extraout_var,_Var2) != 0) {
    touchlink_commissioning_set_task('\x01');
    iVar3 = core_globals_get();
    uVar4 = touchlink_commissioning_get_channel_mask();
    *(uint32_t *)(iVar3 + 0x13bc) = uVar4;
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar3 + 0x13b8) = 5;
    eVar1 = touchlink_commissioning_scan_next_channel();
    if (eVar1 == 0) {
      return 0;
    }
  }
  touchlink_commissioning_set_task('\0');
  return eVar1;
}


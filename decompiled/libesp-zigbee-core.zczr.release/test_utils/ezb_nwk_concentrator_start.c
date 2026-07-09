/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> test_utils.o -> ezb_nwk_concentrator_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_nwk_concentrator_start(undefined1 param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 <= param_3) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x9f9) = param_1;
    iVar1 = core_globals_get();
    *(char *)(iVar1 + 0x9fb) = (char)param_2;
    iVar1 = core_globals_get();
    *(char *)(iVar1 + 0x9fa) = (char)param_3;
    uVar2 = nwk_concentrator_start();
    return uVar2;
  }
  return 2;
}


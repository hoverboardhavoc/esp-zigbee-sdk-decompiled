/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_get_max_asdu
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 aps_get_max_asdu(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar2 + 4);
  if (param_1 == 0) {
    if (param_2 == 0) {
      uVar1 = 0x52;
    }
    else if (param_3 == 0) {
      uVar1 = 0x49;
    }
    else {
      uVar1 = 0x41;
    }
  }
  return uVar1;
}


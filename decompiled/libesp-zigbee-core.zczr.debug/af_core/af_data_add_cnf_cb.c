/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_add_cnf_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_data_add_cnf_cb(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar1 = (undefined4 *)calloc(1,0x10);
    if (puVar1 == (undefined4 *)0x0) {
      uVar3 = 1;
    }
    else {
      puVar1[1] = param_2;
      puVar1[2] = param_3;
      *puVar1 = param_1;
      puVar1[3] = puVar1 + 3;
      iVar2 = core_globals_get();
      puVar1[3] = *(undefined4 *)(iVar2 + 0xca4);
      *(undefined4 **)(iVar2 + 0xca4) = puVar1 + 3;
      uVar3 = 0;
    }
  }
  return uVar3;
}


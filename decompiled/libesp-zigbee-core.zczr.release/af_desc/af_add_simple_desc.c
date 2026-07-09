/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_add_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_add_simple_desc(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 2;
  }
  uVar1 = 0;
  while( true ) {
    if (s_ep_num_on_dev <= uVar1) {
      return 5;
    }
    iVar2 = core_globals_get();
    if (*(int *)(*(int *)(iVar2 + 0xc9c) + uVar1 * 4) == 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = core_globals_get();
  *(int *)(*(int *)(iVar2 + 0xc9c) + uVar1 * 4) = param_1;
  return 0;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> ezb_get_use_extended_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_get_use_extended_panid(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = core_globals_get();
  uVar1 = *(undefined4 *)(iVar4 + 0xc);
  uVar2 = *(undefined3 *)(iVar4 + 0x10);
  uVar3 = *(undefined4 *)(iVar4 + 0x10);
  *param_1 = (char)*(undefined3 *)(iVar4 + 0xc);
  param_1[1] = (char)((uint)uVar1 >> 8);
  param_1[3] = (char)((uint)uVar1 >> 0x18);
  param_1[5] = (char)((uint)uVar3 >> 8);
  param_1[2] = (char)((uint)uVar1 >> 0x10);
  param_1[4] = (char)uVar2;
  param_1[6] = (char)((uint)uVar3 >> 0x10);
  param_1[7] = (char)((uint)uVar3 >> 0x18);
  return;
}


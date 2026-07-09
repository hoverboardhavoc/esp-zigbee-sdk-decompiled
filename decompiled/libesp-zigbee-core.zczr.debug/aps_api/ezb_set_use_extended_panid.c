/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> ezb_set_use_extended_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_set_use_extended_panid(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = core_globals_get();
  uVar1 = *param_1;
  uVar2 = *(undefined2 *)(param_1 + 1);
  uVar3 = param_1[1];
  *(char *)(iVar4 + 0xc) = (char)*(undefined2 *)param_1;
  *(char *)(iVar4 + 0xd) = (char)((uint)uVar1 >> 8);
  *(char *)(iVar4 + 0xe) = (char)((uint)uVar1 >> 0x10);
  *(char *)(iVar4 + 0xf) = (char)((uint)uVar1 >> 0x18);
  *(char *)(iVar4 + 0x10) = (char)uVar2;
  *(char *)(iVar4 + 0x11) = (char)((uint)uVar3 >> 8);
  *(char *)(iVar4 + 0x12) = (char)((uint)uVar3 >> 0x10);
  *(char *)(iVar4 + 0x13) = (char)((uint)uVar3 >> 0x18);
  return;
}


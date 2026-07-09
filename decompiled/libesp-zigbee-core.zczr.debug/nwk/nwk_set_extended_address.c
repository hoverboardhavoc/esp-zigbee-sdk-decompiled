/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_set_extended_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_set_extended_address(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = core_globals_get();
  uVar1 = *param_1;
  uVar2 = *(undefined2 *)(param_1 + 1);
  uVar3 = param_1[1];
  *(char *)(iVar4 + 0x9e6) = (char)*(undefined2 *)param_1;
  *(char *)(iVar4 + 0x9e7) = (char)((uint)uVar1 >> 8);
  *(char *)(iVar4 + 0x9e8) = (char)((uint)uVar1 >> 0x10);
  *(char *)(iVar4 + 0x9e9) = (char)((uint)uVar1 >> 0x18);
  *(char *)(iVar4 + 0x9ea) = (char)uVar2;
  *(char *)(iVar4 + 0x9eb) = (char)((uint)uVar3 >> 8);
  *(char *)(iVar4 + 0x9ec) = (char)((uint)uVar3 >> 0x10);
  *(char *)(iVar4 + 0x9ed) = (char)((uint)uVar3 >> 0x18);
  iVar4 = core_globals_get();
  nwk_mm_set_pib_attr(0xff,0x40,iVar4 + 0x9e6);
  return;
}


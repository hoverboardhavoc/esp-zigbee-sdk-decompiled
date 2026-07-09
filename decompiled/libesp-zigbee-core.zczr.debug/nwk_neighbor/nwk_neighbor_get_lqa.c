/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_get_lqa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_neighbor_get_lqa(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = (uint)*(byte *)(param_1 + 2);
  uVar2 = uVar1;
  if ((uVar1 != 0) && (uVar3 = (uint)*(byte *)(param_1 + 3), uVar3 != 0)) {
    uVar4 = (uint)*(byte *)(param_1 + 4);
    if (uVar4 == 0) {
      return uVar1 + uVar3 >> 1;
    }
    if ((uVar3 < uVar1 == uVar4 < uVar1) && (uVar2 = uVar4, uVar3 < uVar1 == uVar4 < uVar3)) {
      return uVar3;
    }
  }
  return uVar2;
}


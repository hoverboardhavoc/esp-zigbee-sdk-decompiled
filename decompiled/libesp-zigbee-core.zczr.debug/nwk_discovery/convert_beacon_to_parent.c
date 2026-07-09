/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> convert_beacon_to_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void convert_beacon_to_parent(short *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  *(undefined1 *)(param_1 + 5) = *(undefined1 *)(param_2 + 0xe);
  uVar1 = (*(byte *)(param_2 + 2) >> 2 & 1) << 0xe;
  uVar4 = *(uint *)(param_1 + 8);
  *(uint *)(param_1 + 8) = uVar4 & 0xffffbfff | uVar1;
  uVar2 = (uint)(*(byte *)(param_2 + 2) >> 7) << 0xf;
  *(uint *)(param_1 + 8) = uVar4 & 0xffff3fff | uVar1 | uVar2;
  uVar3 = (*(byte *)(param_2 + 1) & 3) << 0x10;
  uVar5 = uVar4 & 0xfffc3fff | uVar1 | uVar2 | uVar3;
  *(uint *)(param_1 + 8) = uVar5;
  if ((int)(uVar5 << 2) < 0) {
    *(uint *)(param_1 + 8) =
         uVar4 & 0xfff03fff | uVar1 | uVar2 | uVar3 | (uint)(*param_1 != 0) << 0x12;
  }
  else {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0xc0000;
  }
  *(uint *)(param_1 + 8) =
       (*(byte *)(param_2 + 2) >> 3 & 0xf) << 0x14 | *(uint *)(param_1 + 8) & 0xff0fffff;
  return;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> mempool_free_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_free_ent(uint param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  undefined4 unaff_retaddr;
  uint uVar1;
  undefined4 unaff_s0;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_10 [12];
  
  if (param_5 < param_1) {
    register0x00002008 = (BADSPACEBASE *)auStack_10;
    unaff_retaddr = 0x10180;
    param_2 = mempool_free_ent_part_0();
  }
  uVar2 = (int)(param_5 - param_1) / param_3 & 0xffff;
  *(undefined4 *)((int)register0x00002008 + -4) = unaff_retaddr;
  *(undefined4 *)((int)register0x00002008 + -8) = unaff_s0;
  if (uVar2 < param_4) goto _L0;
  do {
    param_2 = mempool_free_ent_part_0();
_L0:
    uVar1 = 1 << (uVar2 & 7) & 0xff;
    uVar3 = uVar2 >> 3;
    uVar2 = 5;
    uVar3 = __atomic_fetch_and_1(param_2 + uVar3,~uVar1 & 0xff);
  } while ((uVar1 & uVar3) == 0);
  return;
}


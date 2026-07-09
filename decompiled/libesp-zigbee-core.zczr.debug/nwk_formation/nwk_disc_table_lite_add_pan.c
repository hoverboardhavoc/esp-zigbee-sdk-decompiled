/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_disc_table_lite_add_pan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_disc_table_lite_add_pan(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  short *psVar3;
  byte bVar4;
  
  iVar2 = core_globals_get();
  uVar1 = *(undefined1 *)(iVar2 + 0xba4);
  iVar2 = core_globals_get();
  bVar4 = *(char *)(iVar2 + 0xba4) + 1U & 1;
  iVar2 = nwk_disc_table_lite_get_slot(uVar1);
  psVar3 = (short *)nwk_disc_table_lite_get_slot(bVar4);
  if (*psVar3 != *(short *)(param_1 + 0xc)) {
    if (*(byte *)(psVar3 + 1) < *(byte *)(iVar2 + 2)) {
      iVar2 = core_globals_get();
      *(byte *)(iVar2 + 0xba4) = bVar4;
      psVar3 = (short *)nwk_disc_table_lite_get_slot(bVar4 ^ 1);
    }
    *(undefined1 *)(psVar3 + 1) = 0;
  }
  nwk_disc_table_lite_ent_add_pan(param_1);
  return;
}


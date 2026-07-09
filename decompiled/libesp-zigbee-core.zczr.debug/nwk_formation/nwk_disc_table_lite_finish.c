/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_disc_table_lite_finish
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_disc_table_lite_finish(void)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = core_globals_get();
  uVar1 = *(undefined1 *)(iVar3 + 0xba4);
  iVar3 = core_globals_get();
  bVar2 = *(char *)(iVar3 + 0xba4) + 1U & 1;
  iVar3 = nwk_disc_table_lite_get_slot(uVar1);
  iVar4 = nwk_disc_table_lite_get_slot(bVar2);
  if (*(byte *)(iVar4 + 2) < *(byte *)(iVar3 + 2)) {
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + 0xba4) = bVar2;
  }
  iVar3 = core_globals_get();
  nwk_disc_table_lite_get_slot(*(undefined1 *)(iVar3 + 0xba4));
  return;
}


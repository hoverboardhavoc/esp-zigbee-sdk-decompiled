/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_disc_table_lite_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_disc_table_lite_init(void)

{
  byte bVar1;
  int iVar2;
  
  for (bVar1 = 0; bVar1 < 2; bVar1 = bVar1 + 1) {
    nwk_disc_table_lite_get_slot(bVar1);
    nwk_disc_table_lite_ent_init();
  }
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xba4) = 1;
  return;
}


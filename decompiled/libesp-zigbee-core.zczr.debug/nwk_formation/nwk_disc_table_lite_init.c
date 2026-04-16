/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_disc_table_lite_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_disc_table_lite_init(void)

{
  byte slot;
  nwk_disc_table_lite_ent_t *ent;
  int iVar1;
  
  for (slot = 0; slot < 2; slot = slot + 1) {
    ent = nwk_disc_table_lite_get_slot(slot);
    nwk_disc_table_lite_ent_init(ent);
  }
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xba4) = 1;
  return;
}


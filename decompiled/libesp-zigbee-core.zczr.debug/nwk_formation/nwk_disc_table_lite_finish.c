/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_disc_table_lite_finish
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_disc_table_lite_ent_t * nwk_disc_table_lite_finish(void)

{
  uint8_t slot;
  byte slot_00;
  int iVar1;
  nwk_disc_table_lite_ent_t *pnVar2;
  nwk_disc_table_lite_ent_t *pnVar3;
  
  iVar1 = core_globals_get();
  slot = *(uint8_t *)(iVar1 + 0xba4);
  iVar1 = core_globals_get();
  slot_00 = *(char *)(iVar1 + 0xba4) + 1U & 1;
  pnVar2 = nwk_disc_table_lite_get_slot(slot);
  pnVar3 = nwk_disc_table_lite_get_slot(slot_00);
  if (pnVar3->pan_cnt < pnVar2->pan_cnt) {
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xba4) = slot_00;
  }
  iVar1 = core_globals_get();
  pnVar2 = nwk_disc_table_lite_get_slot(*(uint8_t *)(iVar1 + 0xba4));
  return pnVar2;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_disc_table_lite_get_slot
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_disc_table_lite_ent_t * nwk_disc_table_lite_get_slot(uint8_t slot)

{
  uint8_t slot_00;
  byte slot_01;
  undefined3 in_register_00002029;
  int iVar1;
  nwk_disc_table_lite_ent_t *pnVar2;
  nwk_disc_table_lite_ent_t *pnVar3;
  
  if (CONCAT31(in_register_00002029,slot) < 2) {
    iVar1 = core_globals_get();
    return (nwk_disc_table_lite_ent_t *)(iVar1 + 0xb2c + CONCAT31(in_register_00002029,slot) * 0x3c)
    ;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_formation.c",0x56,
                "nwk_disc_table_lite_get_slot","slot < NWK_DISC_TABLE_LITE_SLOT_NR");
  iVar1 = core_globals_get();
  slot_00 = *(uint8_t *)(iVar1 + 0xba4);
  iVar1 = core_globals_get();
  slot_01 = *(char *)(iVar1 + 0xba4) + 1U & 1;
  pnVar2 = nwk_disc_table_lite_get_slot(slot_00);
  pnVar3 = nwk_disc_table_lite_get_slot(slot_01);
  if (pnVar3->pan_cnt < pnVar2->pan_cnt) {
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xba4) = slot_01;
  }
  iVar1 = core_globals_get();
  pnVar2 = nwk_disc_table_lite_get_slot(*(uint8_t *)(iVar1 + 0xba4));
  return pnVar2;
}


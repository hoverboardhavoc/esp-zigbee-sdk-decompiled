/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_formation.o -> nwk_disc_table_lite_get_slot
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_disc_table_lite_ent_t * nwk_disc_table_lite_get_slot(uint8_t slot)

{
  undefined3 in_register_00002029;
  uint uVar1;
  int iVar2;
  
  uVar1 = CONCAT31(in_register_00002029,slot);
  if (1 < uVar1) {
    uVar1 = __assert_func(0,0,0,0);
  }
  iVar2 = core_globals_get();
  return (nwk_disc_table_lite_ent_t *)(iVar2 + 0xb2c + (-uVar1 & 0x3c));
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> nwk_disc_table_remove_pan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_disc_table_remove_pan(nwk_panid_ref_t panid_ref)

{
  undefined3 in_register_00002029;
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(iVar1 + 0xba4,6,uVar2);
    uVar2 = uVar2 & 0xff;
    if (5 < uVar2) break;
    if ((uint)*(byte *)(iVar1 + uVar2 * 0x14 + 0xb34) == CONCAT31(in_register_00002029,panid_ref)) {
      disc_table_delete((nwk_disc_table_t *)(iVar1 + 0xb2c),
                        ((nwk_disc_table_t *)(iVar1 + 0xb2c))->ents + uVar2);
    }
    uVar2 = uVar2 + 1 & 0xff;
  }
  nwk_address_delete_panid(CONCAT31(in_register_00002029,panid_ref));
  return;
}


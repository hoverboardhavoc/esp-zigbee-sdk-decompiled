/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> get_oui_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_oui_ref_t get_oui_ref(nwk_oui_table_t *tbl,uint8_t (*oui) [3])

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  while( true ) {
    bVar1 = bitmap_find_next_bit(tbl->ent_in_use,0x20,uVar3);
    uVar3 = (uint)bVar1;
    if ((0x1f < uVar3) || (iVar2 = memcmp(tbl->ents + uVar3,oui,3), iVar2 == 0)) break;
    uVar3 = uVar3 + 1 & 0xff;
  }
  return bVar1;
}


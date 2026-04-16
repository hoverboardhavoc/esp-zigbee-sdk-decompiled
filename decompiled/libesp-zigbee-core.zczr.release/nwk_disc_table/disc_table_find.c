/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> disc_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_potential_parent_t *
disc_table_find(nwk_disc_table_t *tbl,nwk_panid_ref_t panid_ref,_Bool is_short,ezb_addr_t *addr)

{
  nwk_potential_parent_t *__s1;
  int iVar1;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(tbl->ent_in_use,6,uVar2);
    if (5 < uVar2) {
      return (nwk_potential_parent_t *)0x0;
    }
    __s1 = tbl->ents + uVar2;
    if ((((uint)__s1->panid_ref == CONCAT31(in_register_0000202d,panid_ref)) &&
        (CONCAT31(in_register_00002031,is_short) == ((uint)__s1->field_7 >> 0x1d & 1))) &&
       (iVar1 = memcmp(__s1,addr,8), iVar1 == 0)) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return __s1;
}


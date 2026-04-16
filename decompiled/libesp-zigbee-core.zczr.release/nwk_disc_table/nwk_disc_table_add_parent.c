/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> nwk_disc_table_add_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_disc_table_add_parent(nwk_potential_parent_t *parent)

{
  byte bVar1;
  nwk_disc_table_ent_t *__s;
  int iVar2;
  ezb_err_t eVar3;
  nwk_potential_parent_t *pnVar4;
  uint uVar5;
  uint8_t lqa;
  byte bVar6;
  
  iVar2 = core_globals_get();
  eVar3 = 2;
  if (parent != (nwk_potential_parent_t *)0x0) {
    pnVar4 = disc_table_find((nwk_disc_table_t *)(iVar2 + 0xb2c),parent->panid_ref,
                             (_Bool)(SUB41(parent->field_7,3) >> 5 & 1),&parent->addr);
    if (pnVar4 == (nwk_potential_parent_t *)0x0) {
      uVar5 = bitmap_find_first_zero_bit((bitmap_t *)(iVar2 + 0xba4),6);
      if (uVar5 < 6) {
        test_and_set_bitmap(uVar5,(bitmap_t *)(iVar2 + 0xba4));
        __s = ((nwk_disc_table_t *)(iVar2 + 0xb2c))->ents + uVar5;
        memset(__s,0,0x14);
      }
      else {
        bVar6 = parent->lqa;
        iVar2 = core_globals_get();
        uVar5 = 0;
        __s = (nwk_disc_table_ent_t *)0x0;
        while( true ) {
          uVar5 = bitmap_find_next_bit(iVar2 + 0xba4,6,uVar5);
          uVar5 = uVar5 & 0xff;
          if (5 < uVar5) break;
          bVar1 = *(byte *)(iVar2 + uVar5 * 0x14 + 0xb35);
          if (bVar1 < bVar6) {
            __s = (nwk_disc_table_ent_t *)(iVar2 + uVar5 * 0x14 + 0xb2c);
            bVar6 = bVar1;
          }
          uVar5 = uVar5 + 1 & 0xff;
        }
        if (__s == (nwk_disc_table_ent_t *)0x0) {
          return 1;
        }
      }
      memcpy(__s,parent,0x14);
    }
    eVar3 = 0;
  }
  return eVar3;
}


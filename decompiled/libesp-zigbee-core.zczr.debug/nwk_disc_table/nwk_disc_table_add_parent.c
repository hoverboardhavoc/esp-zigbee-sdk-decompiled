/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> nwk_disc_table_add_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_disc_table_add_parent(nwk_potential_parent_t *parent)

{
  int iVar1;
  nwk_potential_parent_t *pnVar2;
  ezb_err_t eVar3;
  nwk_disc_table_ent_t *__dest;
  
  iVar1 = core_globals_get();
  if (parent == (nwk_potential_parent_t *)0x0) {
    eVar3 = 2;
  }
  else {
    pnVar2 = disc_table_find((nwk_disc_table_t *)(iVar1 + 0xb2c),parent->panid_ref,
                             (_Bool)(SUB41(parent->field_7,3) >> 5 & 1),&parent->addr);
    if (pnVar2 == (nwk_potential_parent_t *)0x0) {
      __dest = disc_table_new((nwk_disc_table_t *)(iVar1 + 0xb2c));
      if ((__dest == (nwk_disc_table_ent_t *)0x0) &&
         (__dest = disc_table_find_weakest(parent->lqa), __dest == (nwk_disc_table_ent_t *)0x0)) {
        eVar3 = 1;
      }
      else {
        memcpy(__dest,parent,0x14);
        eVar3 = 0;
      }
    }
    else {
      eVar3 = 0;
    }
  }
  return eVar3;
}


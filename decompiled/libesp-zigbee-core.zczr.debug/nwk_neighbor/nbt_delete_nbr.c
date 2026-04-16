/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_delete_nbr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nbt_delete_nbr(nwk_neighbor_table_t *tbl,nwk_neighbor_t *nbr)

{
  uint uVar1;
  nwk_neighbor_t *pnVar2;
  _Bool _Var3;
  uint16_t uVar4;
  undefined3 extraout_var;
  undefined2 extraout_var_00;
  
  uVar1 = (int)nbr - (int)tbl->ents >> 5;
  if ((uVar1 & 0xffff) < (uint)tbl->ent_nr) {
    if (nbr->addr_ref != 0xffff) goto _L0;
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x101,"nbt_delete_nbr",
                  "idx < tbl->ent_nr");
_L0:
    nwk_address_unlock_ref();
  }
  _Var3 = test_and_clr_bitmap(uVar1 & 0xffff,tbl->ent_in_use);
  if (CONCAT31(extraout_var,_Var3) == 0) {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x105,"nbt_delete_nbr",
                  "test_and_clr_bitmap(idx, tbl->ent_in_use)");
  }
  else {
    pnVar2 = tbl->ents;
    uVar4 = nwk_neighbor_table_get_router_capacity();
    if (((int)nbr - (int)pnVar2 >> 5 & 0xffffU) < CONCAT22(extraout_var_00,uVar4)) goto _L0;
    if ((*(uint *)&nbr->field_0xc & 3) == 2) {
      nwk_neighbor_table_remove_stored_child(nbr);
      nbt_dec_ed_cnt(tbl);
      return;
    }
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x107,"nbt_delete_nbr",
                "nwk_device_type_is_zed(nbr->device_type)");
_L0:
  uVar1 = *(uint *)&nbr->field_0xc & 3;
  if ((uVar1 != 0) && (uVar1 != 1)) {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x10b,"nbt_delete_nbr",
                  "nwk_device_type_is_zczr(nbr->device_type)");
  }
  nbt_dec_router_cnt(tbl);
  return;
}


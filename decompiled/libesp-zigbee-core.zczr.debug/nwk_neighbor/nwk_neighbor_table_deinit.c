/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_neighbor_table_deinit(void)

{
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  nwk_neighbor_t *nbr;
  uint uVar4;
  
  iVar2 = core_globals_get();
  _Var1 = nbt_is_inited((nwk_neighbor_table_t *)(iVar2 + 0xb1c));
  if (CONCAT31(extraout_var,_Var1) != 0) {
    mm_free(*(undefined4 *)(iVar2 + 0xb20));
    *(undefined4 *)(iVar2 + 0xb20) = 0;
    mm_free(*(undefined4 *)(iVar2 + 0xb1c));
    *(undefined4 *)(iVar2 + 0xb1c) = 0;
    return;
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x1b9,
                        "nwk_neighbor_table_deinit",&_LC11);
  iVar3 = core_globals_get();
  nbr = nbt_get_new_nbr((nwk_neighbor_table_t *)(iVar3 + 0xb1c),SUB41(iVar2,0));
  if (iVar2 == 0) {
    if (nbr == (nwk_neighbor_t *)0x0) {
      return;
    }
  }
  else if (nbr == (nwk_neighbor_t *)0x0) {
    nbr = nbt_get_stale_router((nwk_neighbor_table_t *)(iVar3 + 0xb1c));
    if (nbr == (nwk_neighbor_t *)0x0) {
      return;
    }
    if (nbr->addr_ref != 0xffff) {
      nwk_address_unlock_ref();
    }
  }
  memset(nbr,0,0x1c);
  nbr->addr_ref = 0xffff;
  uVar4 = *(uint *)&nbr->field_0xc;
  *(uint *)&nbr->field_0xc = uVar4 | 3;
  uVar4 = uVar4 & 0xfffffc3f;
  *(uint *)&nbr->field_0xc = uVar4 | 0xc3;
  *(uint *)&nbr->field_0xc = uVar4 | 0x1c0000c3;
  nwk_neighbor_clear_lqa(nbr);
  return;
}


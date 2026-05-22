/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_table_init(uint16_t capacity)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  undefined3 extraout_var_00;
  int iVar4;
  nwk_neighbor_t *nbr;
  uint uVar5;
  
  uVar5 = CONCAT22(in_register_0000202a,capacity);
  iVar2 = core_globals_get();
  _Var1 = nbt_is_inited((nwk_neighbor_table_t *)(iVar2 + 0xb1c));
  if ((CONCAT31(extraout_var,_Var1) == 0) && (uVar5 != 0)) {
    memset((nwk_neighbor_table_t *)(iVar2 + 0xb1c),0,0x10);
    *(uint16_t *)(iVar2 + 0xb24) = capacity;
    uVar3 = mm_calloc(uVar5,0x20);
    *(undefined4 *)(iVar2 + 0xb20) = uVar3;
    uVar3 = mm_calloc(*(ushort *)(iVar2 + 0xb24) + 7 >> 3,1);
    *(undefined4 *)(iVar2 + 0xb1c) = uVar3;
    *(short *)(iVar2 + 0xb26) = (short)(uVar5 >> 1);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x1ac,
                "nwk_neighbor_table_init",&_LC11);
  iVar2 = core_globals_get();
  _Var1 = nbt_is_inited((nwk_neighbor_table_t *)(iVar2 + 0xb1c));
  if (CONCAT31(extraout_var_00,_Var1) != 0) {
    mm_free(*(undefined4 *)(iVar2 + 0xb20));
    *(undefined4 *)(iVar2 + 0xb20) = 0;
    mm_free(*(undefined4 *)(iVar2 + 0xb1c));
    *(undefined4 *)(iVar2 + 0xb1c) = 0;
    return;
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x1ba,
                        "nwk_neighbor_table_deinit",&_LC11);
  iVar4 = core_globals_get();
  nbr = nbt_get_new_nbr((nwk_neighbor_table_t *)(iVar4 + 0xb1c),SUB41(iVar2,0));
  if (iVar2 == 0) {
    if (nbr == (nwk_neighbor_t *)0x0) {
      return;
    }
  }
  else if (nbr == (nwk_neighbor_t *)0x0) {
    nbr = nbt_get_stale_router((nwk_neighbor_table_t *)(iVar4 + 0xb1c));
    if (nbr == (nwk_neighbor_t *)0x0) {
      return;
    }
    if (nbr->addr_ref != 0xffff) {
      nwk_address_unlock_ref();
    }
  }
  memset(nbr,0,0x20);
  nbr->addr_ref = 0xffff;
  uVar5 = *(uint *)&nbr->field_0xc;
  *(uint *)&nbr->field_0xc = uVar5 | 3;
  uVar5 = uVar5 & 0xfffffc3f;
  *(uint *)&nbr->field_0xc = uVar5 | 0xc3;
  *(uint *)&nbr->field_0xc = uVar5 | 0x1c0000c3;
  nwk_neighbor_clear_lqa(nbr);
  return;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_inc_router_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000108b8) */
/* WARNING: Unknown calling convention */

void nbt_inc_router_cnt(nwk_neighbor_table_t *tbl)

{
  undefined4 uVar1;
  int unaff_s0;
  int iVar2;
  undefined2 *puVar3;
  nwk_neighbor_t *nbr;
  uint extraout_a1;
  char *pcVar4;
  int unaff_s7;
  undefined4 in_stack_000000bc;
  undefined4 in_stack_000000e8;
  undefined1 auStack_22 [14];
  undefined4 uStack_14;
  
  if ((int)(uint)tbl->r_num < (int)((uint)tbl->ent_nr - (uint)tbl->ed_capacity)) {
    tbl->r_num = tbl->r_num + 1;
    return;
  }
  pcVar4 = "nbt_inc_router_cnt";
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xd4,
                        "tbl->r_num < (tbl->ent_nr - tbl->ed_capacity)");
  uVar1 = 0x10118;
  puVar3 = (undefined2 *)
           FUN_000101c0(in_stack_000000e8,*(undefined8 *)(iVar2 + 0xd8),
                        *(undefined8 *)(pcVar4 + 0x44));
  if (unaff_s7 != 0) {
    uStack_14 = uVar1;
    iVar2 = nwk_address_short_by_ref
                      (*puVar3,auStack_22,in_stack_000000bc,*(undefined8 *)(puVar3 + 0x6c),
                       *(undefined8 *)(pcVar4 + 0x44),*(undefined8 *)(unaff_s0 + 0x40));
    if (iVar2 != 0) {
      nbr = (nwk_neighbor_t *)
            __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xa0,
                          "nwk_neighbor_get_shortaddr",
                          "(nwk_address_short_by_ref(nbr->addr_ref, &shortaddr)) == 0");
      *(uint *)&nbr->field_0xc = *(uint *)&nbr->field_0xc & 0xe3ffffff | (extraout_a1 & 7) << 0x1a;
      if (extraout_a1 == 0) {
        nwk_neighbor_get_shortaddr(nbr);
        nwk_route_table_remove_by_dst();
        nwk_neighbor_get_shortaddr(nbr);
        nwk_route_table_remove_by_next_hop();
      }
      return;
    }
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


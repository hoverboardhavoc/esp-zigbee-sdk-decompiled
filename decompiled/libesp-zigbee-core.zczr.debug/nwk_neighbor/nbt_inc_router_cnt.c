/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_inc_router_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000108b8) */
/* WARNING: Removing unreachable block (ram,0x0001090e) */
/* WARNING: Removing unreachable block (ram,0x000108c0) */
/* WARNING: Removing unreachable block (ram,0x000108c8) */
/* WARNING: Unknown calling convention */

void nbt_inc_router_cnt(nwk_neighbor_table_t *tbl)

{
  int unaff_s0;
  int iVar1;
  char *pcVar2;
  int unaff_s7;
  undefined4 in_csr726;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_000000e8;
  
  if ((int)(uint)tbl->r_num < (int)((uint)tbl->ent_nr - (uint)tbl->ed_capacity)) {
    tbl->r_num = tbl->r_num + 1;
    return;
  }
  pcVar2 = "nbt_inc_router_cnt";
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xd3);
  iVar1 = FUN_000101c0(in_stack_000000e8,*(undefined8 *)(iVar1 + 0xd8),
                       *(undefined8 *)(pcVar2 + 0x44));
  if (unaff_s7 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_0001073e(in_csr726,in_stack_0000000c,*(undefined8 *)(iVar1 + 0xd8),
               *(undefined8 *)(iVar1 + 0x44),*(undefined8 *)(unaff_s0 + 0x40));
  func_0x00010574();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


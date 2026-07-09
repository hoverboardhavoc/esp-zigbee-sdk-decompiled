/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_store_bind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void aps_bind_table_store_bind(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  aps_bind_table_remove_stored_bind();
  uStack_1c._0_3_ = CONCAT12(*(undefined1 *)(param_1 + 2),*(undefined2 *)(param_1 + 4));
  if ((*(byte *)((int)param_2 + 5) & 1) == 0) {
    iVar1 = nwk_address_extended_by_ref(*param_2,&uStack_24);
    if (iVar1 != 0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x21a,
                    "aps_bind_table_store_bind",
                    "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &dst_addr)) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uStack_1c = CONCAT13(*(undefined1 *)(param_2 + 1),(uint3)uStack_1c);
    uStack_18 = uStack_24;
    uStack_14 = uStack_20;
  }
  else {
    uStack_1c = (uint)(uint3)uStack_1c;
    uStack_18 = CONCAT22(uStack_18._2_2_,*param_2);
  }
  ds_internal_add_entry(6,&uStack_1c,0xc);
  return;
}


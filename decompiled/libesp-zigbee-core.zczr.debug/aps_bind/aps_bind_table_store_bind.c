/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_store_bind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

ezb_err_t aps_bind_table_store_bind(aps_bind_src_t *src,aps_bind_dst_t *dst)

{
  ezb_err_t eVar1;
  int iVar2;
  uint unaff_s7;
  undefined1 auStack_24 [4];
  ezb_extaddr_t dst_addr;
  dataset_bind_info_t bind_info;
  
  dst_addr.field_0.u64._4_4_ = 0;
  aps_bind_table_remove_stored_bind(src,dst);
  dst_addr.field_0.u8[6] = src->src_ep;
  dst_addr.field_0.u64._4_2_ = src->cluster_id;
  if ((dst->field_0x5 & 1) == 0) {
    iVar2 = nwk_address_extended_by_ref((dst->field_0).extaddr.addr_ref,auStack_24);
    if (iVar2 != 0) {
      __assert_func("//build/esp-zigbee/src/core/aps/aps_bind.c",0x218,
                    "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &dst_addr)) == 0");
      if (unaff_s7 <= tp) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    dst_addr.field_0.u8[7] = (dst->field_0).extaddr.endpoint;
  }
  else {
    dst_addr.field_0.u8[7] = 0;
  }
  eVar1 = ds_internal_add_entry(6,(undefined1 *)((int)&dst_addr.field_0 + 4),0xc);
  return eVar1;
}


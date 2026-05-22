/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_remove_stored_bind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_bind_table_remove_stored_bind(aps_bind_src_t *src,aps_bind_dst_t *dst)

{
  int iVar1;
  uint8_t uVar2;
  int iStack_28;
  ezb_extaddr_t dst_addr;
  ds_bind_info_iterator_t itor;
  
  ds_bind_info_itor_read((ds_bind_info_iterator_t *)((int)&dst_addr.field_0 + 4));
  do {
    if ((dst_addr.field_0.u64._4_2_ == src->cluster_id) && (dst_addr.field_0.u8[6] == src->src_ep))
    {
      if ((dst->field_0x5 & 1) == 0) {
        uVar2 = (dst->field_0).extaddr.endpoint;
      }
      else {
        uVar2 = '\0';
      }
      if (dst_addr.field_0.u8[7] == uVar2) {
        if ((dst->field_0x5 & 1) == 0) {
          iVar1 = nwk_address_extended_by_ref((dst->field_0).extaddr.addr_ref,&iStack_28);
          if (iVar1 != 0) {
            __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x203,
                          "aps_bind_table_remove_stored_bind",
                          "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &dst_addr)) == 0");
            return;
          }
          if ((itor.data._0_4_ == iStack_28) &&
             (itor.data.field_3._0_4_ == dst_addr.field_0.u64._0_4_)) goto _L0;
        }
        else if ((itor.data._0_4_ & 0xffff) == (uint)(dst->field_0).extaddr.addr_ref) {
_L0:
          ds_bind_info_delete((ds_bind_info_iterator_t *)((int)&dst_addr.field_0 + 4));
        }
      }
    }
    ds_bind_info_next((ds_bind_info_iterator_t *)((int)&dst_addr.field_0 + 4));
  } while( true );
}


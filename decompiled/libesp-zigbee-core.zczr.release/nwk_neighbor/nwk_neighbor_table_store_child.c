/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_store_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_neighbor_table_store_child(nwk_neighbor_t *child)

{
  ezb_shortaddr_t eVar1;
  ezb_err_t eVar2;
  undefined4 uStack_24;
  dataset_child_info_t child_info;
  
  if ((*(uint *)&child->field_0xc & 0x3c3) != 0x42) {
    child = (nwk_neighbor_t *)__assert_func(0,0,0,0);
  }
  uStack_24 = 0;
  child_info.version = 0;
  child_info.shortaddr = 0;
  child_info.extaddr.field_0.u64._0_4_ = 0;
  child_info.extaddr.field_0.u64._4_4_ = 0;
  child_info.ed_configuration = 0;
  child_info.mac_iface_idx = '\0';
  child_info.key_seq = '\0';
  nwk_neighbor_table_remove_stored_child(child);
  eVar1 = nwk_neighbor_get_shortaddr(child);
  uStack_24 = CONCAT22(eVar1,(undefined2)uStack_24);
  nwk_neighbor_get_extaddr(child,(ezb_extaddr_t *)&child_info);
  child_info.ed_configuration._0_1_ =
       (byte)(*(uint *)&child->field_0xc >> 6) & 0x10 |
       (byte)(*(uint *)((int)&child->dev + 4) >> 0x14) & 0xf | (byte)child_info._12_4_ & 0xe0;
  child_info.extaddr.field_0.u64._4_4_ =
       CONCAT22(CONCAT11(child->key_seq,(char)(*(uint *)&child->field_0xc >> 0xd)),
                (child->dev).r.router_info) & 0xff1fffff;
  eVar2 = ds_internal_add_entry(4,&uStack_24,0x14);
  return eVar2;
}


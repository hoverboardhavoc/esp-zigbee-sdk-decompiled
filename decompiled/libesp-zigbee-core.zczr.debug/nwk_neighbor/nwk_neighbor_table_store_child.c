/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_store_child
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
  nwk_neighbor_t *nbr;
  int iVar3;
  uint uVar4;
  undefined4 uStack_24;
  dataset_child_info_t child_info;
  
  if ((*(uint *)&child->field_0xc & 0x3c3) == 0x42) {
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
    child_info._12_4_ =
         child_info._12_4_ & 0xffffffe0 | (*(uint *)&child->field_0xc >> 10 & 1) << 4 |
         *(uint *)((int)&child->dev + 4) >> 0x14 & 0xf;
    child_info.extaddr.field_0.u64._4_4_ =
         CONCAT22(CONCAT11(child->key_seq,(char)(*(uint *)&child->field_0xc >> 0xd)),
                  (child->dev).r.router_info) & 0xff1fffff;
    eVar2 = ds_internal_add_entry(4,&uStack_24,0x14);
    return eVar2;
  }
  nbr = (nwk_neighbor_t *)
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x28b,
                      "nwk_neighbor_table_store_child",
                      "(child->device_type == NWK_DEVICE_TYPE_ZED) && (child->relationship == NWK_RELATIONSHIP_CHILD)"
                     );
  uVar4 = *(uint *)&nbr->field_0xc & 3;
  if (uVar4 == 2) {
    iVar3 = 1;
  }
  else {
    iVar3 = 2;
  }
  *(uint *)&nbr->field_0xc = *(uint *)&nbr->field_0xc & 0xfffffc3f | iVar3 << 6;
  if (uVar4 == 2) {
    iVar3 = core_globals_get();
    nwk_neighbor_zed_set_timeout(nbr,*(uint8_t *)(iVar3 + 0xa29));
    eVar2 = nwk_neighbor_table_store_child(nbr);
  }
  else {
    iVar3 = core_globals_get();
    (nbr->dev).r.inbound_activity = *(uint8_t *)(iVar3 + 0xa25);
    iVar3 = core_globals_get();
    eVar2 = iVar3 + 0x1000;
    (nbr->dev).r.outbound_activity = *(uint8_t *)(iVar3 + 0xa25);
  }
  return eVar2;
}


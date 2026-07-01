/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_update_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: ind */
/* WARNING: Unknown calling convention */

void aps_cmd_handle_update_device(aps_header_t *aps_hdr,zmsg_t *msg)

{
  ezb_shortaddr_t eVar1;
  ezb_shortaddr_t router_addr;
  uint uVar2;
  int iVar3;
  undefined1 auStack_28 [4];
  apsme_update_device_ind_t ind;
  
  iVar3 = aps_secur_is_tc();
  if (iVar3 != 0) {
    auStack_28 = (undefined1  [4])0x0;
    ind.field_0._0_4_ = 0;
    ind.field_0._4_4_ = 0;
    ind.device_address.field_0.u64._0_4_ = 0;
    ind.device_address.field_0.u64._4_4_ = 0;
    ind.device_shortaddr = 0;
    ind.status = '\0';
    ind._19_1_ = 0;
    iVar3 = zmsg_get_offset(msg);
    uVar2 = iVar3 + 1U & 0xffff;
    iVar3 = zmsg_get_length(msg);
    if (((10 < (int)(iVar3 - uVar2)) &&
        (iVar3 = nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,auStack_28), iVar3 == 0
        )) && (((msg->flags & 4) != 0 ||
               ((iVar3 = aps_secur_get_key_pair_by_addr(auStack_28), iVar3 == 0 ||
                ((*(ushort *)(iVar3 + 0x34) & 1) != 0)))))) {
      iVar3 = zmsg_read_bytes(msg,uVar2,8,(undefined1 *)((int)&ind.field_0 + 4));
      uVar2 = uVar2 + iVar3 & 0xffff;
      iVar3 = zmsg_read_bytes(msg,uVar2,2,(undefined1 *)((int)&ind.device_address.field_0 + 4));
      zmsg_read_bytes(msg,uVar2 + iVar3 & 0xffff,1,
                      (undefined1 *)((int)&ind.device_address.field_0 + 6));
      eVar1 = (aps_hdr->addr_info).src_addr;
      iVar3 = nwk_neighbor_table_get_by_short(eVar1);
      if (iVar3 == 0) {
        iVar3 = nwk_route_table_find(eVar1);
        if (iVar3 != 0) {
          nwk_route_table_add_rev_route
                    (ind.device_address.field_0.u64._4_4_ & 0xffff,*(undefined2 *)(iVar3 + 2),0);
        }
      }
      else {
        nwk_route_table_add_rev_route(ind.device_address.field_0.u64._4_4_ & 0xffff,eVar1,0);
      }
      apsme_update_device_indication((apsme_update_device_ind_t *)auStack_28);
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}


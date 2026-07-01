/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_bind_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_mgmt_bind_rsp
          (zdo_packet_payload_t *payload,zdp_nwk_mgmt_bind_rsp_field_t *rsp,_Bool is_write)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ezb_zdp_nwk_mgmt_bind_table_entry_t *peVar4;
  undefined3 in_register_00002031;
  char *pcVar5;
  zdp_status_t unaff_s2;
  uint uVar6;
  uint unaff_s4;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (rsp == (zdp_nwk_mgmt_bind_rsp_field_t *)0x0)) {
    pcVar5 = "zdo_op_nwk_mgmt_bind_rsp";
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x19f,
                  "payload && rsp");
    goto _L0;
  }
  if (CONCAT31(in_register_00002031,is_write) == 0) {
    auStack_22[0] = 0;
    uVar3 = zmsg_get_length();
    af_read_le8(payload,auStack_22,&rsp->status);
    af_read_le8(payload,auStack_22,&rsp->binding_table_entries);
    af_read_le8(payload,auStack_22,&rsp->start_index);
    af_read_le8(payload,auStack_22,&rsp->binding_table_list_count);
    if (auStack_22[0] <= uVar3) {
      if (rsp->status != '\0') {
        return '\0';
      }
      bVar1 = rsp->binding_table_list_count;
      if (bVar1 == 0) {
        return bVar1;
      }
      peVar4 = (ezb_zdp_nwk_mgmt_bind_table_entry_t *)calloc((uint)bVar1,0x18);
      rsp->binding_table_list = peVar4;
      if (peVar4 != (ezb_zdp_nwk_mgmt_bind_table_entry_t *)0x0) {
        uVar6 = 0;
        while( true ) {
          if (rsp->binding_table_list_count <= uVar6) {
            return '\0';
          }
          af_read_bytes(payload,auStack_22,8,(uint8_t *)(rsp->binding_table_list + uVar6));
          af_read_le8(payload,auStack_22,&rsp->binding_table_list[uVar6].src_ep);
          af_read_le16(payload,auStack_22,&rsp->binding_table_list[uVar6].cluster_id);
          af_read_le8(payload,auStack_22,&rsp->binding_table_list[uVar6].dst_addr_mode);
          if (uVar3 < auStack_22[0]) break;
          peVar4 = rsp->binding_table_list;
          if (peVar4[uVar6].dst_addr_mode == '\x01') {
            af_read_le16(payload,auStack_22,&peVar4[uVar6].dst_addr.short_addr);
            rsp->binding_table_list[uVar6].dst_ep = '\0';
          }
          else {
            if (peVar4[uVar6].dst_addr_mode != '\x03') {
              return 0x80;
            }
            af_read_bytes(payload,auStack_22,8,(uint8_t *)&peVar4[uVar6].dst_addr.short_addr);
            af_read_le8(payload,auStack_22,&rsp->binding_table_list[uVar6].dst_ep);
          }
          if (uVar3 < auStack_22[0]) {
            return 0xfe;
          }
          uVar6 = uVar6 + 1 & 0xff;
        }
      }
    }
    return 0xfe;
  }
  auStack_22[0]._0_1_ = rsp->status;
  iVar2 = zmsg_append_bytes(1,auStack_22);
  if (iVar2 != 0) {
    return 0x8a;
  }
  auStack_22[0]._0_1_ = rsp->binding_table_entries;
  iVar2 = zmsg_append_bytes(payload,1,auStack_22);
  if (iVar2 != 0) {
    return 0x8a;
  }
  auStack_22[0]._0_1_ = rsp->start_index;
  iVar2 = zmsg_append_bytes(payload,1,auStack_22);
  if (iVar2 != 0) {
    return 0x8a;
  }
  auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->binding_table_list_count);
  iVar2 = zmsg_append_bytes(payload,1,auStack_22);
  if (iVar2 != 0) {
    return 0x8a;
  }
  if (rsp->status != '\0') {
    return '\0';
  }
  if (rsp->binding_table_list == (ezb_zdp_nwk_mgmt_bind_table_entry_t *)0x0) {
    return '\0';
  }
  if (rsp->binding_table_list_count == '\0') {
    return '\0';
  }
  unaff_s2 = '\0';
  unaff_s4 = 0;
  while( true ) {
    if (rsp->binding_table_list_count <= unaff_s4) {
      return unaff_s2;
    }
    iVar2 = zmsg_append_bytes(payload,8,rsp->binding_table_list + unaff_s4);
    if (iVar2 != 0) {
      return 0x8a;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->binding_table_list[unaff_s4].src_ep);
    iVar2 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    auStack_22[0] = rsp->binding_table_list[unaff_s4].cluster_id;
    iVar2 = zmsg_append_bytes(payload,2,auStack_22);
    if (iVar2 != 0) break;
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->binding_table_list[unaff_s4].dst_addr_mode);
    iVar2 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    pcVar5 = (char *)(rsp->binding_table_list + unaff_s4);
    if (((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar5)->dst_addr_mode == '\x01') {
_L0:
      auStack_22[0] = (((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar5)->dst_addr).short_addr;
      iVar2 = zmsg_append_bytes(payload,2,auStack_22);
      if (iVar2 != 0) {
        return 0x8a;
      }
    }
    else if (((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar5)->dst_addr_mode == '\x03') {
      iVar2 = zmsg_append_bytes(payload,8,&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar5)->dst_addr
                               );
      if (iVar2 != 0) {
        return 0x8a;
      }
      auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->binding_table_list[unaff_s4].dst_ep);
      iVar2 = zmsg_append_bytes(payload,1,auStack_22);
      if (iVar2 != 0) {
        return 0x8a;
      }
    }
    unaff_s4 = unaff_s4 + 1 & 0xff;
  }
  return 0x8a;
}


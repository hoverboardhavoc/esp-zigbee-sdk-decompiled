/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  uint8_t uVar2;
  int iVar3;
  uint uVar4;
  ezb_zdp_nwk_mgmt_bind_table_entry_t *peVar5;
  undefined3 in_register_00002031;
  char *pcVar6;
  zdp_status_t unaff_s2;
  uint uVar7;
  uint unaff_s4;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (rsp == (zdp_nwk_mgmt_bind_rsp_field_t *)0x0)) {
    pcVar6 = "zdo_op_nwk_mgmt_bind_rsp";
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x140,"payload && rsp");
    goto _L0;
  }
  if (CONCAT31(in_register_00002031,is_write) == 0) {
    auStack_22[0] = 0;
    uVar4 = zmsg_get_length();
    af_read_le8(payload,auStack_22,&rsp->status);
    af_read_le8(payload,auStack_22,&rsp->binding_table_entries);
    af_read_le8(payload,auStack_22,&rsp->start_index);
    af_read_le8(payload,auStack_22,&rsp->binding_table_list_count);
    if (auStack_22[0] <= uVar4) {
      if (rsp->status != '\0') {
        return '\0';
      }
      bVar1 = rsp->binding_table_list_count;
      if (bVar1 == 0) {
        return bVar1;
      }
      peVar5 = (ezb_zdp_nwk_mgmt_bind_table_entry_t *)calloc((uint)bVar1,0x18);
      rsp->binding_table_list = peVar5;
      if (peVar5 != (ezb_zdp_nwk_mgmt_bind_table_entry_t *)0x0) {
        uVar7 = 0;
        while( true ) {
          if (rsp->binding_table_list_count <= uVar7) {
            return '\0';
          }
          af_read_bytes(payload,auStack_22,8,(uint8_t *)(rsp->binding_table_list + uVar7));
          af_read_le8(payload,auStack_22,&rsp->binding_table_list[uVar7].src_ep);
          af_read_le16(payload,auStack_22,&rsp->binding_table_list[uVar7].cluster_id);
          af_read_le8(payload,auStack_22,&rsp->binding_table_list[uVar7].dst_addr_mode);
          if (uVar4 < auStack_22[0]) break;
          peVar5 = rsp->binding_table_list;
          uVar2 = peVar5[uVar7].dst_addr_mode;
          if (uVar2 == '\x01') {
            af_read_le16(payload,auStack_22,&peVar5[uVar7].dst_addr.short_addr);
            rsp->binding_table_list[uVar7].dst_ep = '\0';
          }
          else {
            if (uVar2 != '\x03') {
              log_write(2,"ZDO_NWK_MGMT","MgmtBindRsp: Invalid DstAddrMode: 0x%02x",uVar2);
              return 0x80;
            }
            af_read_bytes(payload,auStack_22,8,(uint8_t *)&peVar5[uVar7].dst_addr.short_addr);
            af_read_le8(payload,auStack_22,&rsp->binding_table_list[uVar7].dst_ep);
          }
          if (uVar4 < auStack_22[0]) {
            return 0xfe;
          }
          uVar7 = uVar7 + 1 & 0xff;
        }
      }
    }
    return 0xfe;
  }
  auStack_22[0]._0_1_ = rsp->status;
  iVar3 = zmsg_append_bytes(1,auStack_22);
  if (iVar3 != 0) {
    return 0x8a;
  }
  auStack_22[0]._0_1_ = rsp->binding_table_entries;
  iVar3 = zmsg_append_bytes(payload,1,auStack_22);
  if (iVar3 != 0) {
    return 0x8a;
  }
  auStack_22[0]._0_1_ = rsp->start_index;
  iVar3 = zmsg_append_bytes(payload,1,auStack_22);
  if (iVar3 != 0) {
    return 0x8a;
  }
  auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->binding_table_list_count);
  iVar3 = zmsg_append_bytes(payload,1,auStack_22);
  if (iVar3 != 0) {
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
    iVar3 = zmsg_append_bytes(payload,8,rsp->binding_table_list + unaff_s4);
    if (iVar3 != 0) {
      return 0x8a;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->binding_table_list[unaff_s4].src_ep);
    iVar3 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    auStack_22[0] = rsp->binding_table_list[unaff_s4].cluster_id;
    iVar3 = zmsg_append_bytes(payload,2,auStack_22);
    if (iVar3 != 0) break;
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->binding_table_list[unaff_s4].dst_addr_mode);
    iVar3 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    pcVar6 = (char *)(rsp->binding_table_list + unaff_s4);
    if (((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar6)->dst_addr_mode == '\x01') {
_L0:
      auStack_22[0] = (((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar6)->dst_addr).short_addr;
      iVar3 = zmsg_append_bytes(payload,2,auStack_22);
      if (iVar3 != 0) {
        return 0x8a;
      }
    }
    else if (((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar6)->dst_addr_mode == '\x03') {
      iVar3 = zmsg_append_bytes(payload,8,&((ezb_zdp_nwk_mgmt_bind_table_entry_t *)pcVar6)->dst_addr
                               );
      if (iVar3 != 0) {
        return 0x8a;
      }
      auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->binding_table_list[unaff_s4].dst_ep);
      iVar3 = zmsg_append_bytes(payload,1,auStack_22);
      if (iVar3 != 0) {
        return 0x8a;
      }
    }
    unaff_s4 = unaff_s4 + 1 & 0xff;
  }
  return 0x8a;
}


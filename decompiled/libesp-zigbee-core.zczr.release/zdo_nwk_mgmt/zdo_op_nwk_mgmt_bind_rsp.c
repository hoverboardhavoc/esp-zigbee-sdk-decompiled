/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_bind_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_mgmt_bind_rsp
          (zdo_packet_payload_t *payload,zdp_nwk_mgmt_bind_rsp_field_t *rsp,_Bool is_write)

{
  zdp_nwk_mgmt_bind_rsp_field_t *unaff_s0;
  ezb_err_t eVar1;
  zdp_nwk_mgmt_bind_rsp_field_t *extraout_a1;
  undefined3 in_register_00002031;
  int iVar2;
  ezb_zdp_nwk_mgmt_bind_table_entry_t *peVar3;
  uint uVar4;
  uint uVar5;
  uint16_t auStack_32 [2];
  uint16_t offset;
  
  iVar2 = CONCAT31(in_register_00002031,is_write);
  if ((payload == (zdo_packet_payload_t *)0x0) ||
     (unaff_s0 = rsp, rsp == (zdp_nwk_mgmt_bind_rsp_field_t *)0x0)) {
    iVar2 = 0;
    payload = (zdo_packet_payload_t *)__assert_func(0,0,0);
    rsp = extraout_a1;
  }
  if (iVar2 == 0) {
    auStack_32[0] = 0;
    uVar4 = zmsg_get_length();
    af_read_le8(payload,auStack_32,&unaff_s0->status);
    af_read_le8(payload,auStack_32,&unaff_s0->binding_table_entries);
    af_read_le8(payload,auStack_32,&unaff_s0->start_index);
    af_read_le8(payload,auStack_32,&unaff_s0->binding_table_list_count);
    if (uVar4 < auStack_32[0]) {
      return 0xfe;
    }
    if ((unaff_s0->status == '\0') && (unaff_s0->binding_table_list_count != 0)) {
      peVar3 = (ezb_zdp_nwk_mgmt_bind_table_entry_t *)
               calloc((uint)unaff_s0->binding_table_list_count,0x18);
      unaff_s0->binding_table_list = peVar3;
      if (peVar3 == (ezb_zdp_nwk_mgmt_bind_table_entry_t *)0x0) {
        return 0xfe;
      }
      for (uVar5 = 0; uVar5 < unaff_s0->binding_table_list_count; uVar5 = uVar5 + 1 & 0xff) {
        af_read_bytes(payload,auStack_32,8,(uint8_t *)(unaff_s0->binding_table_list + uVar5));
        af_read_le8(payload,auStack_32,&unaff_s0->binding_table_list[uVar5].src_ep);
        af_read_le16(payload,auStack_32,&unaff_s0->binding_table_list[uVar5].cluster_id);
        af_read_le8(payload,auStack_32,&unaff_s0->binding_table_list[uVar5].dst_addr_mode);
        if (uVar4 < auStack_32[0]) {
          return 0xfe;
        }
        peVar3 = unaff_s0->binding_table_list;
        if (peVar3[uVar5].dst_addr_mode == '\x01') {
          af_read_le16(payload,auStack_32,&peVar3[uVar5].dst_addr.short_addr);
          unaff_s0->binding_table_list[uVar5].dst_ep = '\0';
        }
        else {
          if (peVar3[uVar5].dst_addr_mode != '\x03') {
            log_write(2,"ZDO_NWK_MGMT","MgmtBindRsp: Invalid DstAddrMode: 0x%02x");
            return 0x80;
          }
          af_read_bytes(payload,auStack_32,8,(uint8_t *)&peVar3[uVar5].dst_addr.short_addr);
          af_read_le8(payload,auStack_32,&unaff_s0->binding_table_list[uVar5].dst_ep);
        }
        if (uVar4 < auStack_32[0]) {
          return 0xfe;
        }
      }
    }
  }
  else {
    eVar1 = zmsg_append_u8(payload,rsp->status);
    if ((((eVar1 != 0) ||
         (eVar1 = zmsg_append_u8(payload,unaff_s0->binding_table_entries), eVar1 != 0)) ||
        (eVar1 = zmsg_append_u8(payload,unaff_s0->start_index), eVar1 != 0)) ||
       (eVar1 = zmsg_append_u8(payload,unaff_s0->binding_table_list_count), eVar1 != 0)) {
      return 0x8a;
    }
    if (((unaff_s0->status == '\0') &&
        (unaff_s0->binding_table_list != (ezb_zdp_nwk_mgmt_bind_table_entry_t *)0x0)) &&
       (unaff_s0->binding_table_list_count != '\0')) {
      for (uVar4 = 0; uVar4 < unaff_s0->binding_table_list_count; uVar4 = uVar4 + 1 & 0xff) {
        iVar2 = zmsg_append_bytes(payload,8,unaff_s0->binding_table_list + uVar4);
        if (iVar2 != 0) {
          return 0x8a;
        }
        eVar1 = zmsg_append_u8(payload,unaff_s0->binding_table_list[uVar4].src_ep);
        if (eVar1 != 0) {
          return 0x8a;
        }
        auStack_32[0] = unaff_s0->binding_table_list[uVar4].cluster_id;
        iVar2 = zmsg_append_bytes(payload,2,auStack_32);
        if (iVar2 != 0) {
          return 0x8a;
        }
        eVar1 = zmsg_append_u8(payload,unaff_s0->binding_table_list[uVar4].dst_addr_mode);
        if (eVar1 != 0) {
          return 0x8a;
        }
        peVar3 = unaff_s0->binding_table_list;
        if (peVar3[uVar4].dst_addr_mode == '\x01') {
          auStack_32[0] = peVar3[uVar4].dst_addr.short_addr;
          iVar2 = zmsg_append_bytes(payload,2,auStack_32);
_L0:
          if (iVar2 != 0) {
            return 0x8a;
          }
        }
        else if (peVar3[uVar4].dst_addr_mode == '\x03') {
          iVar2 = zmsg_append_bytes(payload,8,&peVar3[uVar4].dst_addr);
          if (iVar2 != 0) {
            return 0x8a;
          }
          iVar2 = zmsg_append_u8(payload,unaff_s0->binding_table_list[uVar4].dst_ep);
          goto _L0;
        }
      }
    }
  }
  return '\0';
}


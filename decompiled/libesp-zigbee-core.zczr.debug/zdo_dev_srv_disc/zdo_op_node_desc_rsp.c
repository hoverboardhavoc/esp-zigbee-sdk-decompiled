/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_node_desc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_node_desc_rsp(zdo_packet_payload_t *payload,zdp_node_desc_rsp_field_t *rsp,_Bool is_write)

{
  zdp_status_t unaff_s1;
  int iVar1;
  uint uVar2;
  undefined3 in_register_00002031;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (rsp == (zdp_node_desc_rsp_field_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x291,"zdo_op_node_desc_rsp",
                  "payload && rsp");
  }
  else {
    if (CONCAT31(in_register_00002031,is_write) == 0) {
      auStack_22[0] = 0;
      uVar2 = zmsg_get_length();
      af_read_le8(payload,auStack_22,&rsp->status);
      af_read_le16(payload,auStack_22,&rsp->nwk_addr_of_interest);
      if (auStack_22[0] <= uVar2) {
        if (rsp->status == '\0') {
          af_read_le16(payload,auStack_22,&(rsp->node_desc).node_flags);
          af_read_le8(payload,auStack_22,&(rsp->node_desc).mac_capability_flags);
          af_read_le16(payload,auStack_22,&(rsp->node_desc).manufacturer_code);
          af_read_le8(payload,auStack_22,&(rsp->node_desc).max_buf_size);
          af_read_le16(payload,auStack_22,&(rsp->node_desc).max_incoming_transfer_size);
          af_read_le16(payload,auStack_22,&(rsp->node_desc).server_mask);
          af_read_le16(payload,auStack_22,&(rsp->node_desc).max_outgoing_transfer_size);
          af_read_le8(payload,auStack_22,&(rsp->node_desc).desc_capability_field);
        }
        else {
          memset(&rsp->node_desc,0,0x10);
        }
        if (auStack_22[0] <= uVar2) {
          return '\0';
        }
      }
      return 0xfe;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->status);
    iVar1 = zmsg_append_bytes(1,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_22[0] = rsp->nwk_addr_of_interest;
    iVar1 = zmsg_append_bytes(payload,2,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    unaff_s1 = rsp->status;
    if (unaff_s1 != '\0') {
      return '\0';
    }
  }
  auStack_22[0] = (rsp->node_desc).node_flags;
  iVar1 = zmsg_append_bytes(payload,2,auStack_22);
  if (iVar1 == 0) {
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,(rsp->node_desc).mac_capability_flags);
    iVar1 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar1 == 0) {
      auStack_22[0] = (rsp->node_desc).manufacturer_code;
      iVar1 = zmsg_append_bytes(payload,2,auStack_22);
      if (iVar1 == 0) {
        auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,(rsp->node_desc).max_buf_size);
        iVar1 = zmsg_append_bytes(payload,1,auStack_22);
        if (iVar1 == 0) {
          auStack_22[0] = (rsp->node_desc).max_incoming_transfer_size;
          iVar1 = zmsg_append_bytes(payload,2,auStack_22);
          if (iVar1 == 0) {
            auStack_22[0] = (rsp->node_desc).server_mask;
            iVar1 = zmsg_append_bytes(payload,2,auStack_22);
            if (iVar1 == 0) {
              auStack_22[0] = (rsp->node_desc).max_outgoing_transfer_size;
              iVar1 = zmsg_append_bytes(payload,2,auStack_22);
              if (iVar1 == 0) {
                auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,(rsp->node_desc).desc_capability_field)
                ;
                iVar1 = zmsg_append_bytes(payload,1,auStack_22);
                if (iVar1 != 0) {
                  unaff_s1 = 0x8a;
                }
              }
              else {
                unaff_s1 = 0x8a;
              }
            }
            else {
              unaff_s1 = 0x8a;
            }
          }
          else {
            unaff_s1 = 0x8a;
          }
        }
        else {
          unaff_s1 = 0x8a;
        }
      }
      else {
        unaff_s1 = 0x8a;
      }
    }
    else {
      unaff_s1 = 0x8a;
    }
  }
  else {
    unaff_s1 = 0x8a;
  }
  return unaff_s1;
}


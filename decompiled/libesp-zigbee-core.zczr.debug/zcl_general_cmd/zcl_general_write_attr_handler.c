/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_write_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_write_attr_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  zcl_status_t zVar1;
  int iVar2;
  uint uVar3;
  size_t __size;
  zcl_attr_desc_t *attr_desc;
  undefined3 extraout_var;
  int iVar4;
  undefined4 uVar5;
  zmsg_t *unaff_s2;
  uint16_t uVar6;
  uint16_t uStack_3c;
  uint16_t local_3a;
  undefined1 auStack_38 [2];
  uint16_t offset;
  zcl_write_attr_req_t write_attr_req;
  
  _auStack_38 = 0;
  write_attr_req.attr_id = 0;
  write_attr_req.attr_type = '\0';
  write_attr_req._3_1_ = 0;
  if ((((packet == (zcl_packet_t *)0x0) ||
       (unaff_s2 = packet->payload, unaff_s2 == (zcl_packet_payload_t *)0x0)) ||
      (rsp == (zcl_packet_t *)0x0)) || (rsp->payload == (zcl_packet_payload_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x11a,
                  "zcl_general_write_attr_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else if (((packet->header).fc & 4) != 0) {
    uVar6 = (packet->header).manuf_code;
    goto _L0;
  }
  uVar6 = 0;
_L0:
  iVar2 = af_get_ep_desc((packet->header).dst_ep);
  if (iVar2 == 0) {
    uVar5 = 0x81;
  }
  else {
    if (((packet->header).fc & 8) == 0) {
      uVar5 = 1;
    }
    else {
      uVar5 = 2;
    }
    iVar2 = af_endpoint_get_cluster_desc((packet->header).cluster_id,uVar5);
    if (iVar2 == 0) {
      uVar5 = 0xc3;
    }
    else {
      uVar3 = zmsg_get_length(unaff_s2);
      local_3a = 0;
      while (local_3a < uVar3) {
        _auStack_38 = 0;
        write_attr_req.attr_id = 0;
        write_attr_req.attr_type = '\0';
        write_attr_req._3_1_ = 0;
        af_read_le16(unaff_s2,&local_3a,(uint16_t *)auStack_38);
        af_read_le8(unaff_s2,&local_3a,(uint8_t *)&offset);
        __size = zcl_packet_read_variable_attr_size
                           (packet->payload,local_3a,_auStack_38 >> 0x10 & 0xff);
        write_attr_req._0_4_ = calloc(1,__size);
        zcl_packet_read_variable_attr_value
                  (unaff_s2,&local_3a,_auStack_38 >> 0x10 & 0xff,write_attr_req._0_4_);
        attr_desc = (zcl_attr_desc_t *)zcl_cluster_get_attr_desc(iVar2,_auStack_38 & 0xffff,uVar6);
        zVar1 = check_write_attr_filed((zcl_write_attr_req_t *)auStack_38,attr_desc);
        iVar4 = CONCAT31(extraout_var,zVar1);
        if (iVar4 == 0) {
          if (((packet->header).fc & 8) == 0) {
            uVar5 = 1;
          }
          else {
            uVar5 = 2;
          }
          iVar4 = zcl_set_attr_value((packet->header).dst_ep,(packet->header).cluster_id,uVar5,
                                     _auStack_38 & 0xffff,uVar6,write_attr_req._0_4_,0);
          if (iVar4 == 0) {
            if (((packet->header).cluster_id == 0x500) && (((packet->header).fc & 8) == 0)) {
              ias_zone_cluster_srv_set_attr_val_post_proc
                        (packet,_auStack_38 & 0xffff,write_attr_req._0_4_);
            }
            if (((packet->header).fc & 8) == 0) {
              uVar5 = 1;
            }
            else {
              uVar5 = 2;
            }
            zcl_message_notify_attr_value
                      ((packet->header).dst_ep,(packet->header).cluster_id,uVar5,attr_desc);
          }
        }
        uStack_3c = CONCAT11(uStack_3c._1_1_,(char)iVar4);
        zmsg_append_bytes(rsp->payload,1,&uStack_3c);
        if (iVar4 != 0) {
          uStack_3c = (uint16_t)auStack_38;
          zmsg_append_bytes(rsp->payload,2,&uStack_3c);
        }
        mm_free(write_attr_req._0_4_);
      }
      if (local_3a == uVar3) {
        zVar1 = zcl_packet_setup_response(rsp,packet,4);
        return zVar1;
      }
      uVar5 = 0x80;
    }
  }
  zVar1 = zcl_packet_setup_default_response(rsp,packet,uVar5);
  return zVar1;
}


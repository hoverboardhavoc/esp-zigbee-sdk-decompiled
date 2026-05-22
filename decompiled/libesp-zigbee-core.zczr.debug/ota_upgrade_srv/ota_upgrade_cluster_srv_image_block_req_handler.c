/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_cluster_srv_image_block_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_cluster_srv_image_block_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint16_t *unaff_s0;
  ota_upgrade_file_t *poVar1;
  ezb_zcl_status_t eVar2;
  ota_upgrade_file_table_t *poVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint unaff_s3;
  undefined1 auStack_44 [8];
  ota_upgrade_image_block_req_payload_t payload;
  uint16_t offset;
  
  payload.block_delay = 0;
  auStack_44._4_4_ = 0;
  payload.fc = '\0';
  payload._1_1_ = 0;
  payload.manuf_code = 0;
  payload.image_type = 0;
  payload._6_2_ = 0;
  payload.file_version = 0;
  payload.file_offset = 0;
  payload._16_4_ = 0;
  payload.node_addr.field_0.u64._3_4_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c",
                  0x145,"ota_upgrade_cluster_srv_image_block_req_handler","packet && rsp");
_L0:
    af_read_bytes(packet->payload,unaff_s0,8,(uint8_t *)((int)&payload.file_offset + 1));
  }
  else {
    unaff_s3 = zmsg_get_length(packet->payload);
    unaff_s0 = &payload.block_delay;
    af_read_le8(packet->payload,unaff_s0,auStack_44 + 4);
    af_read_le16(packet->payload,unaff_s0,(uint16_t *)(auStack_44 + 6));
    af_read_le16(packet->payload,unaff_s0,(uint16_t *)&payload);
    af_read_le32(packet->payload,unaff_s0,(uint32_t *)&payload.image_type);
    af_read_le32(packet->payload,unaff_s0,&payload.file_version);
    af_read_le8(packet->payload,unaff_s0,(uint8_t *)&payload.file_offset);
    if ((auStack_44._4_4_ & 1) != 0) goto _L0;
  }
  if ((auStack_44._4_4_ & 2) != 0) {
    af_read_le16(packet->payload,&payload.block_delay,(uint16_t *)(payload.node_addr.field_0.u8 + 5)
                );
  }
  if (unaff_s3 < payload.block_delay) {
    uVar5 = 0x80;
  }
  else {
    poVar3 = ota_upgrade_get_file_table((packet->header).dst_ep);
    poVar1 = (ota_upgrade_file_t *)0x0;
    for (uVar6 = 0; uVar6 < poVar3->size; uVar6 = uVar6 + 1 & 0xff) {
      poVar1 = poVar3->entry + uVar6;
      if ((((poVar1->header).manufacturer_code == auStack_44._6_2_) &&
          ((poVar1->header).image_type == payload._0_2_)) &&
         ((poVar1->header).file_version == payload._4_4_)) {
        if ((auStack_44._4_4_ & 1) == 0) break;
        if ((*(uint *)&(poVar1->optional).upgrade_file_destination.field_0 ==
             (payload._16_4_ << 0x18 | payload.file_offset >> 8)) &&
           (*(uint *)((int)&(poVar1->optional).upgrade_file_destination.field_0 + 4) ==
            (payload.node_addr.field_0.u64._3_4_ << 0x18 | (uint)payload._16_4_ >> 8))) break;
      }
    }
    if (poVar1 == (ota_upgrade_file_t *)0x0) {
      uVar5 = 0x98;
    }
    else {
      zcl_message_ota_upgrade_server_progress(packet,'\x02',auStack_44 + 4,(void *)0x0);
      uVar6 = (poVar1->header).total_image_size;
      if (payload.file_version < uVar6) {
        if (uVar6 < (payload.file_offset & 0xff) + payload.file_version) {
          payload.file_offset =
               CONCAT31(payload.file_offset._1_3_,(char)uVar6 - (char)payload.file_version);
        }
        auStack_44._0_4_ = (uint)(uint3)auStack_44._1_3_ << 8;
        iVar4 = zmsg_append_bytes(rsp->payload,1,auStack_44);
        if (iVar4 == 0) {
          auStack_44._0_2_ = auStack_44._6_2_;
          iVar4 = zmsg_append_bytes(rsp->payload,2,auStack_44);
          uVar5 = payload._0_4_;
          if (iVar4 == 0) {
            auStack_44[0] = payload.fc;
            auStack_44[1] = payload._1_1_;
            payload._0_4_ = uVar5;
            iVar4 = zmsg_append_bytes(rsp->payload,2,auStack_44);
            if (iVar4 == 0) {
              auStack_44._0_4_ = payload._4_4_;
              iVar4 = zmsg_append_bytes(rsp->payload,4,auStack_44);
              if (iVar4 == 0) {
                auStack_44._0_4_ = payload.file_version;
                iVar4 = zmsg_append_bytes(rsp->payload,4,auStack_44);
                if (iVar4 == 0) {
                  auStack_44[0] = (undefined1)payload.file_offset;
                  iVar4 = zmsg_append_bytes(rsp->payload,1,auStack_44);
                  if (iVar4 == 0) {
                    iVar4 = zmsg_append_bytes(rsp->payload,payload.file_offset & 0xff,
                                              poVar1->data + payload.file_version);
                    if (iVar4 == 0) goto _L0;
                    uVar5 = 0x89;
                  }
                  else {
                    uVar5 = 0x89;
                  }
                }
                else {
                  uVar5 = 0x89;
                }
              }
              else {
                uVar5 = 0x89;
              }
            }
            else {
              uVar5 = 0x89;
            }
          }
          else {
            uVar5 = 0x89;
          }
        }
        else {
          uVar5 = 0x89;
        }
      }
      else {
        auStack_44[0] = 0x98;
        iVar4 = zmsg_append_bytes(rsp->payload,1,auStack_44);
        if (iVar4 == 0) {
_L0:
          eVar2 = zcl_packet_setup_response_with_extension(rsp,packet,5,0,1);
          return eVar2;
        }
        uVar5 = 0x89;
      }
    }
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar5);
  return eVar2;
}


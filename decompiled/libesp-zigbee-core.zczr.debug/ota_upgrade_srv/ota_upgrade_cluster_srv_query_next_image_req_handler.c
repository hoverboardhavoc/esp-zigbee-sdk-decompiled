/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_cluster_srv_query_next_image_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000106dc) */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_cluster_srv_query_next_image_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint16_t *unaff_s0;
  uint uVar1;
  uint32_t uVar2;
  uint unaff_s1;
  ota_upgrade_file_t *poVar3;
  ezb_zcl_status_t eVar4;
  ota_upgrade_file_table_t *poVar5;
  undefined3 extraout_var;
  uint32_t uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 auStack_48 [4];
  ezb_zcl_ota_upgrade_server_progress_start_t start;
  ota_upgrade_query_next_image_req_payload_t payload;
  uint16_t offset;
  
  payload._14_2_ = 0;
  start.policy.file_version = 0;
  payload.fc = '\0';
  payload._1_1_ = 0;
  payload.manuf_code = 0;
  payload.image_type = 0;
  payload._6_2_ = 0;
  payload.file_version = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c",0xfc,
                  "ota_upgrade_cluster_srv_query_next_image_req_handler","packet && rsp");
_L0:
    af_read_le16(packet->payload,unaff_s0,(uint16_t *)&payload.file_version);
  }
  else {
    unaff_s1 = zmsg_get_length(packet->payload);
    unaff_s0 = (uint16_t *)&payload.field_0xe;
    af_read_le8(packet->payload,unaff_s0,(uint8_t *)&start.policy);
    af_read_le16(packet->payload,unaff_s0,(uint16_t *)((int)&start.policy.file_version + 2));
    af_read_le16(packet->payload,unaff_s0,(uint16_t *)&payload);
    af_read_le32(packet->payload,unaff_s0,(uint32_t *)&payload.image_type);
    if ((start.policy.file_version & 1) != 0) goto _L0;
  }
  if (unaff_s1 < (ushort)payload._14_2_) {
    uVar7 = 0x80;
  }
  else {
    poVar5 = ota_upgrade_get_file_table((packet->header).dst_ep);
    uVar1 = 0;
    iVar8 = 1;
    while (uVar7 = payload._0_4_, poVar5 != (ota_upgrade_file_table_t *)0x0) {
      if (poVar5->size <= uVar1) {
        uVar6 = 0;
        uVar2 = 0;
        goto _L0;
      }
      poVar3 = poVar5->entry;
      if (((poVar3[uVar1].header.manufacturer_code == start.policy.file_version._2_2_) &&
          (poVar3[uVar1].header.image_type == payload._0_2_)) &&
         ((((start.policy.file_version & 1) == 0 || ((poVar3[uVar1].header.hdr_fc & 4) == 0)) ||
          (((*(uint *)((int)&poVar3[uVar1].optional.upgrade_file_destination.field_0 + 7) >> 8 &
            0xffff) <= (payload.file_version & 0xffff) &&
           ((payload.file_version & 0xffff) <= (uint)poVar3[uVar1].optional.maximum_hardware_version
           )))))) {
        auStack_48[2] = (packet->header).src_ep;
        auStack_48._0_2_ = (packet->header).src_addr.u.short_addr;
        start.query.short_address = start.policy.file_version._2_2_;
        start.query.ep_id = payload.fc;
        start.query._3_1_ = payload._1_1_;
        start.query.manuf_code = payload.image_type;
        start.query.image_type = payload._6_2_;
        start.query.file_version._0_2_ = (undefined2)payload.file_version;
        start.query._12_4_ = poVar3[uVar1].header.file_version;
        payload._0_4_ = uVar7;
        eVar4 = zcl_message_ota_upgrade_server_progress(packet,'\0',auStack_48,(void *)0x0);
        iVar8 = CONCAT31(extraout_var,eVar4);
        if (iVar8 == 0) {
          uVar6 = poVar3[uVar1].header.file_version;
          uVar2 = poVar3[uVar1].header.total_image_size;
          goto _L0;
        }
        if (iVar8 == 0xfe) {
          uVar6 = 0;
          uVar2 = 0;
          goto _L0;
        }
      }
      uVar1 = uVar1 + 1 & 0xff;
    }
    uVar6 = 0;
    uVar2 = 0;
_L0:
    if (iVar8 == 0x7e) {
      auStack_48[0] = 0x7e;
      iVar8 = zmsg_append_bytes(rsp->payload,1,auStack_48);
      if (iVar8 == 0) {
_L0:
        eVar4 = zcl_packet_setup_response_with_extension(rsp,packet,2,0,1);
        return eVar4;
      }
      uVar7 = 0x7e;
    }
    else if (uVar2 == 0) {
      auStack_48[0] = 0x98;
      iVar8 = zmsg_append_bytes(rsp->payload,1,auStack_48);
      if (iVar8 == 0) goto _L0;
      uVar7 = 0x89;
    }
    else {
      auStack_48 = (undefined1  [4])((uint)auStack_48 & 0xffffff00);
      iVar8 = zmsg_append_bytes(rsp->payload,1,auStack_48);
      if (iVar8 == 0) {
        auStack_48._0_2_ = start.policy.file_version._2_2_;
        iVar8 = zmsg_append_bytes(rsp->payload,2,auStack_48);
        if (iVar8 == 0) {
          auStack_48._0_2_ = payload._0_2_;
          iVar8 = zmsg_append_bytes(rsp->payload,2,auStack_48);
          if (iVar8 == 0) {
            auStack_48 = (undefined1  [4])uVar6;
            iVar8 = zmsg_append_bytes(rsp->payload,4,auStack_48);
            if (iVar8 == 0) {
              auStack_48 = (undefined1  [4])uVar2;
              iVar8 = zmsg_append_bytes(rsp->payload,4,auStack_48);
              if (iVar8 == 0) goto _L0;
              uVar7 = 0x89;
            }
            else {
              uVar7 = 0x89;
            }
          }
          else {
            uVar7 = 0x89;
          }
        }
        else {
          uVar7 = 0x89;
        }
      }
      else {
        uVar7 = 0x89;
      }
    }
  }
  eVar4 = zcl_packet_setup_default_response(rsp,packet,uVar7);
  return eVar4;
}


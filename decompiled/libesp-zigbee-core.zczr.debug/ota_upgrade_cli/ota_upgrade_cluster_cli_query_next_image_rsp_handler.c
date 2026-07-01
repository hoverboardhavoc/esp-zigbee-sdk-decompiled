/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_query_next_image_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_cluster_cli_query_next_image_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  ota_upgrade_downloading_context_t *context;
  uint uVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  uint16_t *offset_00;
  undefined1 auStack_34 [4];
  ota_upgrade_query_next_image_rsp_t payload;
  uint16_t offset;
  
  payload.image_size._2_2_ = 0;
  auStack_34[0] = '\0';
  auStack_34[1] = 0;
  auStack_34._2_2_ = 0;
  payload.status = '\0';
  payload._1_1_ = 0;
  payload.manuf_code = 0;
  payload.image_type = 0;
  payload._6_2_ = 0;
  payload.file_version = 0;
  if (packet == (zcl_packet_t *)0x0) {
    iVar3 = 1;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    iVar3 = 1;
  }
  else {
    context = ota_upgrade_downloading_context_get((packet->header).dst_ep);
    if (*(context->attr).upgrade_status == '\0') {
      uVar2 = zmsg_get_length(packet->payload);
      af_read_le8(packet->payload,(uint16_t *)((int)&payload.image_size + 2),auStack_34);
      if (auStack_34[0] == '\0') {
        offset_00 = (uint16_t *)((int)&payload.image_size + 2);
        af_read_le16(packet->payload,offset_00,(uint16_t *)(auStack_34 + 2));
        af_read_le16(packet->payload,offset_00,(uint16_t *)&payload);
        af_read_le32(packet->payload,offset_00,(uint32_t *)&payload.image_type);
        af_read_le32(packet->payload,offset_00,&payload.file_version);
      }
      if (uVar2 < payload.image_size._2_2_) {
        iVar3 = 0x80;
      }
      else {
        eVar1 = zcl_message_ota_upgrade_query_next_image
                          (packet,(ota_upgrade_query_next_image_rsp_t *)auStack_34);
        iVar3 = CONCAT31(extraout_var,eVar1);
        if (iVar3 == 0) {
          ota_upgrade_download_stop_timer(context);
          eVar1 = ota_upgrade_handle_next_image
                            (context,(ota_upgrade_query_next_image_rsp_t *)auStack_34);
          iVar3 = CONCAT31(extraout_var_00,eVar1);
          if (iVar3 == 0) {
            zcl_message_ota_upgrade_downloading_progress(packet,'\0',auStack_34);
            eVar1 = ota_upgrade_setup_image_block_request(rsp,context,packet);
            return eVar1;
          }
        }
      }
    }
    else {
      iVar3 = 0x95;
    }
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,iVar3);
  return eVar1;
}


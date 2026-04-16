/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_query_next_image_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_cluster_cli_query_next_image_rsp_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,zcl_packet_cnf_ctx_t *rsp_cnf)

{
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  ota_upgrade_downloading_context_t *context;
  undefined3 extraout_var;
  uint uVar3;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar4;
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
    iVar4 = 1;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    iVar4 = 1;
  }
  else {
    context = ota_upgrade_downloading_context_get((packet->header).dst_ep);
    _Var1 = ota_upgrade_downloading_stop_rsp_timeout(context,(packet->header).tsn);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      iVar4 = 0xfe;
    }
    else if (*(context->attr).upgrade_status == '\0') {
      uVar3 = zmsg_get_length(packet->payload);
      af_read_le8(packet->payload,(uint16_t *)((int)&payload.image_size + 2),auStack_34);
      if (auStack_34[0] == '\0') {
        offset_00 = (uint16_t *)((int)&payload.image_size + 2);
        af_read_le16(packet->payload,offset_00,(uint16_t *)(auStack_34 + 2));
        af_read_le16(packet->payload,offset_00,(uint16_t *)&payload);
        af_read_le32(packet->payload,offset_00,(uint32_t *)&payload.image_type);
        af_read_le32(packet->payload,offset_00,&payload.file_version);
      }
      if (uVar3 < payload.image_size._2_2_) {
        iVar4 = 0x80;
      }
      else {
        eVar2 = zcl_message_ota_upgrade_query_next_image
                          (packet,(ota_upgrade_query_next_image_rsp_t *)auStack_34);
        iVar4 = CONCAT31(extraout_var_00,eVar2);
        if (iVar4 == 0) {
          eVar2 = ota_upgrade_handle_next_image
                            (context,(ota_upgrade_query_next_image_rsp_t *)auStack_34);
          iVar4 = CONCAT31(extraout_var_01,eVar2);
          if (iVar4 == 0) {
            zcl_message_ota_upgrade_downloading_progress(packet,'\0',auStack_34);
            ota_upgrade_add_confirm_cb(rsp_cnf,context);
            eVar2 = ota_upgrade_setup_image_block_request(rsp,packet,context);
            return eVar2;
          }
        }
      }
    }
    else {
      iVar4 = 0x95;
    }
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,iVar4);
  return eVar2;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_image_block_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_cluster_cli_image_block_rsp_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,zcl_packet_cnf_ctx_t *rsp_cnf)

{
  undefined1 uVar1;
  int iVar2;
  _Bool _Var3;
  ezb_zcl_status_t eVar4;
  ota_upgrade_downloading_context_t *context;
  undefined3 extraout_var;
  uint uVar5;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint16_t *puVar6;
  uint __size;
  undefined1 auStack_3c [4];
  ota_upgrade_image_block_rsp_t payload;
  uint16_t offset;
  
  payload.field_1._18_2_ = 0;
  auStack_3c = (undefined1  [4])0x0;
  payload.status = '\0';
  payload._1_3_ = 0;
  payload.field_1.wait_for_data.current_time = 0;
  payload.field_1.success.file_version = 0;
  payload.field_1.success.file_offset = 0;
  payload.field_1._12_4_ = 0;
  if (packet == (zcl_packet_t *)0x0) {
    iVar2 = 1;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    iVar2 = 1;
  }
  else {
    context = ota_upgrade_downloading_context_get((packet->header).dst_ep);
    _Var3 = ota_upgrade_downloading_stop_rsp_timeout(context,(packet->header).tsn);
    if (CONCAT31(extraout_var,_Var3) == 0) {
      iVar2 = 0xfe;
    }
    else if (*(context->attr).upgrade_status == '\x01') {
      uVar5 = zmsg_get_length(packet->payload);
      af_read_le8(packet->payload,(uint16_t *)((int)&payload.field_1 + 0x12),auStack_3c);
      if (((uint)auStack_3c & 0xff) == 0) {
        puVar6 = (uint16_t *)((int)&(&payload.field_1.wait_for_data)[1].request_time + 2);
        af_read_le16(packet->payload,puVar6,(uint16_t *)&payload);
        af_read_le16(packet->payload,puVar6,(uint16_t *)&payload.field_0x2);
        af_read_le32(packet->payload,puVar6,(uint32_t *)&payload.field_1);
        af_read_le32(packet->payload,puVar6,&payload.field_1.success.file_version);
        af_read_le8(packet->payload,puVar6,(uint8_t *)&payload.field_1.success.file_offset);
        uVar1 = payload.field_1.success.file_offset._0_1_;
        __size = payload.field_1.success.file_offset & 0xff;
        payload.field_1._12_4_ = calloc(1,__size);
        if (((uint8_t *)payload.field_1._12_4_ == (uint8_t *)0x0) && (__size != 0)) {
          iVar2 = 0x89;
          goto _L0;
        }
        af_read_bytes(packet->payload,(uint16_t *)((int)&payload.field_1 + 0x12),(ushort)(byte)uVar1
                      ,(uint8_t *)payload.field_1._12_4_);
      }
      else if (((uint)auStack_3c & 0xff) == 0x97) {
        puVar6 = (uint16_t *)((int)&(&payload.field_1.wait_for_data)[1].request_time + 2);
        af_read_le32(packet->payload,puVar6,(uint32_t *)&payload);
        af_read_le32(packet->payload,puVar6,(uint32_t *)&payload.field_1);
        af_read_le16(packet->payload,puVar6,(uint16_t *)&payload.field_1.success.file_version);
      }
      if (uVar5 < (ushort)payload.field_1._18_2_) {
        iVar2 = 0x80;
      }
      else if (((uint)auStack_3c & 0xff) == 0) {
        eVar4 = ota_upgrade_handle_image_block_with_success
                          (context,(ota_upgrade_image_block_rsp_t *)auStack_3c);
        if (CONCAT31(extraout_var_00,eVar4) == 0) {
          eVar4 = ota_upgrade_setup_upgrade_end_request(rsp,packet,context,'\0');
          iVar2 = CONCAT31(extraout_var_01,eVar4);
        }
        else {
          if (CONCAT31(extraout_var_00,eVar4) != 0x99) {
            iVar2 = 0xfe;
            goto _L0;
          }
          eVar4 = ota_upgrade_setup_image_block_request(rsp,packet,context);
          iVar2 = CONCAT31(extraout_var_02,eVar4);
        }
        if (iVar2 == 0) {
          ota_upgrade_add_confirm_cb(rsp_cnf,context);
          zcl_message_ota_upgrade_downloading_progress(packet,'\x01',auStack_3c);
          if (*(context->attr).upgrade_status == '\x02') {
            zcl_message_ota_upgrade_downloading_progress(packet,'\x03',auStack_3c);
          }
        }
      }
      else if (((uint)auStack_3c & 0xff) == 0x97) {
        iVar2 = 0x85;
      }
      else {
        iVar2 = 0x95;
      }
    }
    else {
      iVar2 = 0xfe;
    }
  }
_L0:
  if (payload.field_1._12_4_ != 0) {
    mm_free();
  }
  if (iVar2 != 0) {
    iVar2 = zcl_packet_setup_default_response(rsp,packet,iVar2);
  }
  return (ezb_zcl_status_t)iVar2;
}


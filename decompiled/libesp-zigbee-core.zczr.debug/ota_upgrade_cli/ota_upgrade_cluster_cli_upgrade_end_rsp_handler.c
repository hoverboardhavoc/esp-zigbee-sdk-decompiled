/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_upgrade_end_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_cluster_cli_upgrade_end_rsp_handler
          (zcl_packet_t *packet,zcl_packet_t *rsp,zcl_packet_cnf_ctx_t *rsp_cnf)

{
  int iVar1;
  uint16_t *offset_00;
  _Bool _Var2;
  ezb_zcl_status_t eVar3;
  ota_upgrade_downloading_context_t *context;
  undefined3 extraout_var;
  uint uVar4;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined1 auStack_34 [4];
  ota_upgrade_upgrade_end_rsp_t payload;
  uint16_t offset;
  
  payload.upgrade_time._2_2_ = 0;
  auStack_34._0_2_ = 0;
  auStack_34._2_2_ = 0;
  payload.manuf_code = 0;
  payload.image_type = 0;
  payload.file_version = 0;
  payload.current_time = 0;
  if (packet == (zcl_packet_t *)0x0) {
    iVar1 = 1;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    iVar1 = 1;
  }
  else {
    context = ota_upgrade_downloading_context_get((packet->header).dst_ep);
    _Var2 = ota_upgrade_downloading_stop_rsp_timeout(context,(packet->header).tsn);
    if (CONCAT31(extraout_var,_Var2) == 0) {
      iVar1 = 0xfe;
    }
    else if (*(context->attr).upgrade_status == '\x02') {
      uVar4 = zmsg_get_length(packet->payload);
      offset_00 = (uint16_t *)((int)&payload.upgrade_time + 2);
      af_read_le16(packet->payload,offset_00,(uint16_t *)auStack_34);
      af_read_le16(packet->payload,offset_00,(uint16_t *)(auStack_34 + 2));
      af_read_le32(packet->payload,offset_00,(uint32_t *)&payload);
      af_read_le32(packet->payload,offset_00,&payload.file_version);
      af_read_le32(packet->payload,offset_00,&payload.current_time);
      if (uVar4 < payload.upgrade_time._2_2_) {
        iVar1 = 0x80;
      }
      else {
        eVar3 = ota_upgrade_handle_upgrade_end(context,(ota_upgrade_upgrade_end_rsp_t *)auStack_34);
        iVar1 = CONCAT31(extraout_var_00,eVar3);
        if (iVar1 == 0) {
          if (payload.current_time == 0xffffffff) {
            *(context->attr).upgrade_status = '\x03';
          }
          else {
            eVar3 = zcl_message_ota_upgrade_downloading_progress(packet,'\x04',auStack_34);
            iVar1 = CONCAT31(extraout_var_01,eVar3);
            if (iVar1 != 0x96) {
              if (iVar1 == 0x99) {
                *(context->attr).upgrade_status = '\x05';
                eVar3 = ota_upgrade_setup_upgrade_end_request(rsp,packet,context,0x99);
                iVar1 = CONCAT31(extraout_var_02,eVar3);
                if (iVar1 == 0) {
                  ota_upgrade_add_confirm_cb(rsp_cnf,context);
                  goto _L0;
                }
              }
              else {
                if (iVar1 == 0) {
                  *(context->attr).upgrade_status = '\x04';
                  zcl_message_ota_upgrade_downloading_progress(packet,'\x05',auStack_34);
                  ota_upgrade_set_upgrade_status_normal(context);
                  iVar1 = 0;
                  goto _L0;
                }
                ota_upgrade_set_upgrade_status_normal(context);
                iVar1 = 0xfe;
              }
              goto _L0;
            }
            ota_upgrade_set_upgrade_status_normal(context);
            eVar3 = ota_upgrade_setup_upgrade_end_request(rsp,packet,context,0x96);
            iVar1 = CONCAT31(extraout_var_03,eVar3);
            if (iVar1 != 0) goto _L0;
            ota_upgrade_add_confirm_cb(rsp_cnf,context);
          }
_L0:
          if (iVar1 == 0) goto _L0;
        }
      }
    }
    else {
      iVar1 = 0xfe;
    }
  }
_L0:
  iVar1 = zcl_packet_setup_default_response(rsp,packet,iVar1);
_L0:
  return (ezb_zcl_status_t)iVar1;
}


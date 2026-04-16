/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> zcl_message_ota_upgrade_downloading_progress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_ota_upgrade_downloading_progress(zcl_packet_t *packet,uint8_t progress,void *info)

{
  uint uVar1;
  ota_upgrade_downloading_context_t *context;
  undefined3 in_register_0000202d;
  ezb_zcl_cmd_hdr_t *peVar2;
  undefined4 local_40;
  ezb_zcl_ota_upgrade_client_progress_message_t message;
  
  peVar2 = (ezb_zcl_cmd_hdr_t *)CONCAT31(in_register_0000202d,progress);
  local_40 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.progress = EZB_ZCL_OTA_UPGRADE_PROGRESS_START;
  message.in.field_2.receiving.file_offset = 0;
  message.in.field_2.start.file_version = 0;
  message.in.field_2.start.image_size = 0;
  uVar1 = zcl_packet_to_message(&local_40,packet);
  if (uVar1 != 0) goto _L0;
  message._4_4_ = packet;
  message.in.header = peVar2;
  if (peVar2 == (ezb_zcl_cmd_hdr_t *)0x4) {
    if (info == (void *)0x0) goto _L0;
                    /* WARNING: Load size is inaccurate */
    message.in.progress = *info;
    message.in.field_2.receiving.file_offset = *(uint32_t *)((int)info + 4);
  }
  else if (peVar2 < (ezb_zcl_cmd_hdr_t *)0x5) {
    if (peVar2 == (ezb_zcl_cmd_hdr_t *)0x1) {
      if (info == (void *)0x0) goto _L0;
      message.in.progress = *(ezb_zcl_ota_upgrade_progress_t *)((int)info + 0xc);
      message.in.field_2.start.manuf_code._0_1_ = *(undefined1 *)((int)info + 0x10);
      message.in.field_2.start.file_version = *(uint32_t *)((int)info + 0x14);
    }
    else if (peVar2 == (ezb_zcl_cmd_hdr_t *)0x3) {
      if (info == (void *)0x0) goto _L0;
      message.in.progress = *(ezb_zcl_ota_upgrade_progress_t *)((int)info + 4);
      message.in.field_2.receiving.file_offset = *(uint32_t *)((int)info + 8);
    }
    else {
      if (peVar2 != (ezb_zcl_cmd_hdr_t *)0x0) goto _L0;
      if (info == (void *)0x0) goto _L0;
      message.in.progress = *(ezb_zcl_ota_upgrade_progress_t *)((int)info + 2);
      message.in.field_2.receiving.file_offset = *(uint32_t *)((int)info + 8);
      message.in.field_2.start.file_version = *(uint32_t *)((int)info + 0xc);
    }
  }
  else if (peVar2 == (ezb_zcl_cmd_hdr_t *)0x5) {
    if (info == (void *)0x0) goto _L0;
    message.in.progress = *(int *)((int)info + 0xc) - *(int *)((int)info + 8);
  }
  else if (peVar2 == (ezb_zcl_cmd_hdr_t *)0x6) {
    context = ota_upgrade_downloading_context_get((packet->header).dst_ep);
    ota_upgrade_set_upgrade_status_normal(context);
  }
  else {
_L0:
    local_40 = CONCAT31(local_40._1_3_,0x87);
  }
  message.in.field_2.start.image_size._0_1_ = 0xfe;
  zcl_core_action_schedule(0x3a,&local_40);
  if ((message.in.field_2.start.image_size & 0xff) != 0xfe) {
    uVar1 = message.in.field_2.start.image_size & 0xff;
  }
  if ((message.in.header != (ezb_zcl_cmd_hdr_t *)0x6) && (uVar1 == 0x95)) {
    zcl_message_ota_upgrade_downloading_progress(packet,'\x06',(void *)0x0);
    uVar1 = 0xfe;
  }
_L0:
  return (ezb_zcl_status_t)uVar1;
}


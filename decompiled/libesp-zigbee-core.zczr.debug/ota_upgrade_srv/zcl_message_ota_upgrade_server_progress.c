/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> zcl_message_ota_upgrade_server_progress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_ota_upgrade_server_progress(zcl_packet_t *packet,uint8_t progress,void *info,void *out)

{
  uint uVar1;
  undefined3 in_register_0000202d;
  ezb_zcl_cmd_hdr_t *peVar2;
  ezb_zcl_ota_upgrade_server_progress_upgrade_time_t *time;
  undefined4 uStack_4c;
  ezb_zcl_ota_upgrade_server_progress_message_t message;
  
  peVar2 = (ezb_zcl_cmd_hdr_t *)CONCAT31(in_register_0000202d,progress);
  uStack_4c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.progress = EZB_ZCL_OTA_UPGRADE_PROGRESS_START;
  message.in.field_2._0_4_ = 0;
  message.in.field_2.sending.file_version = 0;
  message.in.field_2.start.query.file_version = 0;
  message.in.field_2._12_4_ = 0;
  message.in.field_2.start.policy.file_version = (anon_struct_4_1_72a1db13_for_policy)0;
  message.out.result = '\0';
  message.out._1_1_ = 0;
  message.out.finish.current_time = 0;
  uVar1 = zcl_packet_to_message(&uStack_4c,packet);
  if (uVar1 != 0) goto _L0;
  message._4_4_ = packet;
  message.in.header = peVar2;
  if (peVar2 == (ezb_zcl_cmd_hdr_t *)0x5) {
    if (info == (void *)0x0) goto _L0;
                    /* WARNING: Load size is inaccurate */
    message.in.progress = CONCAT31(message.in.progress._1_3_,*info);
    message.in.progress = CONCAT22(*(undefined2 *)((int)info + 2),(undefined2)message.in.progress);
    message.in.field_2.start.query.short_address = *(undefined2 *)((int)info + 4);
    message.in.field_2.sending.file_version = *(uint32_t *)((int)info + 8);
  }
  else if (peVar2 < (ezb_zcl_cmd_hdr_t *)0x6) {
    if (peVar2 == (ezb_zcl_cmd_hdr_t *)0x0) {
      if (info == (void *)0x0) goto _L0;
      memcpy(&message.in.progress,info,0x14);
    }
    else {
      if (peVar2 != (ezb_zcl_cmd_hdr_t *)0x2) goto _L0;
      if (info == (void *)0x0) goto _L0;
      message.in.progress = *(ezb_zcl_ota_upgrade_progress_t *)((int)info + 2);
      message.in.field_2._0_4_ = *(undefined4 *)((int)info + 8);
      message.in.field_2.sending.file_version = *(uint32_t *)((int)info + 0xc);
      message.in.field_2.start.query.file_version._0_2_ = *(undefined2 *)((int)info + 0x1a);
    }
  }
  else if (peVar2 != (ezb_zcl_cmd_hdr_t *)0x6) {
_L0:
    uStack_4c = CONCAT31(uStack_4c._1_3_,0x87);
  }
  message.in.field_2.start.policy.file_version._0_1_ = 0xfe;
  zcl_core_action_schedule(0x3c,&uStack_4c);
  if (((uint)message.in.field_2.start.policy.file_version & 0xff) != 0xfe) {
    uVar1 = (uint)message.in.field_2.start.policy.file_version & 0xff;
  }
  if ((message.in.header != (ezb_zcl_cmd_hdr_t *)0x6) && (uVar1 == 0x95)) {
    zcl_message_ota_upgrade_server_progress(packet,'\x06',(void *)0x0,(void *)0x0);
    uVar1 = 0xfe;
  }
  if ((message.in.header == (ezb_zcl_cmd_hdr_t *)0x5) && (out != (void *)0x0)) {
    *(undefined2 *)out = message.in.field_2.start.policy.file_version._2_2_;
    *(undefined2 *)((int)out + 2) = message.out._0_2_;
  }
_L0:
  return (ezb_zcl_status_t)uVar1;
}


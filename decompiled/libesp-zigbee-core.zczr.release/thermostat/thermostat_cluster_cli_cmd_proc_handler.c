/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t thermostat_cluster_cli_cmd_proc_handler(void *arg)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint16_t uStack_66;
  undefined1 auStack_64 [2];
  uint16_t offset;
  ezb_zcl_thermostat_get_weekly_schedule_rsp_payload_t payload;
  ezb_zcl_thermostat_get_weekly_schedule_rsp_message_t message;
  zcl_packet_t rsp;
  
  iVar1 = 1;
  memset(&message.out,0,0x28);
  if (arg != (void *)0x0) {
    iVar1 = 1;
    if (((*(byte *)((int)arg + 0x1a) & 8) != 0) &&
       (iVar1 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar1 == 0)) {
      uVar3 = 0x81;
      if (*(char *)((int)arg + 0x20) == '\0') {
        uStack_66 = 0;
        _auStack_64 = 0;
        payload.num_of_trans = '\0';
        payload.day_of_week = '\0';
        payload.mode_for_req = '\0';
        payload._3_1_ = 0;
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_66,(uint8_t *)auStack_64);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_66,(uint8_t *)&offset);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_66,auStack_64 + 1);
        payload._0_4_ = calloc(1,(_auStack_64 & 0xff) * 6);
        uVar2 = 0;
        uVar3 = 0x89;
        if ((void *)payload._0_4_ != (void *)0x0) {
          while( true ) {
            if ((_auStack_64 & 0xff) <= uVar2) break;
            iVar1 = uVar2 * 6;
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_66,
                         (uint16_t *)(payload._0_4_ + iVar1));
            if ((_auStack_64 & 0x10000) == 0) {
              *(undefined2 *)(payload._0_4_ + iVar1 + 2) = 0;
            }
            else {
              af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_66,
                           (uint16_t *)(payload._0_4_ + iVar1 + 2));
            }
            if ((_auStack_64 & 0x20000) == 0) {
              *(undefined2 *)(payload._0_4_ + iVar1 + 4) = 0;
            }
            else {
              af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_66,
                           (uint16_t *)(payload._0_4_ + iVar1 + 4));
            }
            uVar2 = uVar2 + 1 & 0xff;
          }
          uVar2 = zmsg_get_length();
          uVar3 = 0x80;
          if (uStack_66 <= uVar2) {
            payload.transitions = (ezb_zcl_thermostat_weekly_schedule_transition_t *)0x0;
            message.info.status = '\0';
            message.info.dst_ep = '\0';
            message.info.cluster_id = 0;
            message.info.cluster_role = '\0';
            message.info._5_1_ = 0;
            message._6_2_ = 0;
            message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
            message.in.payload = (ezb_zcl_thermostat_get_weekly_schedule_rsp_payload_t *)0x0;
            uVar3 = zcl_packet_to_message(&payload.transitions,arg,0x80);
            if (uVar3 == 0) {
              message.in.payload =
                   (ezb_zcl_thermostat_get_weekly_schedule_rsp_payload_t *)
                   CONCAT31(message.in.payload._1_3_,0xfe);
              message._4_4_ = arg;
              message.in.header = (ezb_zcl_cmd_hdr_t *)auStack_64;
              zcl_core_action_schedule(0x39,&payload.transitions,0);
              if (((uint)message.in.payload & 0xff) != 0xfe) {
                uVar3 = (uint)message.in.payload & 0xff;
              }
            }
          }
        }
      }
      iVar1 = zcl_packet_setup_default_response(&message.out,arg,uVar3);
      if (iVar1 == 0) {
        zcl_packet_send(&message.out,0);
      }
      else {
        zcl_packet_free(&message.out);
      }
    }
  }
  return (ezb_zcl_status_t)iVar1;
}


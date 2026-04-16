/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_get_weekly_schedule_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
thermostat_get_weekly_schedule_rsp_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint16_t *offset_00;
  int iVar1;
  uint uVar2;
  ezb_zcl_status_t eVar3;
  undefined1 auStack_2c [4];
  ezb_zcl_thermostat_get_weekly_schedule_rsp_payload_t payload;
  uint16_t offset;
  
  payload.transitions._2_2_ = 0;
  auStack_2c = (undefined1  [4])0x0;
  payload.num_of_trans = '\0';
  payload.day_of_week = '\0';
  payload.mode_for_req = '\0';
  payload._3_1_ = 0;
  if (packet == (zcl_packet_t *)0x0) {
    eVar3 = 0x80;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    eVar3 = 0x80;
  }
  else {
    offset_00 = (uint16_t *)((int)&payload.transitions + 2);
    af_read_le8(packet->payload,offset_00,auStack_2c);
    af_read_le8(packet->payload,offset_00,auStack_2c + 2);
    af_read_le8(packet->payload,offset_00,auStack_2c + 1);
    payload._0_4_ = calloc(1,((uint)auStack_2c & 0xff) * 6);
    if ((void *)payload._0_4_ == (void *)0x0) {
      eVar3 = 0x89;
    }
    else {
      for (uVar2 = 0; uVar2 < ((uint)auStack_2c & 0xff); uVar2 = uVar2 + 1 & 0xff) {
        iVar1 = uVar2 * 6;
        af_read_le16(packet->payload,(uint16_t *)((int)&payload.transitions + 2),
                     (uint16_t *)(payload._0_4_ + iVar1));
        if (((uint)auStack_2c & 0x10000) == 0) {
          *(undefined2 *)(payload._0_4_ + iVar1 + 2) = 0;
        }
        else {
          af_read_le16(packet->payload,(uint16_t *)((int)&payload.transitions + 2),
                       (uint16_t *)(payload._0_4_ + iVar1 + 2));
        }
        if (((uint)auStack_2c & 0x20000) == 0) {
          *(undefined2 *)(payload._0_4_ + iVar1 + 4) = 0;
        }
        else {
          af_read_le16(packet->payload,(uint16_t *)((int)&payload.transitions + 2),
                       (uint16_t *)(payload._0_4_ + iVar1 + 4));
        }
      }
      uVar2 = zmsg_get_length(packet->payload);
      if (uVar2 < payload.transitions._2_2_) {
        eVar3 = 0x80;
      }
      else {
        eVar3 = zcl_message_thermostat_get_weekly_schedule_response
                          (packet,(ezb_zcl_thermostat_get_weekly_schedule_rsp_payload_t *)auStack_2c
                          );
      }
    }
  }
  eVar3 = zcl_packet_setup_default_response(rsp,packet,eVar3);
  return eVar3;
}


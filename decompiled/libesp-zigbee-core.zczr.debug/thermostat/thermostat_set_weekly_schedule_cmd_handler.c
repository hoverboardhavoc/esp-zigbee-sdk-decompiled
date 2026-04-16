/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_set_weekly_schedule_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t thermostat_set_weekly_schedule_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  uint16_t *offset_00;
  int iVar1;
  uint uVar2;
  ezb_zcl_status_t eVar3;
  uint uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 auStack_2c [4];
  ezb_zcl_thermostat_set_weekly_schedule_payload_t payload;
  uint16_t offset;
  
  payload.transitions._2_2_ = 0;
  auStack_2c = (undefined1  [4])0x0;
  payload.num_of_trans = '\0';
  payload.day_of_week = '\0';
  payload.mode_for_req = '\0';
  payload._3_1_ = 0;
  ep_id = (packet->header).dst_ep;
  uVar4 = zmsg_get_length(packet->payload);
  offset_00 = (uint16_t *)((int)&payload.transitions + 2);
  af_read_le8(packet->payload,offset_00,auStack_2c);
  af_read_le8(packet->payload,offset_00,auStack_2c + 1);
  af_read_le8(packet->payload,offset_00,auStack_2c + 2);
  if (auStack_2c[0] < 0xb) {
    payload._0_4_ = calloc(1,0x3c);
    if ((void *)payload._0_4_ == (void *)0x0) {
      iVar1 = 0x89;
    }
    else {
      for (uVar2 = 0; (payload.transitions._2_2_ < uVar4 && (uVar2 < ((uint)auStack_2c & 0xff)));
          uVar2 = uVar2 + 1 & 0xff) {
        iVar1 = uVar2 * 6;
        af_read_le16(packet->payload,(uint16_t *)((int)&payload.transitions + 2),
                     (uint16_t *)(payload._0_4_ + iVar1));
        if (((uint)auStack_2c & 0x10000) != 0) {
          af_read_le16(packet->payload,(uint16_t *)((int)&payload.transitions + 2),
                       (uint16_t *)(payload._0_4_ + iVar1 + 2));
        }
        if (((uint)auStack_2c & 0x20000) != 0) {
          af_read_le16(packet->payload,(uint16_t *)((int)&payload.transitions + 2),
                       (uint16_t *)(payload._0_4_ + iVar1 + 4));
        }
      }
      eVar3 = zcl_message_thermostat_set_weekly_schedule
                        (packet,(ezb_zcl_thermostat_set_weekly_schedule_payload_t *)auStack_2c);
      iVar1 = CONCAT31(extraout_var,eVar3);
      if (iVar1 == 0) {
        eVar3 = thermostat_weekly_schedule_add_transitions
                          (ep_id,(ezb_zcl_thermostat_set_weekly_schedule_payload_t *)auStack_2c);
        iVar1 = CONCAT31(extraout_var_00,eVar3);
        if (iVar1 == 0) {
          thermostat_weekly_schedule_loop_start(ep_id);
        }
      }
    }
  }
  else {
    iVar1 = 0x87;
  }
  if (payload._0_4_ != 0) {
    mm_free();
  }
  eVar3 = zcl_packet_setup_default_response(rsp,packet,iVar1);
  return eVar3;
}


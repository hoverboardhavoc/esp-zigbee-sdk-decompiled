/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> ezb_zcl_thermostat_set_weekly_schedule_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_thermostat_set_weekly_schedule_cmd_req
                    (ezb_zcl_thermostat_set_weekly_schedule_cmd_t *cmd_req)

{
  int iVar1;
  ezb_zcl_thermostat_weekly_schedule_transition_t *peVar2;
  uint uVar3;
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [4];
  zcl_packet_t packet;
  
  memset(auStack_48,0,0x28);
  if ((cmd_req == (ezb_zcl_thermostat_set_weekly_schedule_cmd_t *)0x0) ||
     (iVar1 = zcl_packet_init(auStack_48,0), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_60,cmd_req,10);
    iVar1 = zcl_cmd_to_packet(auStack_48,1,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,0x201);
    if ((((iVar1 == 0) &&
         (iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).num_of_trans),
         iVar1 == 0)) &&
        (iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).day_of_week), iVar1 == 0)
        ) && (iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).mode_for_req),
             iVar1 == 0)) {
      uVar3 = 0;
      do {
        if (((uint)(cmd_req->payload).num_of_trans <= (uVar3 & 0xff)) ||
           (peVar2 = (cmd_req->payload).transitions,
           peVar2 == (ezb_zcl_thermostat_weekly_schedule_transition_t *)0x0)) break;
        iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,peVar2[uVar3].start_time);
        if (((iVar1 != 0) ||
            ((((cmd_req->payload).mode_for_req & 1) != 0 &&
             (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,
                                       (cmd_req->payload).transitions[uVar3].heat_setpoint),
             iVar1 != 0)))) ||
           ((((cmd_req->payload).mode_for_req & 2) != 0 &&
            (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,
                                      (cmd_req->payload).transitions[uVar3].cool_setpoint),
            iVar1 != 0)))) goto _L0;
        uVar3 = uVar3 + 1;
      } while (uVar3 != 10);
      zcl_packet_send(auStack_48,&(cmd_req->cmd_ctrl).cnf_ctx);
      iVar1 = zcl_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar1;
}


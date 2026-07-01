/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> window_covering.o -> ezb_zcl_window_covering_movement_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_window_covering_movement_cmd_req(ezb_zcl_window_covering_movement_cmd_t *cmd_req)

{
  int iVar1;
  undefined4 uVar2;
  ezb_zcl_window_covering_server_cmd_id_t eVar3;
  undefined1 auStack_50 [22];
  ezb_zcl_window_covering_cmd_payload_t eStack_3a;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if (cmd_req == (ezb_zcl_window_covering_movement_cmd_t *)0x0) {
    iVar1 = -1;
    goto _L0;
  }
  iVar1 = zcl_packet_init(auStack_38,0);
  if (iVar1 != 0) goto _L0;
  memcpy(auStack_50,cmd_req,10);
  iVar1 = zcl_cmd_to_packet(auStack_38,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,
                            (char)cmd_req->cmd_id,0x102);
  if (iVar1 != 0) goto _L0;
  eVar3 = cmd_req->cmd_id;
  uVar2 = 1;
  if (eVar3 == EZB_ZCL_CMD_WINDOW_COVERING_GO_TO_LIFT_PERCENTAGE_ID) {
_L0:
    eStack_3a.lift_percentage = (cmd_req->payload).lift_percentage;
_L0:
    iVar1 = zmsg_append_bytes(packet._32_4_,uVar2,&eStack_3a);
    if (iVar1 != 0) goto _L0;
  }
  else {
    if (EZB_ZCL_CMD_WINDOW_COVERING_GO_TO_LIFT_PERCENTAGE_ID < eVar3) {
      if (eVar3 != EZB_ZCL_CMD_WINDOW_COVERING_GO_TO_TILT_VALUE_ID) {
        if (eVar3 != EZB_ZCL_CMD_WINDOW_COVERING_GO_TO_TILT_PERCENTAGE_ID) goto _L114;
        goto _L0;
      }
      eStack_3a = cmd_req->payload;
      uVar2 = 2;
      goto _L0;
    }
    uVar2 = 2;
    if (EZB_ZCL_CMD_WINDOW_COVERING_STOP_ID < eVar3) {
      if (eVar3 != EZB_ZCL_CMD_WINDOW_COVERING_GO_TO_LIFT_VALUE_ID) {
_L114:
        iVar1 = 2;
        goto _L0;
      }
      eStack_3a = cmd_req->payload;
      goto _L0;
    }
  }
  zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
  iVar1 = zcl_status_to_err();
  if (iVar1 == 0) {
    return 0;
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar1;
}


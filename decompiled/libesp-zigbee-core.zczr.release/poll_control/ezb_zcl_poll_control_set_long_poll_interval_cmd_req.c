/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> ezb_zcl_poll_control_set_long_poll_interval_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_poll_control_set_long_poll_interval_cmd_req
                    (ezb_zcl_poll_control_set_long_poll_interval_cmd_t *cmd_req)

{
  ezb_err_t eVar1;
  int iVar2;
  undefined1 auStack_50 [20];
  uint32_t uStack_3c;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_req == (ezb_zcl_poll_control_set_long_poll_interval_cmd_t *)0x0) ||
     (iVar2 = zcl_packet_init(auStack_38,0), iVar2 != 0)) {
_L0:
    eVar1 = 0;
  }
  else {
    memcpy(auStack_50,cmd_req,10);
    eVar1 = zcl_cmd_to_packet(auStack_38,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,2,0x20);
    if (eVar1 == 0) {
      uStack_3c = cmd_req->long_poll_interval;
      eVar1 = zmsg_append_bytes(packet._32_4_,4,&uStack_3c);
      if (eVar1 == 0) {
        zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
        eVar1 = zcl_status_to_err();
        if (eVar1 == 0) goto _L0;
      }
    }
    zcl_packet_free(auStack_38);
  }
  return eVar1;
}


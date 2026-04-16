/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarms_send_cmd_no_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t alarms_send_cmd_no_payload(ezb_zcl_alarms_cmd_with_no_payload_t *cmd,uint8_t cmd_id)

{
  int iVar1;
  int iVar2;
  undefined3 in_register_0000202d;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if (cmd == (ezb_zcl_alarms_cmd_with_no_payload_t *)0x0) {
    iVar1 = 2;
  }
  else {
    iVar2 = zcl_packet_init(auStack_38,0);
    iVar1 = -1;
    if (iVar2 == 0) {
      memcpy(auStack_50,cmd,10);
      iVar1 = zcl_cmd_to_packet(auStack_38,0,0,(cmd->cmd_ctrl).dis_default_rsp,0,
                                CONCAT31(in_register_0000202d,cmd_id),9);
      if (iVar1 == 0) {
        zcl_packet_send(auStack_38,&(cmd->cmd_ctrl).cnf_ctx);
        iVar1 = zcl_status_to_err();
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_disc_cmd_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_disc_cmd_cmd_req(zcl_disc_cmd_cmd_t *cmd_req)

{
  uint8_t uVar1;
  uint16_t uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_req == (zcl_disc_cmd_cmd_t *)0x0) ||
     (iVar3 = zcl_packet_init(auStack_38,*(uint *)&(cmd_req->cmd_ctrl).fc & 1), iVar3 != 0)) {
    iVar3 = -1;
  }
  else {
    uVar1 = (cmd_req->payload).is_recv;
    uVar4 = *(uint *)&(cmd_req->cmd_ctrl).fc;
    uVar2 = (cmd_req->cmd_ctrl).manuf_code;
    memcpy(auStack_50,cmd_req,10);
    iVar3 = zcl_cmd_to_packet(auStack_38,0,uVar4 & 1,uVar4 >> 1 & 1,uVar4 >> 2 & 1,uVar2,
                              (uVar1 == '\0') * '\x02' + '\x11',(cmd_req->cmd_ctrl).cluster_id);
    if (((iVar3 == 0) &&
        (iVar3 = zmsg_append_u8((zmsg_t *)packet._32_4_,(uint8_t)(cmd_req->payload).start_cmd_id),
        iVar3 == 0)) &&
       (iVar3 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).max_cmd_number),
       iVar3 == 0)) {
      zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
      iVar3 = zcl_status_to_err();
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar3;
}


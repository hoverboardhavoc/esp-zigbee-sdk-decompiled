/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_disc_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_disc_attr_cmd_req(zcl_disc_attr_cmd_t *cmd_req)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_req == (zcl_disc_attr_cmd_t *)0x0) ||
     (iVar1 = zcl_packet_init(auStack_38,*(uint *)&(cmd_req->cmd_ctrl).fc & 1), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_50,cmd_req,10);
    uVar2 = *(uint *)&(cmd_req->cmd_ctrl).fc;
    iVar1 = zcl_cmd_to_packet(auStack_38,0,uVar2 & 1,uVar2 >> 1 & 1,uVar2 >> 2 & 1,
                              (cmd_req->cmd_ctrl).manuf_code,0xc,(cmd_req->cmd_ctrl).cluster_id);
    if (((iVar1 == 0) &&
        (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).start_attr_id),
        iVar1 == 0)) &&
       (iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).max_attr_number),
       iVar1 == 0)) {
      zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
      iVar1 = zcl_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}


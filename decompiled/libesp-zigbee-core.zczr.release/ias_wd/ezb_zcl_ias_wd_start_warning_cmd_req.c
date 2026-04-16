/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_wd.o -> ezb_zcl_ias_wd_start_warning_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ias_wd_start_warning_cmd_req(ezb_zcl_ias_wd_start_warning_cmd_t *cmd_req)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_50 [22];
  uint16_t uStack_3a;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if (cmd_req == (ezb_zcl_ias_wd_start_warning_cmd_t *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_38,0);
    if (iVar1 == 0) {
      memcpy(auStack_50,cmd_req,10);
      iVar1 = zcl_cmd_to_packet(auStack_38,1,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,0,0x502);
      if (iVar1 == 0) {
        uVar2 = *(uint *)&cmd_req->payload;
        uStack_3a = CONCAT11(uStack_3a._1_1_,
                             (byte)(uVar2 >> 2) & 0xc | (byte)((uVar2 & 0xf) << 4) |
                             (byte)(uVar2 >> 6) & 3);
        iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
        if (iVar1 == 0) {
          uStack_3a = (cmd_req->payload).duration;
          iVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
          if (iVar1 == 0) {
            uStack_3a = CONCAT11(uStack_3a._1_1_,(cmd_req->payload).strobe_duty_cycle);
            iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
            if (iVar1 == 0) {
              uStack_3a = CONCAT11(uStack_3a._1_1_,(cmd_req->payload).strobe_level);
              iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
              if (iVar1 == 0) {
                zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
                iVar1 = zcl_status_to_err();
                if (iVar1 == 0) {
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}


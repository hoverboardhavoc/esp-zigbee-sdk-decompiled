/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_read_report_config_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t zcl_read_report_config_cmd_req(zcl_read_report_config_cmd_t *cmd_req)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  zcl_read_report_config_record_t *record;
  ezb_zcl_read_report_config_record_t *peVar4;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((((cmd_req == (zcl_read_report_config_cmd_t *)0x0) || ((cmd_req->payload).record_number == 0))
      || ((cmd_req->payload).record_field == (ezb_zcl_read_report_config_record_t *)0x0)) ||
     (iVar1 = zcl_packet_init(auStack_38,*(uint *)&(cmd_req->cmd_ctrl).fc & 1), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_50,cmd_req,10);
    uVar3 = *(uint *)&(cmd_req->cmd_ctrl).fc;
    iVar2 = zcl_cmd_to_packet(auStack_38,0,uVar3 & 1,uVar3 >> 1 & 1,uVar3 >> 2 & 1,
                              (cmd_req->cmd_ctrl).manuf_code,8,(cmd_req->cmd_ctrl).cluster_id);
    iVar1 = iVar2;
    if (iVar2 == 0) {
      while ((iVar2 < (int)(uint)(cmd_req->payload).record_number &&
             (peVar4 = (cmd_req->payload).record_field,
             peVar4 != (ezb_zcl_read_report_config_record_t *)0x0))) {
        peVar4 = peVar4 + iVar2;
        iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,peVar4->report_direction);
        if ((iVar1 != 0) ||
           (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,peVar4->attr_id), iVar1 != 0))
        goto _L0;
        iVar2 = iVar2 + 1;
      }
      zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
      iVar1 = zcl_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar1;
}


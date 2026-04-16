/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_config_report_cmd_req(zcl_config_report_cmd_t *cmd_req)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint16_t uVar4;
  zcl_config_report_record_t *record;
  ezb_zcl_config_report_record_t *peVar5;
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [4];
  zcl_packet_t packet;
  
  memset(auStack_48,0,0x28);
  if ((((cmd_req == (zcl_config_report_cmd_t *)0x0) || ((cmd_req->payload).record_number == 0)) ||
      ((cmd_req->payload).record_field == (ezb_zcl_config_report_record_t *)0x0)) ||
     (iVar1 = zcl_packet_init(auStack_48,*(uint *)&(cmd_req->cmd_ctrl).fc & 1), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_60,cmd_req,10);
    uVar3 = *(uint *)&(cmd_req->cmd_ctrl).fc;
    iVar1 = zcl_cmd_to_packet(auStack_48,0,uVar3 & 1,uVar3 >> 1 & 1,uVar3 >> 2 & 1,
                              (cmd_req->cmd_ctrl).manuf_code,6,(cmd_req->cmd_ctrl).cluster_id);
    if (iVar1 == 0) {
      iVar2 = 0;
      while ((iVar2 < (int)(uint)(cmd_req->payload).record_number &&
             (peVar5 = (cmd_req->payload).record_field,
             peVar5 != (ezb_zcl_config_report_record_t *)0x0))) {
        peVar5 = peVar5 + iVar2;
        iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,peVar5->direction);
        if ((iVar1 != 0) ||
           (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,peVar5->attr_id), iVar1 != 0))
        goto _L0;
        if (peVar5->direction == '\0') {
          iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(peVar5->field_2).client.attr_type);
          if (((iVar1 != 0) ||
              (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,
                                        (peVar5->field_2).client.min_interval), iVar1 != 0)) ||
             (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(peVar5->field_2).client.max_interval
                                      ), iVar1 != 0)) goto _L0;
          iVar1 = zcl_attr_type_is_analog((peVar5->field_2).client.attr_type);
          if (iVar1 != 0) {
            uVar4 = (peVar5->field_2).client.max_interval;
            if (uVar4 == 0) {
              uVar4 = (peVar5->field_2).client.min_interval;
            }
            if (uVar4 == 0xffff) {
              iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,'\0');
            }
            else {
              iVar1 = zcl_packet_append_variable_attr_value
                                (packet._32_4_,(peVar5->field_2).client.attr_type,
                                 (undefined1 *)((int)&peVar5->field_2 + 8));
            }
            goto _L0;
          }
        }
        else {
          iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(peVar5->field_2).server.timeout);
_L0:
          if (iVar1 != 0) goto _L0;
        }
        iVar2 = iVar2 + 1;
      }
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


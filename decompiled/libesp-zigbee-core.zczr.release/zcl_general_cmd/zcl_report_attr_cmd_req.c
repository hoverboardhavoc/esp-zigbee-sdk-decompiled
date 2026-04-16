/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_report_attr_cmd_req(zcl_report_attr_cmd_t *cmd_req)

{
  anon_struct_1_3_9083e743_for_fc aVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint16_t *puVar5;
  uint uVar6;
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [4];
  zcl_packet_t packet;
  
  memset(auStack_48,0,0x28);
  if ((cmd_req == (zcl_report_attr_cmd_t *)0x0) ||
     (iVar3 = zcl_packet_init(auStack_48,*(uint *)&(cmd_req->cmd_ctrl).fc & 1), iVar3 != 0)) {
    iVar3 = -1;
  }
  else {
    aVar1 = (cmd_req->cmd_ctrl).fc;
    uVar2 = (cmd_req->cmd_ctrl).manuf_code;
    memcpy(auStack_60,cmd_req,10);
    uVar6 = *(uint *)&(cmd_req->cmd_ctrl).fc;
    iVar3 = zcl_cmd_to_packet(auStack_48,0,uVar6 & 1,uVar6 >> 1 & 1,uVar6 >> 2 & 1,uVar2,10,
                              (cmd_req->cmd_ctrl).cluster_id);
    if (iVar3 == 0) {
      iVar4 = zcl_reporting_info_find
                        ((cmd_req->cmd_ctrl).src_ep,(cmd_req->cmd_ctrl).cluster_id,
                         (((byte)aVar1 & 2) == 0) + '\x01',(cmd_req->payload).attr_id,
                         -((byte)aVar1 & 1) & uVar2);
      if ((iVar4 == 0) ||
         (iVar3 = zcl_get_attr_desc(*(undefined1 *)(iVar4 + 1),*(undefined2 *)(iVar4 + 4),
                                    *(undefined1 *)(iVar4 + 8),*(undefined2 *)(iVar4 + 6),
                                    *(undefined2 *)(iVar4 + 0x30)), iVar3 == 0)) {
        iVar3 = 5;
      }
      else if (((*(byte *)(iVar3 + 3) & 4) == 0) ||
              (iVar3 = zcl_attr_type_is_reportable(*(undefined1 *)(iVar3 + 2)), iVar3 == 0)) {
        iVar3 = 6;
      }
      else {
        do {
          puVar5 = (uint16_t *)
                   zcl_get_attr_desc(*(undefined1 *)(iVar4 + 1),*(undefined2 *)(iVar4 + 4),
                                     *(undefined1 *)(iVar4 + 8),*(undefined2 *)(iVar4 + 6),
                                     *(undefined2 *)(iVar4 + 0x30));
          zcl_reporting_sync_attr_change(iVar4);
          iVar3 = zmsg_append_le16((zmsg_t *)packet._32_4_,*puVar5);
          if (((iVar3 != 0) ||
              (iVar3 = zmsg_append_u8((zmsg_t *)packet._32_4_,(uint8_t)puVar5[1]), iVar3 != 0)) ||
             (iVar3 = zcl_packet_append_variable_attr_value
                                (packet._32_4_,(char)puVar5[1],*(undefined4 *)(puVar5 + 4)),
             iVar3 != 0)) goto _L0;
          iVar4 = zcl_reporting_find_next_ready_report(iVar4);
        } while (iVar4 != 0);
        zcl_packet_send(auStack_48,&(cmd_req->cmd_ctrl).cnf_ctx);
        iVar3 = zcl_status_to_err();
        if (iVar3 == 0) {
          return 0;
        }
      }
    }
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar3;
}


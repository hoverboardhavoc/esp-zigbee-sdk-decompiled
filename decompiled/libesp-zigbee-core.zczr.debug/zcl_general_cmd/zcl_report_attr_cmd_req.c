/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_report_attr_cmd_req(zcl_report_attr_cmd_t *cmd_req)

{
  anon_struct_1_3_9083e743_for_fc aVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint16_t uVar7;
  undefined2 uStack_4a;
  undefined4 uStack_48;
  zcl_packet_t packet;
  
  uStack_48 = 0;
  packet.header.src_addr._0_4_ = 0;
  packet.header.src_addr.u._2_4_ = 0;
  packet.header._8_4_ = 0;
  packet.header.dst_addr.u._0_2_ = 0;
  packet.header.dst_addr.u._2_2_ = 0;
  packet.header.dst_addr.u._4_4_ = 0;
  packet.header.src_ep = '\0';
  packet.header.dst_ep = '\0';
  packet.header.cluster_id = 0;
  packet.header.profile_id = 0;
  packet.header.fc = '\0';
  packet.header._27_1_ = 0;
  packet.header.manuf_code = 0;
  packet.header.tsn = '\0';
  packet.header.rssi = '\0';
  packet.header.cmd_id = '\0';
  packet.header._33_1_ = 0;
  packet._34_2_ = 0;
  if (cmd_req == (zcl_report_attr_cmd_t *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = zcl_packet_init(&uStack_48,*(uint *)&(cmd_req->cmd_ctrl).fc & 1);
    if (iVar2 == 0) {
      aVar1 = (cmd_req->cmd_ctrl).fc;
      if (((byte)aVar1 & 2) == 0) {
        uVar6 = 2;
      }
      else {
        uVar6 = 1;
      }
      if (((byte)aVar1 & 1) == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = (cmd_req->cmd_ctrl).manuf_code;
      }
      uVar5 = *(uint *)&(cmd_req->cmd_ctrl).fc;
      iVar2 = zcl_cmd_to_packet(&uStack_48,0,uVar5 & 1,uVar5 >> 1 & 1,uVar5 >> 2 & 1,
                                (cmd_req->cmd_ctrl).manuf_code,10,(cmd_req->cmd_ctrl).cluster_id);
      if (iVar2 == 0) {
        iVar3 = zcl_reporting_info_find
                          ((cmd_req->cmd_ctrl).src_ep,(cmd_req->cmd_ctrl).cluster_id,uVar6,
                           (cmd_req->payload).attr_id,uVar7);
        if (iVar3 == 0) {
          iVar2 = 5;
        }
        else {
          iVar2 = zcl_get_attr_desc(*(undefined1 *)(iVar3 + 1),*(undefined2 *)(iVar3 + 4),
                                    *(undefined1 *)(iVar3 + 8),*(undefined2 *)(iVar3 + 6),
                                    *(undefined2 *)(iVar3 + 0x30));
          if (iVar2 == 0) {
            iVar2 = 5;
          }
          else if ((*(byte *)(iVar2 + 3) & 4) == 0) {
            iVar2 = 6;
          }
          else {
            iVar2 = zcl_attr_type_is_reportable(*(undefined1 *)(iVar2 + 2));
            if (iVar2 == 0) {
              iVar2 = 6;
            }
            else {
              for (; iVar3 != 0; iVar3 = zcl_reporting_find_next_ready_report(iVar3)) {
                puVar4 = (undefined2 *)
                         zcl_get_attr_desc(*(undefined1 *)(iVar3 + 1),*(undefined2 *)(iVar3 + 4),
                                           *(undefined1 *)(iVar3 + 8),*(undefined2 *)(iVar3 + 6),
                                           *(undefined2 *)(iVar3 + 0x30));
                zcl_reporting_sync_attr_change(iVar3);
                uStack_4a = *puVar4;
                iVar2 = zmsg_append_bytes(packet._32_4_,2,&uStack_4a);
                if (iVar2 != 0) goto _L0;
                uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)(puVar4 + 1));
                iVar2 = zmsg_append_bytes(packet._32_4_,1,&uStack_4a);
                if ((iVar2 != 0) ||
                   (iVar2 = zcl_packet_append_variable_attr_value
                                      (packet._32_4_,*(undefined1 *)(puVar4 + 1),
                                       *(undefined4 *)(puVar4 + 4)), iVar2 != 0)) goto _L0;
              }
              zcl_packet_send(&uStack_48,&(cmd_req->cmd_ctrl).cnf_ctx);
              iVar2 = zcl_status_to_err();
_L0:
              if (iVar2 == 0) {
                return 0;
              }
            }
          }
        }
      }
    }
    else {
      iVar2 = -1;
    }
  }
  zcl_packet_free(&uStack_48);
  return iVar2;
}


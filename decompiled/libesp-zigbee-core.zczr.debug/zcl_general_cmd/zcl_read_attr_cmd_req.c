/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_read_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_read_attr_cmd_req(zcl_read_attr_cmd_t *cmd_req)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint16_t *puVar4;
  uint16_t uStack_3a;
  undefined4 uStack_38;
  zcl_packet_t packet;
  
  uStack_38 = 0;
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
  if (cmd_req == (zcl_read_attr_cmd_t *)0x0) {
    iVar1 = 2;
  }
  else if ((cmd_req->payload).attr_number == '\0') {
    iVar1 = 2;
  }
  else if ((cmd_req->payload).attr_field == (uint16_t *)0x0) {
    iVar1 = 2;
  }
  else {
    iVar1 = zcl_packet_init(&uStack_38,*(uint *)&(cmd_req->cmd_ctrl).fc & 1);
    if (iVar1 == 0) {
      uVar3 = *(uint *)&(cmd_req->cmd_ctrl).fc;
      iVar2 = zcl_cmd_to_packet(&uStack_38,0,uVar3 & 1,uVar3 >> 1 & 1,uVar3 >> 2 & 1,
                                (cmd_req->cmd_ctrl).manuf_code,0,(cmd_req->cmd_ctrl).cluster_id);
      iVar1 = iVar2;
      if (iVar2 == 0) {
        while ((iVar2 < (int)(uint)(cmd_req->payload).attr_number &&
               (puVar4 = (cmd_req->payload).attr_field, puVar4 != (uint16_t *)0x0))) {
          uStack_3a = puVar4[iVar2];
          iVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
          if (iVar1 != 0) goto _L0;
          iVar2 = iVar2 + 1;
        }
        zcl_packet_send(&uStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
        iVar1 = zcl_status_to_err();
_L0:
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    else {
      iVar1 = -1;
    }
  }
  zcl_packet_free(&uStack_38);
  return iVar1;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_device_info_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_touchlink_device_info_rsp(zcl_touchlink_device_info_rsp_t *cmd_rsp)

{
  int iVar1;
  uint uVar2;
  uint32_t uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [4];
  zcl_packet_t packet;
  
  auStack_48 = (undefined1  [4])0x0;
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
  if (cmd_rsp == (zcl_touchlink_device_info_rsp_t *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_48,0);
    if (iVar1 == 0) {
      iVar1 = zcl_touchlink_cmd_to_packet
                        ((zcl_packet_t *)auStack_48,'\x01','\x03',(ezb_address_t *)cmd_rsp);
      if (iVar1 == 0) {
        packet.header.fc = (cmd_rsp->cmd_ctrl).tsn;
        packet.header._20_4_ = packet.header._20_4_ | 0x200000;
        uStack_50 = cmd_rsp->transaction_id;
        iVar1 = zmsg_append_bytes(packet._32_4_,4,&uStack_50);
        if (iVar1 == 0) {
          uStack_50 = CONCAT31(uStack_50._1_3_,cmd_rsp->n_sub_devices);
          iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_50);
          if (iVar1 == 0) {
            uStack_50 = CONCAT31(uStack_50._1_3_,cmd_rsp->start_index);
            iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_50);
            if (iVar1 == 0) {
              uStack_50 = CONCAT31(uStack_50._1_3_,cmd_rsp->n_records);
              iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_50);
              uVar2 = 0;
              if (iVar1 == 0) {
                for (; uVar2 < cmd_rsp->n_records; uVar2 = uVar2 + 1 & 0xff) {
                  uStack_50 = *(uint32_t *)&cmd_rsp->records[uVar2].ieee_addr.field_0;
                  uStack_4c = *(undefined4 *)((int)&cmd_rsp->records[uVar2].ieee_addr.field_0 + 4);
                  iVar1 = zmsg_append_bytes(packet._32_4_,8,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT31(uStack_50._1_3_,cmd_rsp->records[uVar2].ep_id);
                  iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT22(uStack_50._2_2_,cmd_rsp->records[uVar2].profile_id);
                  iVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT22(uStack_50._2_2_,cmd_rsp->records[uVar2].device_id);
                  iVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT31(uStack_50._1_3_,cmd_rsp->records[uVar2].version);
                  iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT31(uStack_50._1_3_,cmd_rsp->records[uVar2].n_group_ids);
                  iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                  uStack_50 = CONCAT31(uStack_50._1_3_,cmd_rsp->records[uVar2].sort);
                  iVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_50);
                  if (iVar1 != 0) goto _L0;
                }
                zcl_packet_intrp_send(auStack_48,&cmd_rsp->cnf_ctx);
                iVar1 = zcl_status_to_err();
_L0:
                if (iVar1 == 0) {
                  return 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar1 = -1;
    }
  }
  zcl_packet_free(auStack_48);
  return iVar1;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_device_info_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_touchlink_device_info_rsp(zcl_touchlink_device_info_rsp_t *cmd_rsp)

{
  ezb_err_t eVar1;
  int iVar2;
  ezb_err_t eVar3;
  uint uVar4;
  undefined1 auStack_60 [16];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [4];
  zcl_packet_t packet;
  
  memset(auStack_48,0,0x28);
  if ((cmd_rsp == (zcl_touchlink_device_info_rsp_t *)0x0) ||
     (iVar2 = zcl_packet_init(auStack_48,0), iVar2 != 0)) {
    eVar1 = -1;
  }
  else {
    memcpy(auStack_60,cmd_rsp,10);
    eVar3 = zcl_touchlink_cmd_to_packet
                      ((zcl_packet_t *)auStack_48,'\x01','\x03',(ezb_address_t *)cmd_rsp);
    eVar1 = 2;
    if (eVar3 == 0) {
      packet.header.fc = (cmd_rsp->cmd_ctrl).tsn;
      packet.header.cluster_id._0_1_ = (byte)packet.header.cluster_id | 0x20;
      eVar1 = zmsg_append_le32((zmsg_t *)packet._32_4_,cmd_rsp->transaction_id);
      if (((eVar1 == 0) &&
          (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->n_sub_devices), eVar1 == 0)) &&
         (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->start_index), eVar1 == 0)) {
        eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->n_records);
        uVar4 = 0;
        if (eVar1 == 0) {
          for (; uVar4 < cmd_rsp->n_records; uVar4 = uVar4 + 1 & 0xff) {
            uStack_50 = *(undefined4 *)&cmd_rsp->records[uVar4].ieee_addr.field_0;
            uStack_4c = *(undefined4 *)((int)&cmd_rsp->records[uVar4].ieee_addr.field_0 + 4);
            eVar1 = zmsg_append_bytes(packet._32_4_,8,&uStack_50);
            if (((((eVar1 != 0) ||
                  (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->records[uVar4].ep_id),
                  eVar1 != 0)) ||
                 ((eVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,
                                            cmd_rsp->records[uVar4].profile_id), eVar1 != 0 ||
                  ((eVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,
                                             cmd_rsp->records[uVar4].device_id), eVar1 != 0 ||
                   (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->records[uVar4].version),
                   eVar1 != 0)))))) ||
                (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->records[uVar4].n_group_ids)
                , eVar1 != 0)) ||
               (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->records[uVar4].sort),
               eVar1 != 0)) goto _L0;
          }
          zcl_packet_intrp_send(auStack_48,&cmd_rsp->cnf_ctx);
          eVar1 = zcl_status_to_err();
          if (eVar1 == 0) {
            return 0;
          }
        }
      }
    }
  }
_L0:
  zcl_packet_free(auStack_48);
  return eVar1;
}


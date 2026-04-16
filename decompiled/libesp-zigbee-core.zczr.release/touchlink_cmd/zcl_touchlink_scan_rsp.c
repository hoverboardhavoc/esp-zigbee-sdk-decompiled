/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_scan_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_touchlink_scan_rsp(zcl_touchlink_scan_rsp_t *cmd_rsp)

{
  ezb_err_t eVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_rsp == (zcl_touchlink_scan_rsp_t *)0x0) ||
     (iVar2 = zcl_packet_init(auStack_38,0), iVar2 != 0)) {
    eVar1 = -1;
  }
  else {
    memcpy(auStack_50,cmd_rsp,10);
    eVar3 = zcl_touchlink_cmd_to_packet
                      ((zcl_packet_t *)auStack_38,'\x01','\x01',(ezb_address_t *)cmd_rsp);
    eVar1 = 2;
    if (eVar3 == 0) {
      packet.header.fc = (cmd_rsp->cmd_ctrl).tsn;
      packet.header.cluster_id._0_1_ = (byte)packet.header.cluster_id | 0x20;
      eVar1 = zmsg_append_le32((zmsg_t *)packet._32_4_,cmd_rsp->transaction_id);
      if (((((((eVar1 == 0) &&
              (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->rssi_correction), eVar1 == 0)
              ) && (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->zigbee_info), eVar1 == 0
                   )) &&
            ((eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->touchlink_info), eVar1 == 0 &&
             (eVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,cmd_rsp->key_bitmask), eVar1 == 0))))
           && ((eVar1 = zmsg_append_le32((zmsg_t *)packet._32_4_,cmd_rsp->response_id), eVar1 == 0
               && ((eVar1 = zmsg_append_bytes(packet._32_4_,8,&cmd_rsp->ext_panid), eVar1 == 0 &&
                   (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->nwk_update_id),
                   eVar1 == 0)))))) &&
          (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->channel), eVar1 == 0)) &&
         (((((eVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,cmd_rsp->pan_id), eVar1 == 0 &&
             (eVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,cmd_rsp->nwk_addr), eVar1 == 0)) &&
            (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->n_subdevs), eVar1 == 0)) &&
           (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,cmd_rsp->total_group_ids), eVar1 == 0))
          && ((cmd_rsp->n_subdevs != '\x01' ||
              (((eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_rsp->sub_device).ep_id),
                eVar1 == 0 &&
                (eVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_rsp->sub_device).profile_id),
                eVar1 == 0)) &&
               ((eVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_rsp->sub_device).device_id),
                eVar1 == 0 &&
                ((eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_rsp->sub_device).version),
                 eVar1 == 0 &&
                 (eVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_rsp->sub_device).n_group_ids),
                 eVar1 == 0)))))))))))) {
        zcl_packet_intrp_send(auStack_38,&cmd_rsp->cnf_ctx);
        eVar1 = zcl_status_to_err();
        if (eVar1 == 0) {
          return 0;
        }
      }
    }
  }
  zcl_packet_free(auStack_38);
  return eVar1;
}


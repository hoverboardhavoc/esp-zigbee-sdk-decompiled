/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ezb_zcl_ota_upgrade_query_next_image_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ota_upgrade_query_next_image_cmd_req
                    (ezb_zcl_ota_upgrade_query_next_image_req_cmd_t *cmd_req)

{
  ezb_err_t eVar1;
  int iVar2;
  uint32_t auStack_3c [2];
  zcl_packet_t packet;
  
  auStack_3c[1] = 0;
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
  if (cmd_req == (ezb_zcl_ota_upgrade_query_next_image_req_cmd_t *)0x0) {
    eVar1 = -1;
  }
  else {
    iVar2 = zcl_packet_init(auStack_3c + 1,0);
    if (iVar2 == 0) {
      eVar1 = zcl_cmd_to_packet(auStack_3c + 1,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,1,0x19);
      if (eVar1 == 0) {
        auStack_3c[0] = CONCAT22(auStack_3c[0]._2_2_,(ushort)(cmd_req->payload).fc);
        eVar1 = zmsg_append_bytes(packet._32_4_,2,auStack_3c);
        if (eVar1 == 0) {
          auStack_3c[0] = CONCAT22(auStack_3c[0]._2_2_,(cmd_req->payload).manuf_code);
          eVar1 = zmsg_append_bytes(packet._32_4_,2,auStack_3c);
          if (eVar1 == 0) {
            auStack_3c[0] = CONCAT22(auStack_3c[0]._2_2_,(cmd_req->payload).image_type);
            eVar1 = zmsg_append_bytes(packet._32_4_,2,auStack_3c);
            if (eVar1 == 0) {
              auStack_3c[0] = (cmd_req->payload).file_version;
              eVar1 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
              if (eVar1 == 0) {
                if (((cmd_req->payload).fc & 1) != 0) {
                  auStack_3c[0] = CONCAT22(auStack_3c[0]._2_2_,(cmd_req->payload).hw_version);
                  eVar1 = zmsg_append_bytes(packet._32_4_,2,auStack_3c);
                  if (eVar1 != 0) goto _L0;
                }
                zcl_packet_send(auStack_3c + 1,&(cmd_req->cmd_ctrl).cnf_ctx);
                eVar1 = zcl_status_to_err();
                if (eVar1 == 0) {
                  return 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      eVar1 = -1;
    }
  }
_L0:
  zcl_packet_free(auStack_3c + 1);
  return eVar1;
}


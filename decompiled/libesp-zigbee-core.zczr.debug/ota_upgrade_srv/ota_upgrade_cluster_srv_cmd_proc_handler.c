/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ota_upgrade_cluster_srv_cmd_proc_handler(void *arg)

{
  char cVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined1 auStack_38 [4];
  zcl_packet_t rsp;
  
  auStack_38 = (undefined1  [4])0x0;
  rsp.header.src_addr._0_4_ = 0;
  rsp.header.src_addr.u._2_4_ = 0;
  rsp.header._8_4_ = 0;
  rsp.header.dst_addr.u._0_2_ = 0;
  rsp.header.dst_addr.u._2_2_ = 0;
  rsp.header.dst_addr.u._4_4_ = 0;
  rsp.header.src_ep = '\0';
  rsp.header.dst_ep = '\0';
  rsp.header.cluster_id = 0;
  rsp.header.profile_id = 0;
  rsp.header.fc = '\0';
  rsp.header._27_1_ = 0;
  rsp.header.manuf_code = 0;
  rsp.header.tsn = '\0';
  rsp.header.rssi = '\0';
  rsp.header.cmd_id = '\0';
  rsp.header._33_1_ = 0;
  rsp._34_2_ = 0;
  if (arg == (void *)0x0) {
    iVar2 = 1;
  }
  else if ((*(byte *)((int)arg + 0x1a) >> 3 & 1) == 0) {
    iVar2 = zcl_packet_init(auStack_38,*(byte *)((int)arg + 0x1a) >> 2 & 1);
    if (iVar2 == 0) {
      cVar1 = *(char *)((int)arg + 0x20);
      if (cVar1 == '\x03') {
        eVar3 = ota_upgrade_cluster_srv_image_block_req_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_00,eVar3);
      }
      else if (cVar1 == '\x06') {
        eVar3 = ota_upgrade_cluster_srv_upgrade_end_req_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_01,eVar3);
      }
      else if (cVar1 == '\x01') {
        eVar3 = ota_upgrade_cluster_srv_query_next_image_req_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var,eVar3);
      }
      else {
        iVar2 = zcl_packet_setup_default_response(auStack_38,arg,0x81);
      }
      if (iVar2 == 0) {
        zcl_packet_send(auStack_38,0);
      }
      else {
        zcl_packet_free(auStack_38);
      }
    }
  }
  else {
    iVar2 = 1;
  }
  return (ezb_zcl_status_t)iVar2;
}


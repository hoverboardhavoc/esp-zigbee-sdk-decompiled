/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t touchlink_commissioning_cluster_cli_cmd_proc_handler(void *arg)

{
  char cVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined1 auStack_38 [4];
  zcl_packet_t resp;
  
  auStack_38 = (undefined1  [4])0x0;
  resp.header.src_addr._0_4_ = 0;
  resp.header.src_addr.u._2_4_ = 0;
  resp.header._8_4_ = 0;
  resp.header.dst_addr.u._0_2_ = 0;
  resp.header.dst_addr.u._2_2_ = 0;
  resp.header.dst_addr.u._4_4_ = 0;
  resp.header.src_ep = '\0';
  resp.header.dst_ep = '\0';
  resp.header.cluster_id = 0;
  resp.header.profile_id = 0;
  resp.header.fc = '\0';
  resp.header._27_1_ = 0;
  resp.header.manuf_code = 0;
  resp.header.tsn = '\0';
  resp.header.rssi = '\0';
  resp.header.cmd_id = '\0';
  resp.header._33_1_ = 0;
  resp._34_2_ = 0;
  if (arg == (void *)0x0) {
    iVar2 = 1;
  }
  else if ((*(byte *)((int)arg + 0x1a) & 8) == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = zcl_packet_init(auStack_38,*(byte *)((int)arg + 0x1a) >> 2 & 1);
    if (iVar2 == 0) {
      cVar1 = *(char *)((int)arg + 0x20);
      if (cVar1 == 'A') {
        eVar3 = touchlink_commissioning_get_group_ids_rsp_cmd_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_00,eVar3);
      }
      else if (cVar1 == 'B') {
        eVar3 = touchlink_commissioning_get_endpoint_list_rsp_cmd_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_01,eVar3);
      }
      else if (cVar1 == '@') {
        eVar3 = touchlink_commissioning_endpoint_info_cmd_handler
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
  return (ezb_zcl_status_t)iVar2;
}


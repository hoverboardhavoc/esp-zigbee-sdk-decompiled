/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ota_upgrade_cluster_cli_cmd_proc_handler(void *arg)

{
  byte bVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
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
    goto _L0;
  }
  if ((*(byte *)((int)arg + 0x1a) & 8) == 0) {
    iVar2 = 1;
    goto _L0;
  }
  iVar2 = zcl_packet_init(auStack_38,*(byte *)((int)arg + 0x1a) >> 2 & 1);
  if (iVar2 != 0) goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 5) {
    eVar3 = ota_upgrade_cluster_cli_image_block_rsp_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
    iVar2 = CONCAT31(extraout_var_02,eVar3);
  }
  else if (bVar1 < 6) {
    if (bVar1 == 0) {
      eVar3 = ota_upgrade_cluster_cli_image_notify_req_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_01,eVar3);
    }
    else {
      if (bVar1 != 2) goto _L0;
      eVar3 = ota_upgrade_cluster_cli_query_next_image_rsp_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var,eVar3);
    }
  }
  else if (bVar1 == 7) {
    eVar3 = ota_upgrade_cluster_cli_upgrade_end_rsp_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
    iVar2 = CONCAT31(extraout_var_00,eVar3);
  }
  else {
_L0:
    iVar2 = zcl_packet_setup_default_response(auStack_38,arg,0x81);
  }
  if (iVar2 == 0) {
    ota_upgrade_packet_send((zcl_packet_t *)auStack_38);
  }
  else {
    zcl_packet_free(auStack_38);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}


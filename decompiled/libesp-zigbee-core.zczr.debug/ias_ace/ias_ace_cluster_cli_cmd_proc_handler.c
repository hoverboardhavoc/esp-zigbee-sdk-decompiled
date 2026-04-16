/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_cli_cmd_proc_handler(void *arg)

{
  byte bVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
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
  if (bVar1 == 4) {
    eVar3 = ias_ace_cluster_panel_status_changed_cmd_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
    iVar2 = CONCAT31(extraout_var_05,eVar3);
  }
  else if (bVar1 < 5) {
    if (bVar1 == 2) {
      eVar3 = ias_ace_cluster_get_zone_information_rsp_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_04,eVar3);
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        eVar3 = ias_ace_cluster_arm_rsp_handler((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_03,eVar3);
      }
      else {
        if (bVar1 != 1) goto _L0;
        eVar3 = ias_ace_cluster_get_zone_id_map_rsp_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_00,eVar3);
      }
    }
    else {
      if (bVar1 != 3) goto _L0;
      eVar3 = ias_ace_cluster_zone_status_changed_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_01,eVar3);
    }
  }
  else if (bVar1 == 7) {
    eVar3 = ias_ace_cluster_bypass_rsp_handler((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
    iVar2 = CONCAT31(extraout_var_07,eVar3);
  }
  else if (bVar1 < 8) {
    if (bVar1 == 5) {
      eVar3 = ias_ace_cluster_get_panel_status_rsp_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var_06,eVar3);
    }
    else {
      if (bVar1 != 6) goto _L0;
      eVar3 = ias_ace_cluster_set_bypassed_zone_list_rsp_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
      iVar2 = CONCAT31(extraout_var,eVar3);
    }
  }
  else if (bVar1 == 8) {
    eVar3 = ias_ace_cluster_get_zone_status_rsp_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
    iVar2 = CONCAT31(extraout_var_02,eVar3);
  }
  else {
_L0:
    iVar2 = zcl_packet_setup_default_response(auStack_38,arg,0x81);
  }
  if (iVar2 == 0) {
    zcl_packet_send(auStack_38,0);
  }
  else {
    zcl_packet_free(auStack_38);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}


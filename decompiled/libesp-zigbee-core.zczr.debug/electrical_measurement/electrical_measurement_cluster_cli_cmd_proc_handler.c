/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t electrical_measurement_cluster_cli_cmd_proc_handler(void *arg)

{
  int iVar1;
  ezb_zcl_status_t eVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
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
    iVar1 = 1;
  }
  else if ((*(byte *)((int)arg + 0x1a) & 8) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_38,*(byte *)((int)arg + 0x1a) >> 2 & 1);
    if (iVar1 == 0) {
      if (*(char *)((int)arg + 0x20) == '\0') {
        eVar2 = electrical_measurement_cluster_get_prof_info_rsp_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar1 = CONCAT31(extraout_var,eVar2);
      }
      else if (*(char *)((int)arg + 0x20) == '\x01') {
        eVar2 = electrical_measurement_cluster_get_meas_prof_rsp_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar1 = CONCAT31(extraout_var_00,eVar2);
      }
      else {
        iVar1 = zcl_packet_setup_default_response(auStack_38,arg,0x81);
      }
      if (iVar1 == 0) {
        zcl_packet_send(auStack_38,0);
      }
      else {
        zcl_packet_free(auStack_38);
      }
    }
  }
  return (ezb_zcl_status_t)iVar1;
}


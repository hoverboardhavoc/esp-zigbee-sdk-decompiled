/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ezb_zcl_ias_zone_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_ias_zone_cluster_server_init(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  code *pcStack_48;
  code *pcStack_44;
  code *pcStack_34;
  undefined4 uStack_24;
  code *pcStack_20;
  code *pcStack_1c;
  code *pcStack_18;
  code *pcStack_14;
  
  uStack_24 = 0x10500;
  pcStack_20 = ias_zone_cluster_srv_check_value_handler;
  pcStack_1c = ias_zone_cluster_srv_write_attr_hook;
  pcStack_18 = ias_zone_cluster_srv_cmd_disc_handler;
  pcStack_14 = ias_zone_cluster_srv_cmd_proc_handler;
  iVar2 = ias_zone_ctx_init();
  if (iVar2 == 0) {
    iVar2 = zcl_cluster_template_add(&uStack_24);
    if (iVar2 == 0) {
      cie_info_restore(param_1);
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x229,
                  "ezb_zcl_ias_zone_cluster_server_init","ias_zone_ctx_init(ep_id) == 0");
  }
  pcVar1 = ezb_zcl_ias_zone_cluster_client_init;
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x22a,
                "ezb_zcl_ias_zone_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  uStack_54 = 0x20500;
  uStack_50 = 0;
  uStack_4c = 0;
  pcStack_48 = ias_zone_cluster_cli_cmd_disc_handler;
  pcStack_44 = ias_zone_cluster_cli_cmd_proc_handler;
  pcStack_34 = pcVar1;
  iVar2 = zcl_cluster_template_add(&uStack_54);
  if (iVar2 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x239,
                "ezb_zcl_ias_zone_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}


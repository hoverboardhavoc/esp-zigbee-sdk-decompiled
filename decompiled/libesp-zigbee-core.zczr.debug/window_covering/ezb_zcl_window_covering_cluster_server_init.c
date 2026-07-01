/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> window_covering.o -> ezb_zcl_window_covering_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_window_covering_cluster_server_init(uint8_t ep_id)

{
  code *pcVar1;
  int iVar2;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  code *pcStack_48;
  undefined4 uStack_44;
  code *pcStack_34;
  char *pcStack_24;
  zcl_cluster_template_t template;
  
  pcStack_24 = "/cluster/window_covering.c";
  template._0_4_ = window_covering_cluster_srv_check_value_handler;
  template.check_value_handler = (zcl_cluster_check_value_t)0x0;
  template.write_attr_handler = window_covering_cluster_srv_cmd_disc_handler;
  template.cmd_disc_handler = window_covering_cluster_srv_cmd_proc_handler;
  iVar2 = zcl_cluster_template_add(&pcStack_24);
  if (iVar2 == 0) {
    return;
  }
  pcVar1 = ezb_zcl_window_covering_cluster_client_init;
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/window_covering.c",0x107
                ,"ezb_zcl_window_covering_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  uStack_54 = 0x20102;
  uStack_50 = 0;
  uStack_4c = 0;
  pcStack_48 = window_covering_cluster_cli_cmd_disc_handler;
  uStack_44 = 0;
  pcStack_34 = pcVar1;
  iVar2 = zcl_cluster_template_add(&uStack_54);
  if (iVar2 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/window_covering.c",0x115
                ,"ezb_zcl_window_covering_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}


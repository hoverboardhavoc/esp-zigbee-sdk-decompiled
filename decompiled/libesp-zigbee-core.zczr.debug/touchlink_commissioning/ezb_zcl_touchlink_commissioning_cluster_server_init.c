/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> ezb_zcl_touchlink_commissioning_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_touchlink_commissioning_cluster_server_init(uint8_t ep_id)

{
  code *pcVar1;
  int iVar2;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  code *pcStack_48;
  code *pcStack_44;
  code *pcStack_34;
  code *pcStack_24;
  zcl_cluster_template_t template;
  
  pcStack_24 = zmsg_read_bytes;
  template.cluster_id = 0;
  template.cluster_role = '\0';
  template._3_1_ = 0;
  template.check_value_handler = (zcl_cluster_check_value_t)0x0;
  template.write_attr_handler = touchlink_commissioning_cluster_srv_cmd_disc_handler;
  template.cmd_disc_handler = touchlink_commissioning_cluster_srv_cmd_proc_handler;
  iVar2 = zcl_cluster_template_add(&pcStack_24);
  if (iVar2 == 0) {
    return;
  }
  pcVar1 = ezb_zcl_touchlink_commissioning_cluster_client_init;
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/touchlink_commissioning.c",0x178,
                "ezb_zcl_touchlink_commissioning_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  uStack_54 = 0x21000;
  uStack_50 = 0;
  uStack_4c = 0;
  pcStack_48 = touchlink_commissioning_cluster_cli_cmd_disc_handler;
  pcStack_44 = touchlink_commissioning_cluster_cli_cmd_proc_handler;
  pcStack_34 = pcVar1;
  iVar2 = zcl_cluster_template_add(&uStack_54);
  if (iVar2 == 0) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/touchlink_commissioning.c",0x186,
                "ezb_zcl_touchlink_commissioning_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}


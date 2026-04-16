/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> ezb_zcl_scenes_cluster_client_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_scenes_cluster_client_init(uint8_t ep_id)

{
  uint8_t ep_id_00;
  int iVar1;
  undefined4 uStack_24;
  zcl_cluster_template_t template;
  
  uStack_24 = 0x20005;
  template.cluster_id = 0;
  template.cluster_role = '\0';
  template._3_1_ = 0;
  template.check_value_handler = (zcl_cluster_check_value_t)0x0;
  template.write_attr_handler = scenes_cluster_cli_cmd_disc_handler;
  template.cmd_disc_handler = scenes_cluster_cli_cmd_proc_handler;
  iVar1 = zcl_cluster_template_add(&uStack_24);
  if (iVar1 == 0) {
    return;
  }
  ep_id_00 = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x5b8,
                           "ezb_zcl_scenes_cluster_client_init",
                           "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  scene_table_deinit(ep_id_00);
  return;
}


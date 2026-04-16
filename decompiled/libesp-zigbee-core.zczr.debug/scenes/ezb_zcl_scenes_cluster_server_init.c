/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> ezb_zcl_scenes_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_scenes_cluster_server_init(uint8_t ep_id)

{
  code *pcVar1;
  uint8_t ep_id_00;
  ezb_err_t eVar2;
  int iVar3;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  code *pcStack_48;
  code *pcStack_44;
  code *pcStack_34;
  undefined4 uStack_24;
  zcl_cluster_template_t template;
  
  uStack_24 = 0x10005;
  template._0_4_ = scenes_cluster_srv_check_value_handler;
  template.check_value_handler = (zcl_cluster_check_value_t)0x0;
  template.write_attr_handler = scenes_cluster_srv_cmd_disc_handler;
  template.cmd_disc_handler = scenes_cluster_srv_cmd_proc_handler;
  eVar2 = scene_table_init(ep_id);
  if (eVar2 == 0) {
    scene_table_restore(ep_id);
    iVar3 = zcl_cluster_template_add(&uStack_24);
    if (iVar3 == 0) {
      return;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x5a9,
                  "ezb_zcl_scenes_cluster_server_init","scene_table_init(ep_id) == 0");
  }
  pcVar1 = ezb_zcl_scenes_cluster_client_init;
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x5ab,
                "ezb_zcl_scenes_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  uStack_54 = 0x20005;
  uStack_50 = 0;
  uStack_4c = 0;
  pcStack_48 = scenes_cluster_cli_cmd_disc_handler;
  pcStack_44 = scenes_cluster_cli_cmd_proc_handler;
  pcStack_34 = pcVar1;
  iVar3 = zcl_cluster_template_add(&uStack_54);
  if (iVar3 == 0) {
    return;
  }
  ep_id_00 = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x5b8,
                           "ezb_zcl_scenes_cluster_client_init",
                           "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  scene_table_deinit(ep_id_00);
  return;
}


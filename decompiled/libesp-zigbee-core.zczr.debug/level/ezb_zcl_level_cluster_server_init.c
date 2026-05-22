/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> ezb_zcl_level_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_level_cluster_server_init(uint8_t ep_id)

{
  code *pcVar1;
  ezb_err_t eVar2;
  int iVar3;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  code *pcStack_48;
  undefined4 uStack_44;
  code *pcStack_34;
  undefined4 uStack_24;
  zcl_cluster_template_t template;
  
  uStack_24 = 0x10008;
  template._0_4_ = level_cluster_srv_check_value_handler;
  template.check_value_handler = (zcl_cluster_check_value_t)0x0;
  template.write_attr_handler = level_cluster_srv_cmd_disc_handler;
  template.cmd_disc_handler = level_cluster_srv_cmd_proc_handler;
  eVar2 = level_srv_cvc_ctx_init(ep_id);
  if (eVar2 == 0) {
    iVar3 = zcl_cluster_template_add(&uStack_24);
    if (iVar3 == 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x2ac,
                  "ezb_zcl_level_cluster_server_init","level_srv_cvc_ctx_init(ep_id) == 0");
  }
  pcVar1 = ezb_zcl_level_cluster_client_init;
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x2ad,
                "ezb_zcl_level_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  uStack_54 = 0x20008;
  uStack_50 = 0;
  uStack_4c = 0;
  pcStack_48 = level_cluster_cli_cmd_disc_handler;
  uStack_44 = 0;
  pcStack_34 = pcVar1;
  iVar3 = zcl_cluster_template_add(&uStack_54);
  if (iVar3 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",699,
                "ezb_zcl_level_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}


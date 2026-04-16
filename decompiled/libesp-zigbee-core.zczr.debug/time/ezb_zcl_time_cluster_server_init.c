/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> ezb_zcl_time_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_time_cluster_server_init(uint8_t ep_id)

{
  code *pcVar1;
  ezb_err_t eVar2;
  int iVar3;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  code *pcStack_34;
  undefined4 uStack_24;
  zcl_cluster_template_t template;
  
  uStack_24 = 0x1000a;
  template._0_4_ = time_cluster_srv_check_value_handler;
  template.check_value_handler = time_cluster_srv_write_attr_hook;
  template.write_attr_handler = (zcl_cluster_write_attr_t)0x0;
  template.cmd_disc_handler = (zcl_cluster_disc_cmd_t)0x0;
  eVar2 = time_server_ctx_init(ep_id);
  if (eVar2 == 0) {
    iVar3 = zcl_cluster_template_add(&uStack_24);
    if (iVar3 == 0) {
      return;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/time.c",0x19c,
                  "ezb_zcl_time_cluster_server_init","time_server_ctx_init(ep_id) == 0");
  }
  pcVar1 = ezb_zcl_time_cluster_client_init;
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/time.c",0x19d,
                "ezb_zcl_time_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  uStack_54 = 0x2000a;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  pcStack_34 = pcVar1;
  iVar3 = zcl_cluster_template_add(&uStack_54);
  if (iVar3 == 0) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/time.c",0x1ab,
                "ezb_zcl_time_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> ezb_zcl_color_control_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_color_control_cluster_server_init(uint8_t ep_id)

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
  
  uStack_24 = 0x10300;
  template._0_4_ = color_control_cluster_srv_check_value_handler;
  template.check_value_handler = (zcl_cluster_check_value_t)0x0;
  template.write_attr_handler = color_control_cluster_srv_cmd_disc_handler;
  template.cmd_disc_handler = color_control_cluster_srv_cmd_proc_handler;
  eVar2 = color_control_srv_cvc_ctx_init(ep_id);
  if (eVar2 == 0) {
    iVar3 = zcl_cluster_template_add(&uStack_24);
    if (iVar3 == 0) {
      return;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x950,
                  "ezb_zcl_color_control_cluster_server_init",
                  "color_control_srv_cvc_ctx_init(ep_id) == 0");
  }
  pcVar1 = ezb_zcl_color_control_cluster_client_init;
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x951,
                "ezb_zcl_color_control_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  uStack_54 = 0x20300;
  uStack_50 = 0;
  uStack_4c = 0;
  pcStack_48 = color_control_cluster_cli_cmd_disc_handler;
  uStack_44 = 0;
  pcStack_34 = pcVar1;
  iVar3 = zcl_cluster_template_add(&uStack_54);
  if (iVar3 == 0) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x95f,
                "ezb_zcl_color_control_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}


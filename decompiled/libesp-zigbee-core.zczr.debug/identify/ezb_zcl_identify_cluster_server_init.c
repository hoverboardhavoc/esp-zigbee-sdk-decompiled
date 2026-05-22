/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> ezb_zcl_identify_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_identify_cluster_server_init(uint8_t ep_id)

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
  
  uStack_24 = 0x10003;
  template.cluster_id = 0;
  template.cluster_role = '\0';
  template._3_1_ = 0;
  template.check_value_handler = identify_cluster_srv_write_attr_hook;
  template.write_attr_handler = identify_cluster_srv_cmd_disc_handler;
  template.cmd_disc_handler = identify_cluster_srv_cmd_proc_handler;
  eVar2 = identify_timer_ctx_init(ep_id);
  if (eVar2 == 0) {
    iVar3 = zcl_cluster_template_add(&uStack_24);
    if (iVar3 == 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x17e,
                  "ezb_zcl_identify_cluster_server_init","identify_timer_ctx_init(ep_id) == 0");
  }
  pcVar1 = ezb_zcl_identify_cluster_client_init;
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x17f,
                "ezb_zcl_identify_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  uStack_54 = 0x20003;
  uStack_50 = 0;
  uStack_4c = 0;
  pcStack_48 = identify_cluster_cli_cmd_disc_handler;
  pcStack_44 = identify_cluster_cli_cmd_proc_handler;
  pcStack_34 = pcVar1;
  iVar3 = zcl_cluster_template_add(&uStack_54);
  if (iVar3 == 0) {
    return;
  }
  ep_id_00 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",
                           0x18d,"ezb_zcl_identify_cluster_client_init",
                           "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  identify_timer_ctx_deinit(ep_id_00);
  return;
}


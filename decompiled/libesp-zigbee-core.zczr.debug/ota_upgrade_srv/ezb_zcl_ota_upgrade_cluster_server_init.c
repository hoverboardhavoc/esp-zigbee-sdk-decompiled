/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_ota_upgrade_cluster_server_init(uint8_t ep_id)

{
  ezb_err_t eVar1;
  int iVar2;
  undefined4 uStack_24;
  zcl_cluster_template_t template;
  
  uStack_24 = 0x10019;
  template.cluster_id = 0;
  template.cluster_role = '\0';
  template._3_1_ = 0;
  template.check_value_handler = (zcl_cluster_check_value_t)0x0;
  template.write_attr_handler = ota_upgrade_cluster_srv_cmd_disc_handler;
  template.cmd_disc_handler = ota_upgrade_cluster_srv_cmd_proc_handler;
  eVar1 = ota_upgrade_srv_ota_file_table_init(ep_id);
  if (eVar1 == 0) {
    iVar2 = zcl_cluster_template_add(&uStack_24);
    if (iVar2 == 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c",
                  0x1f6,"ezb_zcl_ota_upgrade_cluster_server_init",
                  "ota_upgrade_srv_ota_file_table_init(ep_id) == 0");
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c",0x1f7
                ,"ezb_zcl_ota_upgrade_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}


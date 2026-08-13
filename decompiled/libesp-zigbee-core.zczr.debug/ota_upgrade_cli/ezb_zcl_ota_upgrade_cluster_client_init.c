/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ezb_zcl_ota_upgrade_cluster_client_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_ota_upgrade_cluster_client_init(void)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  code *pcStack_14;
  
  uStack_24 = 0x20019;
  uStack_20 = 0;
  uStack_1c = 0;
  pcStack_18 = ota_upgrade_cluster_cli_cmd_disc_handler;
  pcStack_14 = ota_upgrade_cluster_cli_cmd_proc_handler;
  iVar1 = ota_upgrade_downloading_context_init();
  if (iVar1 == 0) {
    iVar1 = zcl_cluster_template_add(&uStack_24);
    if (iVar1 == 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0x394,"ezb_zcl_ota_upgrade_cluster_client_init",
                  "ota_upgrade_downloading_context_init(ep_id) == 0");
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0x395
                ,"ezb_zcl_ota_upgrade_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  ota_upgrade_downloading_context_deinit();
  return;
}


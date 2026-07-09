/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock.o -> ezb_zcl_door_lock_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_door_lock_cluster_server_init(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  code *pcStack_48;
  code *pcStack_44;
  code *pcStack_34;
  undefined4 uStack_24;
  code *pcStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  code *pcStack_14;
  
  uStack_24 = 0x10101;
  pcStack_20 = door_lock_cluster_srv_check_value_handler;
  uStack_1c = 0;
  pcStack_18 = door_lock_cluster_srv_cmd_disc_handler;
  pcStack_14 = door_lock_cluster_srv_cmd_proc_handler;
  iVar2 = zcl_cluster_template_add(&uStack_24);
  if (iVar2 == 0) {
    return;
  }
  pcVar1 = ezb_zcl_door_lock_cluster_client_init;
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/door_lock.c",0x112,
                "ezb_zcl_door_lock_cluster_server_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  uStack_54 = 0x20101;
  uStack_50 = 0;
  uStack_4c = 0;
  pcStack_48 = door_lock_cluster_cli_cmd_disc_handler;
  pcStack_44 = door_lock_cluster_cli_cmd_proc_handler;
  pcStack_34 = pcVar1;
  iVar2 = zcl_cluster_template_add(&uStack_54);
  if (iVar2 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/door_lock.c",0x120,
                "ezb_zcl_door_lock_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}


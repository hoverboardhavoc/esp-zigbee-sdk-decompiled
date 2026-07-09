/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock.o -> ezb_zcl_door_lock_cluster_client_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_door_lock_cluster_client_init(void)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  code *pcStack_14;
  
  uStack_24 = 0x20101;
  uStack_20 = 0;
  uStack_1c = 0;
  pcStack_18 = door_lock_cluster_cli_cmd_disc_handler;
  pcStack_14 = door_lock_cluster_cli_cmd_proc_handler;
  iVar1 = zcl_cluster_template_add(&uStack_24);
  if (iVar1 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/door_lock.c",0x120,
                "ezb_zcl_door_lock_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}


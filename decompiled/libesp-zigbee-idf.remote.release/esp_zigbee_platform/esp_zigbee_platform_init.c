/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_platform.o -> esp_zigbee_platform_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_platform_init(undefined4 *param_1)

{
  int iVar1;
  undefined4 auStack_14 [2];
  
  auStack_14[0] = 2;
  iVar1 = esp_vfs_eventfd_register(auStack_14);
  if ((((iVar1 == 0x103) || (iVar1 == 0)) && (iVar1 = esp_zigbee_platform_alarm_init(), iVar1 == 0))
     && ((iVar1 = esp_zigbee_task_queue_init(), iVar1 == 0 &&
         (iVar1 = esp_zigbee_platform_radio_init(param_1 + 1), iVar1 == 0)))) {
    esp_zigbee_set_storage_name(*param_1);
  }
  else {
    esp_zigbee_platform_deinit();
  }
  return iVar1;
}


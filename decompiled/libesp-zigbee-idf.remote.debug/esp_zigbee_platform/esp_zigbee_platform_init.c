/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_platform.o -> esp_zigbee_platform_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_platform_init(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_14;
  
  uStack_14 = 2;
  iVar2 = esp_vfs_eventfd_register(&uStack_14);
  if (iVar2 == 0x103) {
    iVar1 = 0;
  }
  else {
    iVar1 = iVar2;
    if (iVar2 != 0) {
      esp_log(0x11,"ESP-ZIGBEE","%s(%d): esp_vfs_eventfd_register failed","esp_zigbee_platform_init"
              ,0x55);
      goto _L0;
    }
  }
  iVar2 = esp_zigbee_platform_alarm_init();
  if (iVar2 == 0) {
    iVar2 = esp_zigbee_task_queue_init();
    if (iVar2 == 0) {
      iVar2 = esp_zigbee_platform_radio_init(param_1 + 1);
      if (iVar2 == 0) {
        esp_zigbee_set_storage_name(*param_1);
        iVar2 = iVar1;
      }
      else {
        esp_log(0x11,"ESP-ZIGBEE","%s(%d): esp_zigbee_platform_radio_init failed",
                "esp_zigbee_platform_init",0x59);
      }
    }
    else {
      esp_log(0x11,"ESP-ZIGBEE","%s(%d): esp_zigbee_task_queue_init failed",
              "esp_zigbee_platform_init",0x58);
    }
  }
  else {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): esp_zigbee_platform_alarm_init failed",
            "esp_zigbee_platform_init",0x56);
  }
_L0:
  if (iVar2 != 0) {
    esp_zigbee_platform_deinit();
  }
  return iVar2;
}


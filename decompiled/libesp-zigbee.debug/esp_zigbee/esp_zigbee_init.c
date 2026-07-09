/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_init(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_zigbee_get_version_string();
  esp_log(0x13,"ESP-ZIGBEE","SDK Version: %s",uVar1);
  iVar2 = esp_zigbee_sleep_init();
  if (iVar2 == 0) {
    iVar2 = esp_zigbee_lock_init();
    if (iVar2 == 0) {
      iVar2 = esp_zigbee_platform_init(param_1 + 4);
      if (iVar2 == 0) {
        iVar2 = ezb_core_init();
        if (iVar2 == 0) {
          zdo_compat_init();
          ezb_secur_set_ic_required((char)param_1[1]);
          ezb_nwk_set_device_type(*param_1);
          if (*param_1 < 2) {
            ezb_nwk_set_max_children((char)param_1[2]);
          }
          else if (*param_1 == 2) {
            ezb_nwk_set_ed_timeout((char)param_1[2]);
            ezb_nwk_set_keepalive_interval(param_1[3]);
          }
          else {
            iVar2 = 0x102;
          }
        }
        else {
          esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize ESP-Zigbee core","esp_zigbee_init",
                  0x41);
        }
      }
      else {
        esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize platform driver","esp_zigbee_init",
                0x3f);
      }
    }
    else {
      esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize task lock","esp_zigbee_init",0x3e);
    }
  }
  else {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize sleep procedure","esp_zigbee_init",0x3d);
  }
  return iVar2;
}


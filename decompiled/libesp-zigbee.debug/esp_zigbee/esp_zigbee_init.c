/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
          iVar2 = ezb_secur_set_ic_required((char)param_1[1]);
          if (iVar2 == 0) {
            iVar2 = ezb_nwk_set_device_type(*param_1);
            if (iVar2 == 0) {
              if (*param_1 < 2) {
                iVar2 = ezb_nwk_set_max_children((char)param_1[2]);
                if (iVar2 != 0) {
                  esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to set max children","esp_zigbee_init",
                          0x56);
                }
              }
              else {
                if (*param_1 != 2) {
                  return 0x102;
                }
                ezb_nwk_set_ed_timeout((char)param_1[2]);
                ezb_nwk_set_keepalive_interval(param_1[3]);
              }
            }
            else {
              esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to set device type","esp_zigbee_init",0x50);
            }
          }
          else {
            esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to set install code policy","esp_zigbee_init",
                    0x4d);
          }
        }
        else {
          esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize ESP-Zigbee core","esp_zigbee_init",
                  0x46);
        }
        iVar2 = esp_zigbee_err_to_esp(iVar2);
      }
      else {
        esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize platform driver","esp_zigbee_init",
                0x41);
      }
    }
    else {
      esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize task lock","esp_zigbee_init",0x40);
    }
  }
  else {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize sleep procedure","esp_zigbee_init",0x3f);
  }
  return iVar2;
}


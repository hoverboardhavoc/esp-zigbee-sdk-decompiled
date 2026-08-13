/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee.release -> esp_zigbee.o -> esp_zigbee_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint esp_zigbee_init(uint *param_1)

{
  uint uVar1;
  
  uVar1 = esp_zigbee_sleep_init();
  if (((uVar1 == 0) && (uVar1 = esp_zigbee_lock_init(), uVar1 == 0)) &&
     (uVar1 = esp_zigbee_platform_init(param_1 + 4), uVar1 == 0)) {
    uVar1 = ezb_core_init();
    if (uVar1 == 0) {
      zdo_compat_init();
      uVar1 = ezb_secur_set_ic_required((char)param_1[1]);
      if ((uVar1 == 0) && (uVar1 = ezb_nwk_set_device_type(*param_1), uVar1 == 0)) {
        if (*param_1 < 2) {
          uVar1 = ezb_nwk_set_max_children((char)param_1[2]);
        }
        else {
          if (*param_1 != 2) {
            return 0x102;
          }
          ezb_nwk_set_ed_timeout((char)param_1[2]);
          ezb_nwk_set_keepalive_interval(param_1[3]);
        }
      }
    }
    if ((uVar1 != 0) && (uVar1 != 0xffffffff)) {
      if ((uVar1 >> 8 & 0xff) == 0) {
        return (uVar1 & 0xff) + 0x100;
      }
      uVar1 = 0xffffffff;
    }
    return uVar1;
  }
  return uVar1;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> esp_zigbee.o -> esp_zigbee_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_init(uint *param_1)

{
  int iVar1;
  
  iVar1 = esp_zigbee_sleep_init();
  if ((((iVar1 == 0) && (iVar1 = esp_zigbee_lock_init(), iVar1 == 0)) &&
      (iVar1 = esp_zigbee_platform_init(param_1 + 4), iVar1 == 0)) &&
     (iVar1 = ezb_core_init(), iVar1 == 0)) {
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
      iVar1 = 0x102;
    }
  }
  return iVar1;
}


/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_scheduler_user_alarm_cancel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_scheduler_user_alarm_cancel(uint param_1)

{
  int iVar1;
  
  if (0xfd < param_1) {
    return 0x102;
  }
  iVar1 = zb_schedule_alarm_cancel(esp_zb_schedule_user_cb,param_1,0);
  if (iVar1 != 0) {
    if (iVar1 == -0x1c) {
      return 0x105;
    }
    if (iVar1 == -0x16) {
      return 0x101;
    }
    if ((iVar1 + 0xdU < 4) || (iVar1 == -0xf)) {
      return 0x102;
    }
    if (iVar1 == -6) {
      return 0x104;
    }
    if (iVar1 != -0x1e) {
      if (iVar1 == -2) {
        return 0x10c;
      }
      iVar1 = -1;
    }
  }
  return iVar1;
}


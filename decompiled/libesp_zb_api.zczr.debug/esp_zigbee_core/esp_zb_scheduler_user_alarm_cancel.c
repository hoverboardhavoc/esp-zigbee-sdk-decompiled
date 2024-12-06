/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_scheduler_user_alarm_cancel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_scheduler_user_alarm_cancel(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0xfe) {
    zb_schedule_alarm_cancel(esp_zb_schedule_user_cb,param_1,0);
    uVar1 = zb_ret_to_esp_err();
  }
  else {
    uVar1 = 0x102;
  }
  return uVar1;
}


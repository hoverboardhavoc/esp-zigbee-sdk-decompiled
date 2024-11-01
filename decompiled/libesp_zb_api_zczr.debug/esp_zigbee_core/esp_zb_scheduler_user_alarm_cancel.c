/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_scheduler_user_alarm_cancel
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


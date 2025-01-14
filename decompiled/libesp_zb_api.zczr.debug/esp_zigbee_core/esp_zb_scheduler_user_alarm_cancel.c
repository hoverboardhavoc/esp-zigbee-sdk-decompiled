/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_scheduler_user_alarm_cancel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_scheduler_user_alarm_cancel(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x102;
  }
  else if (param_1 == 0xfe) {
    uVar1 = 0x102;
  }
  else if (param_1 == 0xff) {
    uVar1 = 0x102;
  }
  else {
    zb_schedule_alarm_cancel(esp_zb_schedule_user_cb,param_1,0);
    uVar1 = zb_ret_to_esp_err();
    zb_buf_free_func(param_1);
  }
  return uVar1;
}


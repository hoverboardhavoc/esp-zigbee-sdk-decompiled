/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> alarms_alarm_table_remove_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 alarms_alarm_table_remove_entry(undefined4 param_1,uint param_2,uint param_3)

{
  byte *__ptr;
  byte *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = (byte *)alarms_get_alarm_table();
  if (pbVar1 == (byte *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_ALARMS",&_LC1,uVar2,"ESP_ZIGBEE_ZCL_ALARMS",
                  "alarms_alarm_table_remove_entry",0xc3,param_1);
    uVar2 = 0x105;
  }
  else {
    while ((__ptr = *(byte **)pbVar1, __ptr != (byte *)0x0 &&
           ((param_2 != *__ptr || (param_3 != *(ushort *)(__ptr + 2)))))) {
      pbVar1 = __ptr + 8;
    }
    if (__ptr == (byte *)0x0) {
      uVar2 = 0x105;
    }
    else {
      *(undefined4 *)pbVar1 = *(undefined4 *)(__ptr + 8);
      alarms_dec_alarm_count(param_1);
      free(__ptr);
      uVar2 = 0;
    }
  }
  return uVar2;
}


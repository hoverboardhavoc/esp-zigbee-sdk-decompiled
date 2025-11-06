/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> alarms_alarm_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarms_alarm_table_free(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *__ptr;
  
  puVar1 = (undefined4 *)alarms_get_alarm_table();
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_ALARMS","E (%lu) %s: %s(%d): No alarm table for ep %d\n",uVar2,
            "ESP_ZIGBEE_ZCL_ALARMS","alarms_alarm_table_free",0xd7,param_1);
  }
  else {
    while (__ptr = (void *)*puVar1, __ptr != (void *)0x0) {
      uVar2 = *(undefined4 *)((int)__ptr + 8);
      free(__ptr);
      *puVar1 = uVar2;
    }
    alarms_set_alarm_count(param_1,0);
  }
  return;
}


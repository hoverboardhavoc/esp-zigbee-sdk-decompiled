/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> alarms_alarm_table_add_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
alarms_alarm_table_add_entry
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
  piVar1 = (int *)alarms_get_alarm_table();
  if (piVar1 == (int *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_ALARMS","E (%lu) %s: %s(%d): No alarm table for ep %d\n",uVar5,
            "ESP_ZIGBEE_ZCL_ALARMS","alarms_alarm_table_add_entry",0xa1,param_1);
    return 0x105;
  }
  uVar2 = alarms_get_alarm_count(param_1);
  uVar3 = alarms_get_alarm_table_size(param_1);
  if (uVar2 < uVar3) {
    puVar4 = (undefined1 *)malloc(0xc);
    if (puVar4 != (undefined1 *)0x0) goto _L0;
    uVar5 = esp_log_timestamp();
    esp_log(2,"ESP_ZIGBEE_ZCL_ALARMS",
            "W (%lu) %s: No memory to add alarm log with alarm code: 0x%x, cluster id: 0x%04x, drop it\n"
            ,uVar5,"ESP_ZIGBEE_ZCL_ALARMS",param_2,param_3);
  }
  else {
    puVar4 = (undefined1 *)alarms_alarm_table_pop_earliest_entry(param_1);
  }
  if (puVar4 == (undefined1 *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_ALARMS","E (%lu) %s: %s(%d): No space for alarm table entry\n",uVar5,
            "ESP_ZIGBEE_ZCL_ALARMS","alarms_alarm_table_add_entry",0xaf);
    return 0x101;
  }
_L0:
  *puVar4 = (char)param_2;
  *(short *)(puVar4 + 2) = (short)param_3;
  *(undefined4 *)(puVar4 + 4) = param_4;
  *(undefined4 *)(puVar4 + 8) = 0;
  *(int *)(puVar4 + 8) = *piVar1;
  *piVar1 = (int)puVar4;
  alarms_inc_alarm_count(param_1);
  return 0;
}


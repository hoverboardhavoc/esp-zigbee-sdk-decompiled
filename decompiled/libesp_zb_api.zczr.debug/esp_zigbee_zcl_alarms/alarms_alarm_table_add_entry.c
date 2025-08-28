/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
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
    esp_log_write(1,"ESP_ZIGBEE_ZCL_ALARMS",&_LC1,uVar5,"ESP_ZIGBEE_ZCL_ALARMS",
                  "alarms_alarm_table_add_entry",0xa1,param_1);
    return 0x105;
  }
  uVar2 = alarms_get_alarm_count(param_1);
  uVar3 = alarms_get_alarm_table_size(param_1);
  if (uVar2 < uVar3) {
    puVar4 = (undefined1 *)malloc(0xc);
    if (puVar4 != (undefined1 *)0x0) goto _L0;
    uVar5 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_ZCL_ALARMS",&_LC3,uVar5,"ESP_ZIGBEE_ZCL_ALARMS",param_2,param_3);
  }
  else {
    puVar4 = (undefined1 *)alarms_alarm_table_pop_earliest_entry(param_1);
  }
  if (puVar4 == (undefined1 *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_ALARMS",&_LC4,uVar5,"ESP_ZIGBEE_ZCL_ALARMS",
                  "alarms_alarm_table_add_entry",0xaf);
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


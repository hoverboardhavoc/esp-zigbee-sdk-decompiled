/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> alarms_alarm_table_pop_earliest_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int alarms_alarm_table_pop_earliest_entry(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)alarms_get_alarm_table();
  if (piVar2 == (int *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_ALARMS",&_LC1,uVar3,"ESP_ZIGBEE_ZCL_ALARMS",
                  "alarms_alarm_table_pop_earliest_entry",0x90,param_1);
    iVar1 = 0;
  }
  else {
    while ((iVar1 = *piVar2, iVar1 != 0 && (*(int *)(iVar1 + 8) != 0))) {
      piVar2 = (int *)(iVar1 + 8);
    }
    if (iVar1 != 0) {
      *piVar2 = *(int *)(iVar1 + 8);
      alarms_dec_alarm_count(param_1);
    }
  }
  return iVar1;
}


/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> alarms_alarm_table_pop_earliest_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * alarms_alarm_table_pop_earliest_entry(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)alarms_get_alarm_table();
  puVar1 = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    while (puVar1 = (undefined4 *)*puVar2, puVar1 != (undefined4 *)0x0) {
      if (puVar1[2] == 0) {
        *puVar2 = 0;
        alarms_dec_alarm_count(param_1);
        return puVar1;
      }
      puVar2 = puVar1 + 2;
    }
  }
  return puVar1;
}


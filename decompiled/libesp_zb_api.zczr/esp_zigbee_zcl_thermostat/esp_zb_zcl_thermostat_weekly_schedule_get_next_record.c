/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_thermostat.o -> esp_zb_zcl_thermostat_weekly_schedule_get_next_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_thermostat_weekly_schedule_get_next_record(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  uStack_1a = *param_1;
  zb_zcl_thermostat_weekly_schedule_get_next_record(&uStack_1a,&uStack_18);
  iVar1 = esp_err_to_zb_ret();
  if (iVar1 == 0) {
    *param_1 = uStack_1a;
    param_2[1] = uStack_16;
    *param_2 = uStack_18;
    param_2[2] = uStack_14;
    param_2[3] = uStack_12;
  }
  return;
}


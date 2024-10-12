/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_thermostat.o -> esp_zb_zcl_thermostat_weekly_schedule_get_next_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_thermostat_weekly_schedule_get_next_record(undefined2 *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined2 uStack_1a;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  uStack_1a = *param_1;
  zb_zcl_thermostat_weekly_schedule_get_next_record(&uStack_1a,&uStack_18);
  iVar1 = esp_err_to_zb_ret();
  if (iVar1 == 0) {
    *param_1 = uStack_1a;
    *param_2 = uStack_18;
    param_2[1] = uStack_17;
    *(undefined2 *)(param_2 + 2) = uStack_16;
    *(undefined2 *)(param_2 + 6) = uStack_12;
    *(undefined2 *)(param_2 + 4) = uStack_14;
  }
  return;
}


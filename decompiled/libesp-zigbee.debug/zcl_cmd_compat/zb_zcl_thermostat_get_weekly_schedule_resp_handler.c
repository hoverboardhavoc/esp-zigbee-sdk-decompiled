/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_thermostat_get_weekly_schedule_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_thermostat_get_weekly_schedule_resp_handler(undefined1 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  convert_to_esp_zb_zcl_cmd_info(&uStack_38,*(undefined4 *)(param_1 + 8));
  uStack_38 = CONCAT31(uStack_38._1_3_,*param_1);
  if (*(int *)(param_1 + 0xc) != 0) {
    puVar2 = *(undefined1 **)(param_1 + 0xc);
    uStack_18._0_3_ =
         CONCAT12(puVar2[2],CONCAT11(*(undefined1 *)(*(int *)(param_1 + 0xc) + 1),*puVar2));
    uStack_14 = *(undefined4 *)(puVar2 + 4);
  }
  if (param_2 != (code *)0x0) {
    (*param_2)(0x3a,&uStack_38);
    uVar1 = esp_err_to_zcl_status();
    param_1[0x10] = uVar1;
  }
  return;
}


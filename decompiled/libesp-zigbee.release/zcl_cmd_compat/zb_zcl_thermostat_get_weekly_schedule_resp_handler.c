/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_thermostat_get_weekly_schedule_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_thermostat_get_weekly_schedule_resp_handler(undefined1 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 auStack_38 [32];
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  convert_to_esp_zb_zcl_cmd_info(auStack_38,*(undefined4 *)(param_1 + 8));
  auStack_38[0] = *param_1;
  puVar2 = *(undefined1 **)(param_1 + 0xc);
  if (puVar2 != (undefined1 *)0x0) {
    uStack_17 = puVar2[1];
    uStack_18 = *puVar2;
    uStack_16 = puVar2[2];
    uStack_14 = *(undefined4 *)(puVar2 + 4);
  }
  if (param_2 != (code *)0x0) {
    (*param_2)(0x3a,auStack_38);
    uVar1 = esp_err_to_zcl_status();
    param_1[0x10] = uVar1;
  }
  return;
}


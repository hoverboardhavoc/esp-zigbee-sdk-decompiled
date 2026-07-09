/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_thermostat_set_weekly_schedule_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_thermostat_set_weekly_schedule_handler(undefined2 *param_1,code *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  char *pcVar3;
  undefined2 *puVar4;
  undefined2 local_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_2e = param_1[1];
  local_30 = *param_1;
  pcVar3 = *(char **)(param_1 + 6);
  uStack_2c = 0;
  if (((pcVar3 != (char *)0x0) &&
      (uStack_28 = (uint)*(ushort *)(pcVar3 + 1), *(int *)(pcVar3 + 4) != 0)) && (*pcVar3 != '\0'))
  {
    for (uVar1 = 0; (uVar1 & 0xffff) < (uint)**(byte **)(param_1 + 6); uVar1 = uVar1 + 1) {
      puVar4 = (undefined2 *)(*(int *)(*(byte **)(param_1 + 6) + 4) + uVar1 * 6);
      uStack_28 = CONCAT22(*puVar4,(undefined2)uStack_28);
      uStack_24 = *(undefined4 *)(puVar4 + 1);
      if (param_2 != (code *)0x0) {
        (*param_2)(0x39,&local_30);
        uVar2 = esp_err_to_zcl_status();
        *(undefined1 *)(param_1 + 8) = uVar2;
      }
    }
  }
  return;
}


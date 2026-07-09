/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_thermostat_set_weekly_schedule_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_thermostat_set_weekly_schedule_handler(undefined4 *param_1,code *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  byte *pbVar3;
  char *pcVar4;
  int iVar5;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  uStack_1c = 0;
  local_20 = *param_1;
  pcVar4 = (char *)param_1[3];
  if (pcVar4 != (char *)0x0) {
    uStack_18 = (uint)*(ushort *)(pcVar4 + 1);
    if ((*(int *)(pcVar4 + 4) != 0) && (*pcVar4 != '\0')) {
      for (uVar1 = 0; pbVar3 = (byte *)param_1[3], uVar1 < *pbVar3; uVar1 = uVar1 + 1 & 0xffff) {
        iVar5 = uVar1 * 6;
        uStack_18 = CONCAT22(*(undefined2 *)(*(int *)(pbVar3 + 4) + iVar5),(undefined2)uStack_18);
        _uStack_14 = CONCAT22(*(undefined2 *)(iVar5 + *(int *)(param_1[3] + 4) + 4),
                              *(undefined2 *)(*(int *)(pbVar3 + 4) + iVar5 + 2));
        if (param_2 != (code *)0x0) {
          (*param_2)(0x39,&local_20);
          uVar2 = esp_err_to_zcl_status();
          *(undefined1 *)(param_1 + 4) = uVar2;
        }
      }
    }
  }
  return;
}


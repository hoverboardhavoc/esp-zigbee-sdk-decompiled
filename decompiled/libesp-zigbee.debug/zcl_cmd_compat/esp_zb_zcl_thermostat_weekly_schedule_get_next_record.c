/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_thermostat_weekly_schedule_get_next_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_thermostat_weekly_schedule_get_next_record(ushort *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  
  if (param_1 == (ushort *)0x0) {
    uVar5 = 0x102;
  }
  else if (param_2 == (byte *)0x0) {
    uVar5 = 0x102;
  }
  else {
    iVar3 = get_endpoint_by_cluster(0x201,1);
    if (iVar3 == 0) {
      uVar5 = 0x105;
    }
    else {
      uVar2 = (uint)*param_1;
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        pbVar4 = (byte *)ezb_zcl_thermostat_get_weekly_schedule_entry(iVar3,bVar1);
        if (pbVar4 != (byte *)0x0) {
          if (uVar2 < pbVar4[1]) {
            *param_2 = bVar1;
            param_2[1] = *pbVar4;
            iVar3 = uVar2 * 6;
            *(undefined2 *)(param_2 + 2) = *(undefined2 *)(*(int *)(pbVar4 + 4) + iVar3);
            *(undefined2 *)(param_2 + 4) = *(undefined2 *)(*(int *)(pbVar4 + 4) + iVar3 + 2);
            *(undefined2 *)(param_2 + 6) = *(undefined2 *)(iVar3 + *(int *)(pbVar4 + 4) + 4);
            *param_1 = *param_1 + 1;
            return 0;
          }
          uVar2 = uVar2 - pbVar4[1] & 0xffff;
        }
      }
      *param_1 = 0xffff;
      uVar5 = 0x105;
    }
  }
  return uVar5;
}


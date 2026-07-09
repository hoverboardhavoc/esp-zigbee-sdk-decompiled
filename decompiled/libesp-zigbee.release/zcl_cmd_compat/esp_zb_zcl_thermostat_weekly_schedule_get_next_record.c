/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_thermostat_weekly_schedule_get_next_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_thermostat_weekly_schedule_get_next_record(ushort *param_1,char *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined2 *puVar6;
  char cVar7;
  
  if (param_1 == (ushort *)0x0) {
    return 0x102;
  }
  uVar3 = 0x102;
  if (param_2 != (char *)0x0) {
    iVar4 = get_endpoint_by_cluster_constprop_0(0x102);
    if (iVar4 != 0) {
      uVar2 = (uint)*param_1;
      cVar7 = '\0';
      do {
        pcVar5 = (char *)ezb_zcl_thermostat_get_weekly_schedule_entry(iVar4,cVar7);
        if (pcVar5 != (char *)0x0) {
          if (uVar2 < (byte)pcVar5[1]) {
            *param_2 = cVar7;
            param_2[1] = *pcVar5;
            puVar6 = (undefined2 *)(*(int *)(pcVar5 + 4) + uVar2 * 6);
            *(undefined2 *)(param_2 + 2) = *puVar6;
            uVar1 = puVar6[2];
            *(undefined2 *)(param_2 + 4) = puVar6[1];
            *(undefined2 *)(param_2 + 6) = uVar1;
            *param_1 = *param_1 + 1;
            return 0;
          }
          uVar2 = uVar2 - (byte)pcVar5[1] & 0xffff;
        }
        cVar7 = cVar7 + '\x01';
      } while (cVar7 != '\a');
      *param_1 = 0xffff;
    }
    uVar3 = 0x105;
  }
  return uVar3;
}


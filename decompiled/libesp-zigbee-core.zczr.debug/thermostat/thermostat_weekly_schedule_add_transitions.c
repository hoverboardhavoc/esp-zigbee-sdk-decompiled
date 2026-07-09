/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_add_transitions
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int thermostat_weekly_schedule_add_transitions(undefined4 param_1,byte *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  short local_50;
  short sStack_4e;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  iVar3 = thermostat_weekly_schedule_context_get();
  iVar8 = iVar3 + 8;
  iVar4 = thermostat_weekly_schedule_graphs_copy(&uStack_4c,iVar8,7);
  if (iVar4 == 0) {
    for (uVar2 = 0; uVar6 = (uint)*param_2, uVar2 < uVar6; uVar2 = uVar2 + 1 & 0xff) {
      if ((param_2[2] & 1) != 0) {
        local_50 = 0;
        sStack_4e = 0;
        sVar1 = *(short *)(uVar2 * 6 + *(int *)(param_2 + 4) + 2);
        thermostat_get_heat_setpoint_limit(param_1,&local_50,&sStack_4e);
        if ((sVar1 < local_50) || (sStack_4e < sVar1)) {
          iVar4 = 0x87;
          goto _L0;
        }
      }
      if ((param_2[2] & 2) != 0) {
        local_50 = 0;
        sStack_4e = 0;
        sVar1 = *(short *)(*(int *)(param_2 + 4) + uVar2 * 6 + 4);
        thermostat_get_cool_setpoint_limit(param_1,&local_50,&sStack_4e);
        if (((sVar1 < local_50) || (sStack_4e < sVar1)) ||
           (*(short *)(*(int *)(param_2 + 4) + uVar2 * 6 + 4) != sVar1)) {
          iVar4 = 0x87;
          goto _L0;
        }
      }
    }
    uVar9 = 0;
    uVar10 = 0;
    for (uVar2 = 0; uVar2 < 7; uVar2 = uVar2 + 1 & 0xff) {
      iVar7 = *(int *)(uVar2 * 4 + iVar3 + 8);
      if (iVar7 == 0) break;
      iVar5 = thermostat_weekly_schedule_day_is_set(param_2[1],uVar2);
      if (iVar5 != 0) {
        uVar10 = *(byte *)(iVar7 + 1) + uVar10 & 0xff;
        uVar9 = uVar9 + 1 & 0xff;
      }
    }
    if (*(byte *)(iVar3 + 4) < uVar6) {
      iVar4 = 0x89;
    }
    else {
      if (uVar10 + uVar9 * uVar6 <= (uint)*(byte *)(iVar3 + 3)) {
        for (uVar2 = 0; uVar2 < 7; uVar2 = uVar2 + 1 & 0xff) {
          iVar7 = thermostat_weekly_schedule_day_is_set(param_2[1],uVar2);
          if (iVar7 != 0) {
            iVar5 = uVar2 * 4 + iVar3;
            thermostat_weekly_schedule_graphs_free(iVar5 + 8,1);
            iVar7 = thermostat_weekly_schedule_graph_create(*param_2,param_2[2]);
            *(int *)(iVar5 + 8) = iVar7;
            if (iVar7 == 0) {
              iVar4 = 0x89;
              goto _L0;
            }
            memcpy(*(void **)(iVar7 + 4),*(void **)(param_2 + 4),(uint)*param_2 * 6);
            iVar5 = uVar2 * 4 + iVar3;
            iVar7 = *(int *)(iVar5 + 8);
            weekly_schedule_transitions_sort(*(undefined4 *)(iVar7 + 4),*(undefined1 *)(iVar7 + 1));
            iVar7 = thermostat_weekly_schedule_graph_is_overlapping(*(undefined4 *)(iVar5 + 8));
            if (iVar7 != 0) {
              iVar4 = 1;
              goto _L0;
            }
          }
        }
        goto _L0;
      }
      iVar4 = 0x89;
    }
  }
_L0:
  thermostat_weekly_schedule_graphs_free(iVar8,7);
  thermostat_weekly_schedule_graphs_copy(iVar8,&uStack_4c,7);
_L0:
  thermostat_weekly_schedule_graphs_free(&uStack_4c,7);
  return iVar4;
}


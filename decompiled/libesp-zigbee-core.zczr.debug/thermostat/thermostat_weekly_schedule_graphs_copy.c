/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_graphs_copy
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 thermostat_weekly_schedule_graphs_copy(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xff) {
      iVar5 = uVar2 * 4;
      piVar6 = (int *)(param_2 + iVar5);
      if (*piVar6 == 0) {
        *(undefined4 *)(iVar5 + param_1) = 0;
      }
      else {
        piVar1 = (int *)(param_1 + iVar5);
        pvVar3 = calloc(1,8);
        *piVar1 = (int)pvVar3;
        if (pvVar3 == (void *)0x0) {
_L0:
          thermostat_weekly_schedule_graphs_free(param_1,param_3);
          return 0x89;
        }
        pvVar4 = calloc((uint)*(byte *)(*piVar6 + 1),6);
        *(void **)((int)pvVar3 + 4) = pvVar4;
        if (*(int *)(*piVar1 + 4) == 0) goto _L0;
        *(undefined1 *)(*piVar1 + 1) = *(undefined1 *)(*piVar6 + 1);
        *(undefined1 *)*piVar1 = *(undefined1 *)*piVar6;
        if (*(void **)(*piVar1 + 4) == (void *)0x0) goto _L0;
        memcpy(*(void **)(*piVar1 + 4),*(void **)(*piVar6 + 4),(uint)*(byte *)(*piVar6 + 1) * 6);
      }
    }
  }
  return 0;
}


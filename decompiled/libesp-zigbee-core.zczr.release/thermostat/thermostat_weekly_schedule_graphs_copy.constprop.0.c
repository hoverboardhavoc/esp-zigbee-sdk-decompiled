/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_weekly_schedule_graphs_copy.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 thermostat_weekly_schedule_graphs_copy_constprop_0(undefined4 *param_1,int *param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  void *__dest;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int *piVar5;
  
  piVar5 = param_2 + 7;
  puVar3 = param_1;
  do {
    if (*param_2 == 0) {
      *puVar3 = 0;
    }
    else {
      puVar2 = (undefined1 *)calloc(1,8);
      *puVar3 = puVar2;
      if (puVar2 == (undefined1 *)0x0) {
_L0:
        thermostat_weekly_schedule_graphs_free(param_1,7);
        return 0x89;
      }
      puVar4 = (undefined1 *)*param_2;
      bVar1 = puVar4[1];
      __dest = calloc((uint)bVar1,6);
      *(void **)(puVar2 + 4) = __dest;
      if (__dest == (void *)0x0) goto _L0;
      puVar2[1] = bVar1;
      *puVar2 = *puVar4;
      memcpy(__dest,*(void **)(puVar4 + 4),(uint)(byte)puVar4[1] * 6);
    }
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
    if (param_2 == piVar5) {
      return 0;
    }
  } while( true );
}


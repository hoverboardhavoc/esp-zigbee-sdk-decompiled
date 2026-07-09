/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_graph_is_overlapping
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 thermostat_weekly_schedule_graph_is_overlapping(int param_1)

{
  short *psVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar2 = 1;
  uVar3 = 0;
  while( true ) {
    if (*(byte *)(param_1 + 1) <= uVar3) {
      return 0;
    }
    if (*(byte *)(param_1 + 1) <= uVar2) break;
    psVar4 = (short *)(uVar3 * 6 + *(int *)(param_1 + 4));
    psVar1 = (short *)(*(int *)(param_1 + 4) + uVar2 * 6);
    if (((*psVar4 == *psVar1) && (psVar4[1] == psVar1[1])) && (psVar4[2] == psVar1[2])) {
      return 1;
    }
    uVar3 = uVar3 + 1 & 0xff;
    uVar2 = uVar2 + 1 & 0xff;
  }
  return 0;
}


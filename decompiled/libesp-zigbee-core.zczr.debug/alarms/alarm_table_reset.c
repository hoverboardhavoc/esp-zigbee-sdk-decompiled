/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 alarm_table_reset(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = (int *)get_alarm_table();
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    alarm_table_remove_stored_all(param_1);
    for (uVar4 = 0; uVar4 < *(byte *)(piVar1 + 3); uVar4 = uVar4 + 1 & 0xff) {
      iVar3 = uVar4 * 0xc + *piVar1;
      *(int *)iVar3 = iVar3;
    }
    *(undefined1 *)((int)piVar1 + 0xd) = 0;
    piVar1[2] = 0;
    piVar1[1] = 0;
    uVar2 = 0;
  }
  return uVar2;
}


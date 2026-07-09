/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarm_table_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 alarm_table_reset(undefined4 param_1)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  piVar2 = (int *)get_alarm_table();
  if (piVar2 == (int *)0x0) {
    uVar3 = 5;
  }
  else {
    alarm_table_remove_stored_all(param_1);
    bVar1 = *(byte *)(piVar2 + 3);
    for (uVar5 = 0; (uVar5 & 0xff) < (uint)bVar1; uVar5 = uVar5 + 1) {
      iVar4 = *piVar2 + uVar5 * 0xc;
      *(int *)iVar4 = iVar4;
    }
    *(undefined1 *)((int)piVar2 + 0xd) = 0;
    piVar2[2] = 0;
    piVar2[1] = 0;
    uVar3 = 0;
  }
  return uVar3;
}


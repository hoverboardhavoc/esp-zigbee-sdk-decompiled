/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarm_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 alarm_table_add(undefined4 param_1,undefined1 param_2,undefined2 param_3,int param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  piVar1 = (int *)get_alarm_table();
  if (piVar1 == (int *)0x0) {
    uVar2 = 5;
  }
  else {
    if (*(byte *)(piVar1 + 3) <= *(byte *)((int)piVar1 + 0xd)) {
      alarm_table_pop_oldest(param_1);
    }
    uVar5 = 0;
    do {
      if ((uint)*(byte *)(piVar1 + 3) <= (uVar5 & 0xff)) {
        DAT_00000004 = 0;
        ebreak();
      }
      iVar3 = uVar5 * 0xc;
      uVar5 = uVar5 + 1;
      piVar4 = (int *)(iVar3 + *piVar1);
    } while (piVar4 != (int *)*piVar4);
    *(undefined1 *)(piVar4 + 1) = param_2;
    puVar6 = (undefined4 *)piVar1[2];
    *(undefined2 *)((int)piVar4 + 6) = param_3;
    piVar4[2] = param_4;
    if (puVar6 == (undefined4 *)0x0) {
      *piVar4 = piVar1[1];
      piVar1[1] = (int)piVar4;
    }
    else {
      *puVar6 = piVar4;
      *piVar4 = 0;
    }
    piVar1[2] = (int)piVar4;
    *(char *)((int)piVar1 + 0xd) = *(char *)((int)piVar1 + 0xd) + '\x01';
    alarm_table_store_entry(param_1);
    uVar2 = 0;
  }
  return uVar2;
}


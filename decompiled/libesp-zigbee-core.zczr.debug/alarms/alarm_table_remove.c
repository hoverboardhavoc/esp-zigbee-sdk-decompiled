/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 alarm_table_remove(undefined4 param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar2 = get_alarm_table();
  if (iVar2 == 0) {
    uVar3 = 5;
  }
  else {
    uVar3 = 5;
    puVar4 = (undefined4 *)(iVar2 + 4);
    while (puVar1 = puVar4, puVar4 = (undefined4 *)*puVar1, puVar4 != (undefined4 *)0x0) {
      if ((*(byte *)(puVar4 + 1) == param_2) && (*(ushort *)((int)puVar4 + 6) == param_3)) {
        if (*(undefined4 **)(iVar2 + 8) == puVar4) {
          if (puVar1 == (undefined4 *)(iVar2 + 4)) {
            *(undefined4 *)(iVar2 + 8) = 0;
          }
          else {
            *(undefined4 **)(iVar2 + 8) = puVar1;
          }
        }
        *puVar1 = *(undefined4 *)*puVar1;
        *puVar4 = puVar4;
        alarm_table_remove_stored_entry
                  (param_1,*(undefined1 *)(puVar4 + 1),*(undefined2 *)((int)puVar4 + 6),puVar4[2]);
        *(char *)(iVar2 + 0xd) = *(char *)(iVar2 + 0xd) + -1;
        uVar3 = 0;
        puVar4 = puVar1;
      }
    }
  }
  return uVar3;
}


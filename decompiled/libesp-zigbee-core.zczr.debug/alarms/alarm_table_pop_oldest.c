/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_pop_oldest
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * alarm_table_pop_oldest(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = get_alarm_table();
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = *(undefined4 **)(iVar2 + 4);
    if (puVar1 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar2 + 4) = *puVar1;
      *puVar1 = puVar1;
      if (*(undefined4 **)(iVar2 + 8) == puVar1) {
        *(undefined4 *)(iVar2 + 8) = 0;
      }
      *(char *)(iVar2 + 0xd) = *(char *)(iVar2 + 0xd) + -1;
      alarm_table_remove_stored_entry
                (param_1,*(undefined1 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),puVar1[2]);
    }
  }
  return puVar1;
}


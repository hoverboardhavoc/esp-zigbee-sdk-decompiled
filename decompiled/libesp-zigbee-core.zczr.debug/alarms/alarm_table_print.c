/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_print
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarm_table_print(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  
  iVar2 = get_alarm_table();
  if ((iVar2 != 0) &&
     (log_write(3,"ZCL_ALARMS","alarm table ep_id=%u total=%u count=%u",param_1,
                *(undefined1 *)(iVar2 + 0xc),*(undefined1 *)(iVar2 + 0xd)),
     *(char *)(iVar2 + 0xd) != '\0')) {
    cVar3 = '\0';
    for (puVar1 = *(undefined4 **)(iVar2 + 4); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      log_write(3,"ZCL_ALARMS","  [%u] alarm_code=0x%02x cluster_id=0x%04x time_stamp=%lu",cVar3,
                *(undefined1 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),puVar1[2]);
      cVar3 = cVar3 + '\x01';
    }
  }
  return;
}


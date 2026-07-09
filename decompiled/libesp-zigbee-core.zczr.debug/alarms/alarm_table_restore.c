/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarm_table_restore(uint param_1)

{
  bool bVar1;
  uint unaff_s0;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined1 uStack_26;
  byte bStack_25;
  undefined2 uStack_24;
  char cStack_22;
  
  piVar2 = (int *)get_alarm_table();
  if (piVar2 == (int *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x171,
                  "alarm_table_restore","table");
    goto _L0;
  }
  uStack_24 = 0;
  cStack_22 = '\0';
  ds_alarm_log_itor_read(&uStack_2c);
  unaff_s0 = 0;
  do {
    if (cStack_22 != '\0') {
      bVar1 = false;
_L0:
      if (unaff_s0 != 0) {
        qsort((void *)*piVar2,unaff_s0,0xc,alarm_log_compare_by_time);
        piVar5 = (int *)*piVar2;
        *piVar5 = piVar2[1];
        piVar2[1] = (int)piVar5;
        piVar2[2] = (int)piVar5;
        for (uVar6 = 1; uVar6 < unaff_s0; uVar6 = uVar6 + 1 & 0xff) {
          puVar3 = (undefined4 *)(*piVar2 + uVar6 * 0xc);
          *puVar3 = 0;
          *(undefined4 **)piVar2[2] = puVar3;
          piVar2[2] = (int)puVar3;
        }
        *(char *)((int)piVar2 + 0xd) = (char)unaff_s0;
      }
      if (bVar1) {
        alarm_table_refresh_stored_alarms(param_1);
      }
      return;
    }
    if (bStack_25 == param_1) {
      if (*(byte *)(piVar2 + 3) <= unaff_s0) {
        bVar1 = true;
        goto _L0;
      }
      iVar4 = unaff_s0 * 0xc;
      *(undefined1 *)(*piVar2 + iVar4 + 4) = uStack_26;
      *(undefined2 *)(*piVar2 + iVar4 + 6) = uStack_28;
      *(undefined4 *)(iVar4 + *piVar2 + 8) = uStack_2c;
      unaff_s0 = unaff_s0 + 1 & 0xff;
    }
_L0:
    ds_alarm_log_next(&uStack_2c);
  } while( true );
}


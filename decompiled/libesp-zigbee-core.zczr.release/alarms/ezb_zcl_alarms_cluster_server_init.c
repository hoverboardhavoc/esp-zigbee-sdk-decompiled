/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> ezb_zcl_alarms_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_alarms_cluster_server_init(uint param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  undefined4 local_40;
  undefined2 uStack_3c;
  undefined1 uStack_3a;
  byte bStack_39;
  short sStack_38;
  char cStack_36;
  undefined1 auStack_34 [32];
  
  memcpy(auStack_34,&_LANCHOR0,0x14);
  iVar3 = ezb_zcl_get_attr_desc(param_1,9,1,0xeffe,0x131b);
  if (iVar3 == 0) goto _L0;
  if (*(byte **)(iVar3 + 8) == (byte *)0x0) goto _L0;
  bVar1 = **(byte **)(iVar3 + 8);
  uVar9 = (uint)bVar1;
  if (uVar9 == 0) goto _L0;
  iVar3 = ezb_zcl_get_attr_desc(param_1,9,1,0xefff,0x131b);
  if (iVar3 == 0) goto _L0;
  puVar4 = (undefined4 *)calloc(1,0x10);
  if (puVar4 == (undefined4 *)0x0) goto _L0;
  pvVar5 = calloc(uVar9,0xc);
  *puVar4 = pvVar5;
  if (pvVar5 == (void *)0x0) goto _L0;
  *(byte *)(puVar4 + 3) = bVar1;
  *(undefined1 *)((int)puVar4 + 0xd) = 0;
  puVar4[2] = 0;
  puVar4[1] = 0;
  uVar7 = 0;
  do {
    *(void **)pvVar5 = pvVar5;
    uVar7 = uVar7 + 1 & 0xff;
    pvVar5 = (void *)((int)pvVar5 + 0xc);
  } while (uVar9 != uVar7);
  *(undefined4 **)(iVar3 + 8) = puVar4;
  do {
    piVar6 = (int *)get_alarm_table(param_1);
    if (piVar6 != (int *)0x0) {
      sStack_38 = 0;
      cStack_36 = '\0';
      uVar9 = 0;
      ds_alarm_log_itor_read(&local_40);
      while (cStack_36 == '\0') {
        if (bStack_39 == param_1) {
          if (*(byte *)(piVar6 + 3) <= uVar9) {
            bVar2 = true;
            if (uVar9 != 0) goto _L0;
            goto _L0;
          }
          iVar3 = uVar9 * 0xc;
          uVar9 = uVar9 + 1 & 0xff;
          iVar3 = *piVar6 + iVar3;
          *(undefined1 *)(iVar3 + 4) = uStack_3a;
          *(undefined2 *)(iVar3 + 6) = uStack_3c;
          *(undefined4 *)(iVar3 + 8) = local_40;
        }
        sStack_38 = sStack_38 + 1;
        ds_alarm_log_itor_read(&local_40);
      }
      bVar2 = false;
      if (uVar9 != 0) {
_L0:
        qsort((void *)*piVar6,uVar9,0xc,alarm_log_compare_by_time);
        piVar8 = (int *)*piVar6;
        *piVar8 = piVar6[1];
        piVar6[1] = (int)piVar8;
        uVar7 = 1;
        while( true ) {
          piVar6[2] = (int)piVar8;
          piVar8 = piVar8 + 3;
          if (uVar9 == uVar7) break;
          *piVar8 = 0;
          uVar7 = uVar7 + 1 & 0xff;
          *(int **)piVar6[2] = piVar8;
        }
        *(char *)((int)piVar6 + 0xd) = (char)uVar9;
        if (bVar2) {
_L0:
          alarm_table_remove_stored_all(param_1);
          iVar3 = get_alarm_table(param_1);
          if (iVar3 != 0) {
            for (piVar6 = *(int **)(iVar3 + 4); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
              alarm_table_store_entry(param_1,piVar6);
            }
          }
        }
      }
      iVar3 = zcl_cluster_template_add(auStack_34);
      if (iVar3 == 0) {
        return;
      }
    }
_L0:
    __assert_func(0,0,0,0);
_L0:
    log_write(3,"ZCL_ALARMS","Alarm table size is zero");
  } while( true );
}


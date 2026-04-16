/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> ezb_zcl_alarms_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_alarms_cluster_server_init(uint8_t ep_id)

{
  byte bVar1;
  bool bVar2;
  undefined3 in_register_00002029;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  void *pvVar6;
  alarms_alarm_table_t *paVar7;
  uint uVar8;
  alarms_alarm_table_entry_t *paVar9;
  uint uVar10;
  undefined1 local_40 [4];
  ds_alarm_log_iterator_t itor;
  zcl_cluster_template_t template;
  
  uVar3 = CONCAT31(in_register_00002029,ep_id);
  memcpy(&itor.index,&_LANCHOR0,0x14);
  iVar4 = ezb_zcl_get_attr_desc(uVar3,9,1,0xeffe,0x131b);
  if (iVar4 == 0) goto _L0;
  if (*(byte **)(iVar4 + 8) == (byte *)0x0) goto _L0;
  bVar1 = **(byte **)(iVar4 + 8);
  uVar10 = (uint)bVar1;
  if (uVar10 == 0) goto _L0;
  iVar4 = ezb_zcl_get_attr_desc(uVar3,9,1,0xefff,0x131b);
  if (iVar4 == 0) goto _L0;
  puVar5 = (undefined4 *)calloc(1,0x10);
  if (puVar5 == (undefined4 *)0x0) goto _L0;
  pvVar6 = calloc(uVar10,0xc);
  *puVar5 = pvVar6;
  if (pvVar6 == (void *)0x0) goto _L0;
  *(byte *)(puVar5 + 3) = bVar1;
  *(undefined1 *)((int)puVar5 + 0xd) = 0;
  puVar5[2] = 0;
  puVar5[1] = 0;
  uVar8 = 0;
  do {
    *(void **)pvVar6 = pvVar6;
    uVar8 = uVar8 + 1 & 0xff;
    pvVar6 = (void *)((int)pvVar6 + 0xc);
  } while (uVar10 != uVar8);
  *(undefined4 **)(iVar4 + 8) = puVar5;
  do {
    paVar7 = get_alarm_table(ep_id);
    if (paVar7 != (alarms_alarm_table_t *)0x0) {
      itor.data.cluster_id = 0;
      itor.data.alarm_code = '\0';
      ds_alarm_log_itor_read((ds_alarm_log_iterator_t *)local_40);
      uVar10 = 0;
      while (itor.data.alarm_code == '\0') {
        uVar8 = uVar10;
        if (itor.data.time_stamp._3_1_ == uVar3) {
          if (paVar7->total <= uVar10) {
            bVar2 = true;
            if (uVar10 != 0) goto _L0;
            goto _L0;
          }
          paVar9 = paVar7->entries;
          uVar8 = uVar10 + 1 & 0xff;
          paVar9[uVar10].alarm_code = itor.data.time_stamp._2_1_;
          paVar9[uVar10].cluster_id = (uint16_t)itor.data.time_stamp;
          paVar9[uVar10].time_stamp = (uint32_t)local_40;
        }
        itor.data.cluster_id = itor.data.cluster_id + 1;
        ds_alarm_log_itor_read((ds_alarm_log_iterator_t *)local_40);
        uVar10 = uVar8;
      }
      bVar2 = false;
      if (uVar10 != 0) {
_L0:
        qsort(paVar7->entries,uVar10,0xc,alarm_log_compare_by_time);
        paVar9 = paVar7->entries;
        (paVar9->node).next = (paVar7->active_alarms).head;
        (paVar7->active_alarms).head = &paVar9->node;
        uVar8 = 1;
        while( true ) {
          paVar7->tail = &paVar9->node;
          paVar9 = paVar9 + 1;
          if (uVar10 == uVar8) break;
          (paVar9->node).next = (list_node_s *)0x0;
          uVar8 = uVar8 + 1 & 0xff;
          paVar7->tail->next = &paVar9->node;
        }
        paVar7->count = (uint8_t)uVar10;
        if (bVar2) {
_L0:
          alarm_table_remove_stored_all(ep_id);
          paVar7 = get_alarm_table(ep_id);
          if (paVar7 != (alarms_alarm_table_t *)0x0) {
            for (paVar9 = (alarms_alarm_table_entry_t *)(paVar7->active_alarms).head;
                paVar9 != (alarms_alarm_table_entry_t *)0x0;
                paVar9 = (alarms_alarm_table_entry_t *)(paVar9->node).next) {
              alarm_table_store_entry(ep_id,paVar9);
            }
          }
        }
      }
      iVar4 = zcl_cluster_template_add(&itor.index);
      if (iVar4 == 0) {
        return;
      }
    }
_L0:
    __assert_func(0,0,0,0);
_L0:
    log_write(3,"ZCL_ALARMS","Alarm table size is zero");
  } while( true );
}


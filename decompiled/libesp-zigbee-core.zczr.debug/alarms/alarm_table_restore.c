/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void alarm_table_restore(uint8_t ep_id)

{
  bool bVar1;
  uint unaff_s0;
  undefined3 in_register_00002029;
  alarms_alarm_table_t *paVar2;
  alarms_alarm_table_entry_t *paVar3;
  uint uVar4;
  undefined1 auStack_2c [4];
  ds_alarm_log_iterator_t itor;
  
  paVar2 = get_alarm_table(ep_id);
  if (paVar2 == (alarms_alarm_table_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x171,
                  "alarm_table_restore","table");
    goto _L0;
  }
  itor.data.cluster_id = 0;
  itor.data.alarm_code = '\0';
  ds_alarm_log_itor_read((ds_alarm_log_iterator_t *)auStack_2c);
  unaff_s0 = 0;
  do {
    if (itor.data.alarm_code != '\0') {
      bVar1 = false;
_L0:
      if (unaff_s0 != 0) {
        qsort(paVar2->entries,unaff_s0,0xc,alarm_log_compare_by_time);
        paVar3 = paVar2->entries;
        (paVar3->node).next = (paVar2->active_alarms).head;
        (paVar2->active_alarms).head = &paVar3->node;
        paVar2->tail = &paVar3->node;
        for (uVar4 = 1; uVar4 < unaff_s0; uVar4 = uVar4 + 1 & 0xff) {
          paVar3 = paVar2->entries + uVar4;
          (paVar3->node).next = (list_node_s *)0x0;
          paVar2->tail->next = &paVar3->node;
          paVar2->tail = &paVar3->node;
        }
        paVar2->count = (uint8_t)unaff_s0;
      }
      if (bVar1) {
        alarm_table_refresh_stored_alarms(ep_id);
      }
      return;
    }
    if ((uint)itor.data.time_stamp._3_1_ == CONCAT31(in_register_00002029,ep_id)) {
      if (paVar2->total <= unaff_s0) {
        bVar1 = true;
        goto _L0;
      }
      paVar2->entries[unaff_s0].alarm_code = itor.data.time_stamp._2_1_;
      paVar2->entries[unaff_s0].cluster_id = (uint16_t)itor.data.time_stamp;
      paVar2->entries[unaff_s0].time_stamp = (uint32_t)auStack_2c;
      unaff_s0 = unaff_s0 + 1 & 0xff;
    }
_L0:
    ds_alarm_log_next((ds_alarm_log_iterator_t *)auStack_2c);
  } while( true );
}


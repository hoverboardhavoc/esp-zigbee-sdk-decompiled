/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarm_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t alarm_table_add(uint8_t ep_id,uint8_t alarm_code,uint16_t cluster_id,uint32_t time_stamp)

{
  alarms_alarm_table_t *paVar1;
  ezb_err_t eVar2;
  alarms_alarm_table_entry_t *entry;
  uint uVar3;
  list_node_t *plVar4;
  
  paVar1 = get_alarm_table(ep_id);
  if (paVar1 == (alarms_alarm_table_t *)0x0) {
    eVar2 = 5;
  }
  else {
    if (paVar1->total <= paVar1->count) {
      alarm_table_pop_oldest(ep_id);
    }
    uVar3 = 0;
    do {
      if ((uint)paVar1->total <= (uVar3 & 0xff)) {
        DAT_00000004 = 0;
        ebreak();
      }
      entry = paVar1->entries + uVar3;
      uVar3 = uVar3 + 1;
    } while (entry != (alarms_alarm_table_entry_t *)(entry->node).next);
    entry->alarm_code = alarm_code;
    plVar4 = paVar1->tail;
    entry->cluster_id = cluster_id;
    entry->time_stamp = time_stamp;
    if (plVar4 == (list_node_t *)0x0) {
      (entry->node).next = (paVar1->active_alarms).head;
      (paVar1->active_alarms).head = &entry->node;
    }
    else {
      plVar4->next = &entry->node;
      (entry->node).next = (list_node_s *)0x0;
    }
    paVar1->tail = &entry->node;
    paVar1->count = paVar1->count + '\x01';
    alarm_table_store_entry(ep_id,entry);
    eVar2 = 0;
  }
  return eVar2;
}


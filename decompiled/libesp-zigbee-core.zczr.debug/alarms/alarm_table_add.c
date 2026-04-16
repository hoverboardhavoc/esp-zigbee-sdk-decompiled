/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_add
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
  
  paVar1 = get_alarm_table(ep_id);
  if (paVar1 == (alarms_alarm_table_t *)0x0) {
    eVar2 = 5;
  }
  else {
    if (paVar1->total <= paVar1->count) {
      alarm_table_pop_oldest(ep_id);
    }
    for (uVar3 = 0; uVar3 < paVar1->total; uVar3 = uVar3 + 1 & 0xff) {
      entry = paVar1->entries + uVar3;
      if (entry == (alarms_alarm_table_entry_t *)(entry->node).next) goto _L0;
    }
    entry = (alarms_alarm_table_entry_t *)0x0;
_L0:
    entry->alarm_code = alarm_code;
    entry->cluster_id = cluster_id;
    entry->time_stamp = time_stamp;
    if (paVar1->tail == (list_node_t *)0x0) {
      (entry->node).next = (paVar1->active_alarms).head;
      (paVar1->active_alarms).head = &entry->node;
      paVar1->tail = &entry->node;
    }
    else {
      paVar1->tail->next = &entry->node;
      (entry->node).next = (list_node_s *)0x0;
      paVar1->tail = &entry->node;
    }
    paVar1->count = paVar1->count + '\x01';
    alarm_table_store_entry(ep_id,entry);
    eVar2 = 0;
  }
  return eVar2;
}


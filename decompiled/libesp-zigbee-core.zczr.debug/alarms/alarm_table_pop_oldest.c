/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_pop_oldest
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

alarms_alarm_table_entry_t * alarm_table_pop_oldest(uint8_t ep_id)

{
  alarms_alarm_table_entry_t *paVar1;
  alarms_alarm_table_t *paVar2;
  
  paVar2 = get_alarm_table(ep_id);
  if (paVar2 == (alarms_alarm_table_t *)0x0) {
    paVar1 = (alarms_alarm_table_entry_t *)0x0;
  }
  else {
    paVar1 = (alarms_alarm_table_entry_t *)(paVar2->active_alarms).head;
    if (paVar1 != (alarms_alarm_table_entry_t *)0x0) {
      (paVar2->active_alarms).head = (paVar1->node).next;
      (paVar1->node).next = (list_node_s *)paVar1;
      if ((alarms_alarm_table_entry_t *)paVar2->tail == paVar1) {
        paVar2->tail = (list_node_t *)0x0;
      }
      paVar2->count = paVar2->count + 0xff;
      alarm_table_remove_stored_entry
                (ep_id,paVar1->alarm_code,paVar1->cluster_id,paVar1->time_stamp);
    }
  }
  return paVar1;
}


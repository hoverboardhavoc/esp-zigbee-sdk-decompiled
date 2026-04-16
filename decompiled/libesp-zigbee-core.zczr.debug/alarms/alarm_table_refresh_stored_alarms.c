/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_refresh_stored_alarms
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void alarm_table_refresh_stored_alarms(uint8_t ep_id)

{
  alarms_alarm_table_entry_t *entry;
  alarms_alarm_table_t *paVar1;
  
  alarm_table_remove_stored_all(ep_id);
  paVar1 = get_alarm_table(ep_id);
  if ((paVar1 != (alarms_alarm_table_t *)0x0) &&
     (entry = (alarms_alarm_table_entry_t *)(paVar1->active_alarms).head,
     entry != (alarms_alarm_table_entry_t *)0x0)) {
    for (; entry != (alarms_alarm_table_entry_t *)0x0;
        entry = (alarms_alarm_table_entry_t *)(entry->node).next) {
      alarm_table_store_entry(ep_id,entry);
    }
  }
  return;
}


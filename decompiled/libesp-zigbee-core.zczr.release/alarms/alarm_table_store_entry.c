/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarm_table_store_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void alarm_table_store_entry(uint8_t ep_id,alarms_alarm_table_entry_t *entry)

{
  uint32_t uStack_18;
  dataset_alarm_log_t log;
  
  uStack_18 = entry->time_stamp;
  log.time_stamp._0_2_ = entry->cluster_id;
  log.time_stamp._2_1_ = entry->alarm_code;
  log.time_stamp._3_1_ = ep_id;
  ds_internal_add_entry(0xc,&uStack_18);
  return;
}


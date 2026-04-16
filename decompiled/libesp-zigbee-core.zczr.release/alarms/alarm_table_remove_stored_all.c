/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarm_table_remove_stored_all
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void alarm_table_remove_stored_all(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  undefined1 auStack_1c [4];
  ds_alarm_log_iterator_t itor;
  
  itor.data.cluster_id = 0;
  itor.data.alarm_code = '\0';
  while (ds_alarm_log_itor_read((ds_alarm_log_iterator_t *)auStack_1c), itor.data.alarm_code == '\0'
        ) {
    if ((uint)itor.data.time_stamp._3_1_ == CONCAT31(in_register_00002029,ep_id)) {
      ds_internal_remove_entry(0xc,auStack_1c);
    }
    else {
      itor.data.cluster_id = itor.data.cluster_id + 1;
    }
  }
  return;
}


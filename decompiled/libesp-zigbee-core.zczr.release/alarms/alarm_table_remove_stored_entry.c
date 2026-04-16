/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarm_table_remove_stored_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void alarm_table_remove_stored_entry
               (uint8_t ep_id,uint8_t alarm_code,uint16_t cluster_id,uint32_t time_stamp)

{
  undefined3 in_register_00002029;
  undefined3 in_register_0000202d;
  undefined2 in_register_00002032;
  undefined1 auStack_2c [4];
  ds_alarm_log_iterator_t itor;
  
  itor.data.cluster_id = 0;
  itor.data.alarm_code = '\0';
  while( true ) {
    ds_alarm_log_itor_read((ds_alarm_log_iterator_t *)auStack_2c);
    if (itor.data.alarm_code != '\0') {
      return;
    }
    if (((((uint)itor.data.time_stamp._3_1_ == CONCAT31(in_register_00002029,ep_id)) &&
         ((uint)itor.data.time_stamp._2_1_ == CONCAT31(in_register_0000202d,alarm_code))) &&
        ((uint)(ushort)itor.data.time_stamp == CONCAT22(in_register_00002032,cluster_id))) &&
       (auStack_2c == (undefined1  [4])time_stamp)) break;
    itor.data.cluster_id = itor.data.cluster_id + 1;
  }
  ds_internal_remove_entry(0xc,auStack_2c);
  return;
}


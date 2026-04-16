/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> ds_alarm_log_itor_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ds_alarm_log_itor_read(ds_alarm_log_iterator_t *itor)

{
  uint16_t uVar1;
  int iVar2;
  
  uVar1 = itor->index;
  *(undefined2 *)&(itor->data).time_stamp = 0;
  *(undefined2 *)((int)&(itor->data).time_stamp + 2) = 0;
  (itor->data).cluster_id = 0;
  (itor->data).alarm_code = '\0';
  (itor->data).ep_id = '\0';
  iVar2 = ds_internal_read_entry(0xc,uVar1,itor,8);
  itor->is_done = iVar2 != 0;
  return;
}


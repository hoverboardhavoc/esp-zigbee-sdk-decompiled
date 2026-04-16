/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarm_table_print
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void alarm_table_print(uint8_t ep_id)

{
  list_node_t *plVar1;
  undefined3 in_register_00002029;
  alarms_alarm_table_t *paVar2;
  char cVar3;
  
  paVar2 = get_alarm_table(ep_id);
  if ((paVar2 != (alarms_alarm_table_t *)0x0) &&
     (log_write(3,"ZCL_ALARMS","alarm table ep_id=%u total=%u count=%u",
                CONCAT31(in_register_00002029,ep_id),paVar2->total,paVar2->count),
     paVar2->count != '\0')) {
    cVar3 = '\0';
    for (plVar1 = (paVar2->active_alarms).head; plVar1 != (list_node_t *)0x0; plVar1 = plVar1->next)
    {
      log_write(3,"ZCL_ALARMS","  [%u] alarm_code=0x%02x cluster_id=0x%04x time_stamp=%lu",cVar3,
                *(undefined1 *)&plVar1[1].next,*(undefined2 *)((int)&plVar1[1].next + 2),
                plVar1[2].next);
      cVar3 = cVar3 + '\x01';
    }
  }
  return;
}


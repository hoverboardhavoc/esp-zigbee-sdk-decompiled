/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> alarm_table_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t alarm_table_reset(uint8_t ep_id)

{
  byte bVar1;
  alarms_alarm_table_t *paVar2;
  ezb_err_t eVar3;
  uint uVar4;
  
  paVar2 = get_alarm_table(ep_id);
  if (paVar2 == (alarms_alarm_table_t *)0x0) {
    eVar3 = 5;
  }
  else {
    alarm_table_remove_stored_all(ep_id);
    bVar1 = paVar2->total;
    for (uVar4 = 0; (uVar4 & 0xff) < (uint)bVar1; uVar4 = uVar4 + 1) {
      paVar2->entries[uVar4].node.next = &paVar2->entries[uVar4].node;
    }
    paVar2->count = '\0';
    paVar2->tail = (list_node_t *)0x0;
    (paVar2->active_alarms).head = (list_node_t *)0x0;
    eVar3 = 0;
  }
  return eVar3;
}


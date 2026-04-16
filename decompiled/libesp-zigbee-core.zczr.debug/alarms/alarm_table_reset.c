/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t alarm_table_reset(uint8_t ep_id)

{
  alarms_alarm_table_t *paVar1;
  ezb_err_t eVar2;
  uint uVar3;
  
  paVar1 = get_alarm_table(ep_id);
  if (paVar1 == (alarms_alarm_table_t *)0x0) {
    eVar2 = 5;
  }
  else {
    alarm_table_remove_stored_all(ep_id);
    for (uVar3 = 0; uVar3 < paVar1->total; uVar3 = uVar3 + 1 & 0xff) {
      paVar1->entries[uVar3].node.next = &paVar1->entries[uVar3].node;
    }
    paVar1->count = '\0';
    paVar1->tail = (list_node_t *)0x0;
    (paVar1->active_alarms).head = (list_node_t *)0x0;
    eVar2 = 0;
  }
  return eVar2;
}


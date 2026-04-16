/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t alarm_table_remove(uint8_t ep_id,uint8_t alarm_code,uint16_t cluster_id)

{
  list_t *plVar1;
  alarms_alarm_table_t *paVar2;
  ezb_err_t eVar3;
  undefined3 in_register_0000202d;
  undefined2 in_register_00002032;
  list_t *plVar4;
  
  paVar2 = get_alarm_table(ep_id);
  if (paVar2 == (alarms_alarm_table_t *)0x0) {
    eVar3 = 5;
  }
  else {
    eVar3 = 5;
    plVar4 = &paVar2->active_alarms;
    while (plVar1 = plVar4, plVar4 = (list_t *)plVar1->head, plVar4 != (list_t *)0x0) {
      if (((uint)*(byte *)(plVar4 + 1) == CONCAT31(in_register_0000202d,alarm_code)) &&
         ((uint)*(ushort *)((int)(plVar4 + 1) + 2) == CONCAT22(in_register_00002032,cluster_id))) {
        if ((list_t *)paVar2->tail == plVar4) {
          if (plVar1 == &paVar2->active_alarms) {
            paVar2->tail = (list_node_t *)0x0;
          }
          else {
            paVar2->tail = (list_node_t *)plVar1;
          }
        }
        plVar1->head = plVar1->head->next;
        plVar4->head = (list_node_t *)plVar4;
        alarm_table_remove_stored_entry
                  (ep_id,*(uint8_t *)(plVar4 + 1),*(uint16_t *)((int)(plVar4 + 1) + 2),
                   (uint32_t)plVar4[2].head);
        paVar2->count = paVar2->count + 0xff;
        eVar3 = 0;
        plVar4 = plVar1;
      }
    }
  }
  return eVar3;
}


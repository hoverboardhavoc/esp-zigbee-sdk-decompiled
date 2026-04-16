/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> list.o -> list_reverse_order
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

list_node_t * list_reverse_order(list_node_t *head)

{
  list_node_t *plVar1;
  list_node_s *plVar2;
  
  plVar1 = (list_node_t *)0x0;
  while (head != (list_node_t *)0x0) {
    plVar2 = head->next;
    head->next = plVar1;
    plVar1 = head;
    head = plVar2;
  }
  return plVar1;
}


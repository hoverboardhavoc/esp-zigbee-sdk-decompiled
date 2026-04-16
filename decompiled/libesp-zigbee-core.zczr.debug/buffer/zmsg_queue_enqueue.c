/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_queue_enqueue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_queue_enqueue(zmsg_queue_t *q,zmsg_t *msg)

{
  zmsg_t *extraout_a1;
  dlist_node_s *pdVar1;
  
  if (((msg->node).next != (dlist_node_s *)0x0) && ((msg->node).prev != (dlist_node_s *)0x0)) {
    q = (zmsg_queue_t *)
        __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0x1e5,"zmsg_queue_enqueue",
                      "!dlist_node_is_on_list(&msg->node)");
    msg = extraout_a1;
  }
  pdVar1 = (q->list).prev;
  (q->list).prev = &msg->node;
  (msg->node).next = &q->list;
  (msg->node).prev = pdVar1;
  pdVar1->next = &msg->node;
  q->length = q->length + 1;
  return;
}


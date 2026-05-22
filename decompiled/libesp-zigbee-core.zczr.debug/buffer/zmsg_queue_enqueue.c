/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x1e5,
                      "zmsg_queue_enqueue","!dlist_node_is_on_list(&msg->node)");
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


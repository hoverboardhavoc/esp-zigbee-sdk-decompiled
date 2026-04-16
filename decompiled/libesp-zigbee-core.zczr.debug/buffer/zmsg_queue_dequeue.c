/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_queue_dequeue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_queue_dequeue(zmsg_queue_t *q,zmsg_t *msg)

{
  zmsg_queue_t *q_00;
  zmsg_t *msg_00;
  dlist_node_s *pdVar1;
  dlist_node_s *pdVar2;
  
  pdVar2 = (msg->node).next;
  if ((pdVar2 != (dlist_node_s *)0x0) && (pdVar1 = (msg->node).prev, pdVar1 != (dlist_node_s *)0x0))
  {
    pdVar2->prev = pdVar1;
    pdVar1->next = pdVar2;
    (msg->node).next = (dlist_node_s *)0x0;
    (msg->node).prev = (dlist_node_s *)0x0;
    q->length = q->length - 1;
    return;
  }
  q_00 = (zmsg_queue_t *)
         __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0x1ed,"zmsg_queue_dequeue",
                       "dlist_node_is_on_list(&msg->node)");
  zmsg_queue_dequeue(q_00,msg_00);
  zmsg_free(msg_00);
  return;
}


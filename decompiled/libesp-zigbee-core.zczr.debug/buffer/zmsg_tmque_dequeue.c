/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_tmque_dequeue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_tmque_dequeue(zmsg_tmque_t *q,zmsg_t *msg)

{
  zmsg_tmque_t *pzVar1;
  
  pzVar1 = (zmsg_tmque_t *)(q->mq).list.next;
  if (((zmsg_tmque_t *)msg == pzVar1) &&
     ((q == pzVar1 || (pzVar1 != (zmsg_tmque_t *)(q->mq).list.prev)))) {
    micro_timer_fire_at(&q->tm,(msg->node).next[3].next);
  }
  zmsg_queue_dequeue(&q->mq,msg);
  return;
}


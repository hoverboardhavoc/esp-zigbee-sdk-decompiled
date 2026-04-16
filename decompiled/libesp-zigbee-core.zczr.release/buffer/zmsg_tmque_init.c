/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_tmque_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_tmque_init(zmsg_tmque_t *q,zmsg_tmque_timeout_handler handler)

{
  q->handler = handler;
  (q->mq).list.next = (dlist_node_s *)q;
  (q->mq).list.prev = (dlist_node_s *)q;
  (q->mq).length = 0;
  micro_timer_init(&q->tm,zmsg_tmq_handle_timer,q);
  return;
}


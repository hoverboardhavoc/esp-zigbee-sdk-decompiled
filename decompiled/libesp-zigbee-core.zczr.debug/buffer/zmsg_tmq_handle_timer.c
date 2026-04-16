/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_tmq_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_tmq_handle_timer(zmsg_tmque_t *q)

{
  zmsg_tmque_t *msg;
  int iVar1;
  zmsg_t *pzVar2;
  dlist_node_s *pdVar3;
  
  iVar1 = micro_timer_get_now();
  msg = (zmsg_tmque_t *)(q->mq).list.next;
  while ((msg != q && (-1 < (int)(iVar1 - (msg->tm).fire_time.val)))) {
    pdVar3 = (msg->mq).list.prev;
    zmsg_queue_dequeue(&q->mq,(zmsg_t *)msg);
    if (q->handler == (zmsg_tmque_timeout_handler)0x0) {
      zmsg_free((zmsg_t *)msg);
    }
    else {
      (*q->handler)((zmsg_t *)msg);
    }
    msg = (zmsg_tmque_t *)pdVar3->next;
  }
  pzVar2 = zmsg_tmque_get_head(q);
  if (pzVar2 != (zmsg_t *)0x0) {
    micro_timer_fire_at(&q->tm,(pzVar2->timestamp).val);
  }
  return;
}


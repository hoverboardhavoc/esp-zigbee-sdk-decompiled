/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_tmque_enqueue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_tmque_enqueue(zmsg_tmque_t *q,zmsg_t *msg,uint32_t tmo_ms)

{
  uint16_t uVar1;
  int iVar2;
  zmsg_t *extraout_a1;
  uint32_t uVar3;
  dlist_node_s *pdVar4;
  zmsg_tmque_t *pzVar5;
  
  if (tmo_ms == 0) {
    q = (zmsg_tmque_t *)__assert_func(0,0,0);
    msg = extraout_a1;
  }
  iVar2 = micro_timer_get_now();
  pzVar5 = (zmsg_tmque_t *)(q->mq).list.next;
  uVar3 = tmo_ms * 1000 + iVar2;
  (msg->timestamp).val = uVar3;
  while ((pzVar5 != q && ((int)((pzVar5->tm).fire_time.val - uVar3) < 0))) {
    pzVar5 = (zmsg_tmque_t *)(pzVar5->mq).list.next;
  }
  pdVar4 = (pzVar5->mq).list.prev;
  (pzVar5->mq).list.prev = &msg->node;
  (msg->node).next = (dlist_node_s *)pzVar5;
  uVar1 = (q->mq).length;
  (msg->node).prev = pdVar4;
  pdVar4->next = &msg->node;
  (q->mq).length = uVar1 + 1;
  if (msg == (zmsg_t *)(q->mq).list.next) {
    micro_timer_fire_at(&q->tm);
    return;
  }
  return;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_tmque_dequeue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_tmque_dequeue(zmsg_tmque_t *q,zmsg_t *msg)

{
  uint16_t uVar1;
  zmsg_t *pzVar2;
  zmsg_t *q_00;
  int iVar3;
  dlist_node_s *pdVar4;
  dlist_node_s *pdVar5;
  
  if ((msg == (zmsg_t *)(q->mq).list.next) &&
     ((q == (zmsg_tmque_t *)msg || (msg != (zmsg_t *)(q->mq).list.prev)))) {
    micro_timer_fire_at(&q->tm,(msg->node).next[3].next);
  }
  pdVar4 = (msg->node).next;
  if ((pdVar4 != (dlist_node_s *)0x0) && (pdVar5 = (msg->node).prev, pdVar5 != (dlist_node_s *)0x0))
  {
    pdVar4->prev = pdVar5;
    pdVar5->next = pdVar4;
    uVar1 = (q->mq).length;
    (msg->node).next = (dlist_node_s *)0x0;
    (msg->node).prev = (dlist_node_s *)0x0;
    (q->mq).length = uVar1 - 1;
    return;
  }
  zmsg_remove_header((zmsg_t *)q,(uint16_t)msg);
  iVar3 = micro_timer_get_now();
  pzVar2 = (zmsg_t *)(q_00->node).next;
  while ((pzVar2 != q_00 && (-1 < (int)(iVar3 - (pzVar2->timestamp).val)))) {
    pdVar5 = (pzVar2->node).prev;
    zmsg_queue_dequeue((zmsg_queue_t *)q_00,pzVar2);
    pdVar4 = q_00[1].node.next;
    if (pdVar4 == (dlist_node_s *)0x0) {
      zmsg_free(pzVar2);
    }
    else {
      (*(code *)pdVar4)();
    }
    pzVar2 = (zmsg_t *)pdVar5->next;
  }
  pzVar2 = (zmsg_t *)(q_00->node).next;
  if ((q_00 != pzVar2) && (pzVar2 != (zmsg_t *)0x0)) {
    micro_timer_fire_at(&q_00->header,(pzVar2->timestamp).val);
    return;
  }
  return;
}


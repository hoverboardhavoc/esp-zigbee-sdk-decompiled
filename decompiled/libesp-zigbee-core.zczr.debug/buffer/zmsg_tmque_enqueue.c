/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_tmque_enqueue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_tmque_enqueue(zmsg_tmque_t *q,zmsg_t *msg,uint32_t tmo_ms)

{
  zmsg_tmque_t *m1;
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  dlist_node_s *pdVar3;
  
  if (tmo_ms == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x240,
                  "zmsg_tmque_enqueue","tmo_ms != 0");
    m1 = (zmsg_tmque_t *)0x0;
  }
  else {
    iVar2 = micro_timer_get_now();
    (msg->timestamp).val = tmo_ms * 1000 + iVar2;
    m1 = (zmsg_tmque_t *)(q->mq).list.next;
    while ((m1 != q &&
           (_Var1 = zmsg_timestamp_ge((zmsg_t *)m1,msg), CONCAT31(extraout_var,_Var1) == 0))) {
      m1 = (zmsg_tmque_t *)(m1->mq).list.next;
    }
  }
  pdVar3 = (m1->mq).list.prev;
  (m1->mq).list.prev = &msg->node;
  (msg->node).next = (dlist_node_s *)m1;
  (msg->node).prev = pdVar3;
  pdVar3->next = &msg->node;
  (q->mq).length = (q->mq).length + 1;
  if (msg == (zmsg_t *)(q->mq).list.next) {
    micro_timer_fire_at(&q->tm,(msg->timestamp).val);
  }
  return;
}


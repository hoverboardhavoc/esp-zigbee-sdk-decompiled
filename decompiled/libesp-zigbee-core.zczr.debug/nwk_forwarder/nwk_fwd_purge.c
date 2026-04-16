/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_purge
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: msg_dst_addr */
/* WARNING: Unknown calling convention */

void nwk_fwd_purge(ezb_shortaddr_t dst_addr)

{
  nwk_fwd_s *pnVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  nwk_fwd_s *pnVar3;
  ushort auStack_12 [2];
  ezb_shortaddr_t msg_dst_addr;
  
  uVar2 = CONCAT22(in_register_0000202a,dst_addr);
  pnVar1 = (nwk_fwd_s *)s_nwk_fwd.send_queue.list.next;
  while (pnVar3 = (nwk_fwd_s *)s_nwk_fwd.delay_queue.mq.list.next, pnVar1 != &s_nwk_fwd) {
    zmsg_read_bytes(pnVar1,2,auStack_12);
    if ((uVar2 == 0xffff) || (pnVar3 = pnVar1, auStack_12[0] == uVar2)) {
      pnVar3 = (nwk_fwd_s *)(pnVar1->send_queue).list.prev;
      zmsg_queue_dequeue(&s_nwk_fwd,pnVar1);
      nwk_fwd_finish_tx((zmsg_t *)pnVar1,8);
    }
    pnVar1 = (nwk_fwd_s *)(pnVar3->send_queue).list.next;
  }
  while (pnVar3 != &s_nwk_fwd) {
    zmsg_read_bytes(pnVar3,2,auStack_12);
    if ((uVar2 == 0xffff) || (pnVar1 = pnVar3, auStack_12[0] == uVar2)) {
      pnVar1 = (nwk_fwd_s *)(pnVar3->send_queue).list.prev;
      zmsg_tmque_dequeue(&s_nwk_fwd,pnVar3);
      nwk_fwd_finish_tx((zmsg_t *)pnVar3,8);
    }
    pnVar3 = (nwk_fwd_s *)(pnVar1->send_queue).list.next;
  }
  return;
}


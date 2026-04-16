/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_purge
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_purge(ezb_shortaddr_t dst_addr)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  nwk_fwd_s *pnVar2;
  nwk_fwd_s *pnVar3;
  ushort auStack_22 [2];
  ezb_shortaddr_t msg_dst_addr;
  
  uVar1 = CONCAT22(in_register_0000202a,dst_addr);
  pnVar2 = (nwk_fwd_s *)s_nwk_fwd.send_queue.list.next;
  while (pnVar3 = (nwk_fwd_s *)s_nwk_fwd.delay_queue.mq.list.next, pnVar2 != &s_nwk_fwd) {
    zmsg_read_le16((zmsg_t *)pnVar2,2,auStack_22);
    if ((uVar1 == 0xffff) || (pnVar3 = pnVar2, auStack_22[0] == uVar1)) {
      pnVar3 = (nwk_fwd_s *)(pnVar2->send_queue).list.prev;
      zmsg_queue_dequeue(&s_nwk_fwd,pnVar2);
      nwk_fwd_finish_tx((zmsg_t *)pnVar2,8);
    }
    pnVar2 = (nwk_fwd_s *)(pnVar3->send_queue).list.next;
  }
  while (pnVar3 != &s_nwk_fwd) {
    zmsg_read_le16((zmsg_t *)pnVar3,2,auStack_22);
    if ((uVar1 == 0xffff) || (pnVar2 = pnVar3, auStack_22[0] == uVar1)) {
      pnVar2 = (nwk_fwd_s *)(pnVar3->send_queue).list.prev;
      zmsg_tmque_dequeue(&s_nwk_fwd,pnVar3);
      nwk_fwd_finish_tx((zmsg_t *)pnVar3,8);
    }
    pnVar3 = (nwk_fwd_s *)(pnVar2->send_queue).list.next;
  }
  return;
}


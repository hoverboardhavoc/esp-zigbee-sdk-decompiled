/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_purge_ex
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_purge_ex(ezb_shortaddr_t dst_addr,_func__Bool_zmsg_t_ptr_void_ptr *filter,
                     void *user_ctx)

{
  nwk_fwd_s *pnVar1;
  _Bool _Var2;
  undefined2 in_register_0000202a;
  uint uVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  nwk_fwd_s *pnVar4;
  ushort auStack_22 [2];
  ezb_shortaddr_t msg_dst_addr;
  
  uVar3 = CONCAT22(in_register_0000202a,dst_addr);
  pnVar1 = (nwk_fwd_s *)s_nwk_fwd.send_queue.list.next;
  while (pnVar4 = (nwk_fwd_s *)s_nwk_fwd.delay_queue.mq.list.next, pnVar1 != &s_nwk_fwd) {
    zmsg_read_bytes(pnVar1,2,auStack_22);
    pnVar4 = pnVar1;
    if (((uVar3 == 0xffff) || (auStack_22[0] == uVar3)) &&
       ((filter == (_func__Bool_zmsg_t_ptr_void_ptr *)0x0 ||
        (_Var2 = (*filter)((zmsg_t *)pnVar1,user_ctx), CONCAT31(extraout_var,_Var2) != 0)))) {
      pnVar4 = (nwk_fwd_s *)(pnVar1->send_queue).list.prev;
      zmsg_queue_dequeue(&s_nwk_fwd,pnVar1);
      nwk_fwd_finish_tx((zmsg_t *)pnVar1,8);
    }
    pnVar1 = (nwk_fwd_s *)(pnVar4->send_queue).list.next;
  }
  while (pnVar4 != &s_nwk_fwd) {
    zmsg_read_bytes(pnVar4,2,auStack_22);
    pnVar1 = pnVar4;
    if (((uVar3 == 0xffff) || (auStack_22[0] == uVar3)) &&
       ((filter == (_func__Bool_zmsg_t_ptr_void_ptr *)0x0 ||
        (_Var2 = (*filter)((zmsg_t *)pnVar4,user_ctx), CONCAT31(extraout_var_00,_Var2) != 0)))) {
      pnVar1 = (nwk_fwd_s *)(pnVar4->send_queue).list.prev;
      zmsg_tmque_dequeue(&s_nwk_fwd,pnVar4);
      nwk_fwd_finish_tx((zmsg_t *)pnVar4,8);
    }
    pnVar4 = (nwk_fwd_s *)(pnVar1->send_queue).list.next;
  }
  return;
}


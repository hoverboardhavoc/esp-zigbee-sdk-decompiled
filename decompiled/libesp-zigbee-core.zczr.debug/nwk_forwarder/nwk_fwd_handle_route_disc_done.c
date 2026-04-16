/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_route_disc_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_handle_route_disc_done(ezb_shortaddr_t dst_addr,ezb_err_t error)

{
  nwk_fwd_s *msg;
  undefined2 in_register_0000202a;
  nwk_fwd_s *pnVar1;
  ushort auStack_22 [2];
  ezb_shortaddr_t msg_dst;
  
  msg = (nwk_fwd_s *)s_nwk_fwd.send_queue.list.next;
  while (msg != &s_nwk_fwd) {
    pnVar1 = msg;
    if ((*(ushort *)&(msg->delay_queue).mq.field_0xa & 0x10) != 0) {
      zmsg_read_bytes(msg,2,auStack_22);
      if ((uint)auStack_22[0] == CONCAT22(in_register_0000202a,dst_addr)) {
        if (error == 0) {
          *(ushort *)&(msg->delay_queue).mq.field_0xa =
               *(ushort *)&(msg->delay_queue).mq.field_0xa & 0xffef;
        }
        else {
          pnVar1 = (nwk_fwd_s *)(msg->send_queue).list.prev;
          zmsg_queue_dequeue(&s_nwk_fwd,msg);
          nwk_fwd_finish_tx((zmsg_t *)msg,error);
        }
      }
    }
    msg = (nwk_fwd_s *)(pnVar1->send_queue).list.next;
  }
  return;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_prepare_next_direct_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zmsg_t * nwk_fwd_prepare_next_direct_tx(nwk_tx_info_t *tx_info)

{
  nwk_fwd_s *msg;
  ezb_err_t error;
  zmsg_t *prev;
  nwk_fwd_s *pnVar1;
  
  msg = (nwk_fwd_s *)s_nwk_fwd.send_queue.list.next;
  do {
    if (msg == &s_nwk_fwd) {
      return (zmsg_t *)0x0;
    }
    pnVar1 = msg;
    if ((*(ushort *)&(msg->delay_queue).mq.field_0xa & 0x10) == 0) {
      error = nwk_fwd_update_route((zmsg_t *)msg,tx_info);
      if (error == 0) {
        return (zmsg_t *)msg;
      }
      if (error == 0xc) {
        *(ushort *)&(msg->delay_queue).mq.field_0xa =
             *(ushort *)&(msg->delay_queue).mq.field_0xa | 0x10;
      }
      else {
        pnVar1 = (nwk_fwd_s *)(msg->send_queue).list.prev;
        zmsg_queue_dequeue(&s_nwk_fwd,msg);
        nwk_fwd_finish_tx((zmsg_t *)msg,error);
      }
    }
    msg = (nwk_fwd_s *)(pnVar1->send_queue).list.next;
  } while( true );
}


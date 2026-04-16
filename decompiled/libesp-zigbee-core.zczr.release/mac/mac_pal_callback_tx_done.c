/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_pal_callback_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_pal_callback_tx_done(ezb_radio_frame_t *frame,ezb_radio_frame_t *ack,ezb_err_t tx_error)

{
  mac_device *dev;
  mac_operation_t op;
  uint uVar1;
  int iVar2;
  _Bool is_indirect;
  zmsg_queue_t *q;
  
  dev = s_devices;
  op = (mac_operation_t)(s_devices->ctx).cur_op;
  if (op == MAC_OPERATION_TRANSMIT_POLL) {
    if ((frame->length != '\0') && ((*(ushort *)frame->psdu & 0x20) == 0)) {
_L0:
      do {
        tx_error = 0;
        __assert_func(0,0,0);
_L0:
        if (op == MAC_OPERATION_TRANSMIT_BEACON) {
          (dev->ctx).cur_op = '\0';
          goto _L0;
        }
      } while (op != MAC_OPERATION_TRANSMIT_INDIRECT);
      (dev->ctx).cur_op = '\0';
      q = &(dev->ctx).itx_q;
      is_indirect = true;
      goto _L0;
    }
    (s_devices->ctx).cur_op = '\0';
    if (tx_error != 0) {
_L0:
      mac_report_poll_result(dev,(mac_status_t)tx_error);
      goto _L0;
    }
    if (ack == (ezb_radio_frame_t *)0x0) goto _L0;
    op = MAC_OPERATION_WAITING_FOR_DATA;
    tx_error = 0x1eb;
    if ((*(ushort *)ack->psdu & 0x10) == 0) goto _L0;
  }
  else {
    if (MAC_OPERATION_TRANSMIT_POLL < op) goto _L0;
    if (op == MAC_OPERATION_TRANSMIT_ASSO_REQ) {
      iVar2 = (uint)(s_devices->pib).rsp_wait_time * 0x3c00;
_L0:
      micro_timer_start(&(s_devices->ctx).operation_timer,iVar2);
      return;
    }
    if (op != MAC_OPERATION_TRANSMIT_DATA_DIRECT) {
      if (op == MAC_OPERATION_ACTIVE_SCAN) {
        uVar1 = ((1 << ((s_devices->ctx).scan_duration & 0x1f)) + 1) * 0x3c00;
        iVar2 = uVar1 - uVar1 % 1000;
        goto _L0;
      }
      goto _L0;
    }
    (s_devices->ctx).cur_op = '\0';
    q = &(dev->ctx).tx_q;
    is_indirect = false;
_L0:
    mac_handle_tx_done(dev,q,tx_error,is_indirect);
    iVar2 = zmsg_queue_get_head(q);
    if (iVar2 == 0) goto _L0;
  }
  mac_start_op(dev,op);
_L0:
  mac_perform_next_op(dev);
  return;
}


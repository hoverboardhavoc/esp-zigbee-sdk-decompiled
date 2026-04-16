/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_transmit_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void mac_handle_transmit_done
               (mac_device *dev,ezb_radio_frame_t *frame,ezb_radio_frame_t *ack,ezb_err_t tx_error)

{
  byte bVar1;
  zmsg_queue_t *pzVar2;
  uint32_t uVar3;
  int iVar4;
  
  bVar1 = (dev->ctx).cur_op;
  if (bVar1 != 5) {
    if (bVar1 < 6) {
      if (bVar1 == 3) {
        mac_start_timer(dev,(ushort)(dev->pib).rsp_wait_time);
        return;
      }
      if (bVar1 == 4) {
        mac_finish_op(dev);
        pzVar2 = &(dev->ctx).tx_q;
        mac_handle_tx_done(dev,pzVar2,tx_error,false);
        iVar4 = zmsg_queue_get_head(pzVar2);
        if (iVar4 != 0) {
          mac_start_op(dev,MAC_OPERATION_TRANSMIT_DATA_DIRECT);
        }
        mac_perform_next_op(dev);
        return;
      }
      if (bVar1 == 1) {
        uVar3 = mac_scan_duration_to_msec((dev->ctx).scan_duration);
        micro_timer_start(&(dev->ctx).operation_timer,uVar3 * 1000);
        return;
      }
    }
    else {
      if (bVar1 == 7) {
        mac_finish_op(dev);
        mac_perform_next_op(dev);
        return;
      }
      if (bVar1 == 8) {
        mac_finish_op(dev);
        pzVar2 = &(dev->ctx).itx_q;
        mac_handle_tx_done(dev,pzVar2,tx_error,true);
        iVar4 = zmsg_queue_get_head(pzVar2);
        if (iVar4 != 0) {
          mac_start_op(dev,MAC_OPERATION_TRANSMIT_INDIRECT);
        }
        mac_perform_next_op(dev);
        return;
      }
    }
    __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x538,"mac_handle_transmit_done",&_L0);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((frame->length == '\0') || ((*(ushort *)frame->psdu >> 5 & 1) != 0)) {
    mac_finish_op(dev);
    if (tx_error == 0) {
      if (ack == (ezb_radio_frame_t *)0x0) goto _L0;
      if ((*(ushort *)ack->psdu & 0x10) != 0) goto _L0;
      tx_error = 0x1eb;
    }
    mac_report_poll_result(dev,(mac_status_t)tx_error);
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x507,"mac_handle_transmit_done",
                  "frame->length == 0 || mac_frame_is_ack_required(frame)");
_L0:
    mac_start_op(dev,MAC_OPERATION_WAITING_FOR_DATA);
  }
_L0:
  mac_perform_next_op(dev);
  return;
}


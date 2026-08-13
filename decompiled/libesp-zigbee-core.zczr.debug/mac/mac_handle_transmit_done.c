/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_transmit_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void mac_handle_transmit_done(int param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 0x2e);
  if (bVar1 != 5) {
    if (bVar1 < 6) {
      if (bVar1 == 3) {
        mac_start_timer(*(undefined1 *)(param_1 + 0x1f));
        return;
      }
      if (bVar1 == 4) {
        mac_finish_op();
        mac_handle_tx_done(param_1,param_1 + 0x48,param_4,0);
        iVar2 = zmsg_queue_get_head(param_1 + 0x48);
        if (iVar2 != 0) {
          mac_start_op(param_1,4);
        }
        mac_perform_next_op(param_1);
        return;
      }
      if (bVar1 == 1) {
        iVar2 = mac_scan_duration_to_msec(*(undefined1 *)(param_1 + 0x33));
        micro_timer_start(param_1 + 0x8c,iVar2 * 1000);
        return;
      }
    }
    else {
      if (bVar1 == 7) {
        mac_finish_op();
        mac_perform_next_op(param_1);
        return;
      }
      if (bVar1 == 8) {
        mac_finish_op();
        mac_handle_tx_done(param_1,param_1 + 0x54,param_4,1);
        iVar2 = zmsg_queue_get_head(param_1 + 0x54);
        if (iVar2 != 0) {
          mac_start_op(param_1,8);
        }
        mac_perform_next_op(param_1);
        return;
      }
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x57e,
                  "mac_handle_transmit_done",&_LC8);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if ((*(char *)(param_2 + 1) == '\0') || ((*(ushort *)*param_2 >> 5 & 1) != 0)) {
    mac_finish_op(param_1);
    if (param_4 == 0) {
      if (param_3 == (undefined4 *)0x0) goto _L0;
      if ((*(ushort *)*param_3 & 0x10) != 0) goto _L0;
      param_4 = 0x1eb;
    }
    mac_report_poll_result(param_1,param_4 & 0xff);
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x54d,
                  "mac_handle_transmit_done",
                  "frame->length == 0 || mac_frame_is_ack_required(frame)");
_L0:
    mac_start_op(param_1,6);
  }
_L0:
  mac_perform_next_op(param_1);
  return;
}


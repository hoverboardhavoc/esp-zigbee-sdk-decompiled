/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_handle_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_handle_ack(undefined2 *param_1,undefined4 param_2,byte param_3)

{
  int unaff_s0;
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = (*(byte *)(param_1 + 6) & 3) - 2;
  if (uVar3 == 0) {
    iVar1 = core_globals_get();
    unaff_s0 = aps_retrans_find(iVar1 + 0x38,*param_1,*(undefined1 *)((int)param_1 + 0xd));
    if (unaff_s0 == 0) goto _L0;
    param_3 = *(byte *)(unaff_s0 + 0x1e);
    uVar3 = ~(uint)param_3 & 0xff;
    if (*(char *)(param_1 + 6) < '\0') goto _L0;
_L0:
    if ((*(uint *)(unaff_s0 + 0x18) & 0xffff0000) == 0x10000) {
      uVar3 = uVar3 & 1;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x10d,
                  "aps_retrans_handle_ack","aps_fcf_get_frame_type(aps_hdr->fcf) == APS_FRAME_ACK");
_L0:
    bVar2 = *(byte *)((int)param_1 + 0x11) & 3;
    if ((bVar2 != 1) && (bVar2 != 2)) goto _L0;
    if (*(char *)(unaff_s0 + 0x1b) == *(char *)(param_1 + 9)) {
      uVar3 = uVar3 & *(byte *)((int)param_1 + 0x13);
    }
  }
  if (uVar3 != 0) {
    *(byte *)(unaff_s0 + 0x1e) = param_3 | (byte)uVar3;
    *(undefined1 *)(unaff_s0 + 0x18) = 1;
    if (*(char *)(unaff_s0 + 0x1c) == '\0') {
      milli_timer_stop(unaff_s0 + 8);
      milli_timer_start(unaff_s0 + 8,0x640);
    }
  }
  if (*(char *)(unaff_s0 + 0x1e) == -1) {
    milli_timer_stop(unaff_s0 + 8);
    iVar1 = aps_tx_window_move_next(unaff_s0 + 0x1a);
    if (iVar1 == 0) {
      aps_retrans_send_confirm(unaff_s0,0);
    }
    else {
      *(undefined1 *)(unaff_s0 + 0x18) = 0;
      aps_retrans_send(unaff_s0);
    }
  }
_L0:
  zmsg_free(param_2);
  return;
}


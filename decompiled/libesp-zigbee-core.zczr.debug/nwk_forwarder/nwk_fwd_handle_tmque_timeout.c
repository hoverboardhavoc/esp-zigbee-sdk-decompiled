/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_tmque_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_tmque_timeout(undefined4 param_1)

{
  int iVar1;
  undefined2 uStack_14;
  undefined1 auStack_11 [9];
  
  zmsg_read_bytes(7,1,auStack_11);
  zmsg_read_bytes(param_1,4,2,&uStack_14);
  iVar1 = nwk_btt_find(uStack_14,auStack_11[0]);
  if ((iVar1 == 0) || (iVar1 = nwk_btr_is_all_acked(), iVar1 == 0)) {
    nwk_fwd_do_send_msg(param_1);
  }
  else {
    nwk_fwd_finish_tx(param_1,0);
  }
  return;
}


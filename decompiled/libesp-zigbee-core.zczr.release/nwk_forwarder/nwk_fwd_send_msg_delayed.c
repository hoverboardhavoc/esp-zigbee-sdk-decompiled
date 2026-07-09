/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_send_msg_delayed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_send_msg_delayed(int param_1,int param_2)

{
  int iVar1;
  ushort uStack_14;
  ushort auStack_12 [3];
  
  zmsg_read_le16_isra_0(0,&uStack_14);
  iVar1 = nwk_is_device_zczr();
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xa28) != '\0') {
      uStack_14 = uStack_14 | 0x2000;
    }
  }
  else {
    uStack_14 = uStack_14 & 0xdfff;
  }
  auStack_12[0] = uStack_14;
  zmsg_write_bytes(param_1,0,2,auStack_12);
  *(undefined1 *)(param_1 + 0x14) = 0;
  if (param_2 == 0) {
    nwk_fwd_do_send_msg(param_1);
  }
  else {
    zmsg_tmque_enqueue(&s_nwk_fwd,param_1,param_2);
  }
  return;
}


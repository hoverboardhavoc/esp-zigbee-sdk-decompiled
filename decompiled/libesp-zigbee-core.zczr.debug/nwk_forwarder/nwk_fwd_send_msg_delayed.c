/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_send_msg_delayed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_send_msg_delayed(int param_1,undefined4 param_2)

{
  int iVar1;
  ushort uStack_14;
  ushort auStack_12 [3];
  
  zmsg_read_bytes(0,2,auStack_12);
  iVar1 = nwk_is_device_zczr();
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xa28) != '\0') {
      auStack_12[0] = auStack_12[0] | 0x2000;
    }
  }
  else {
    auStack_12[0] = auStack_12[0] & 0xdfff;
  }
  uStack_14 = auStack_12[0];
  zmsg_write_bytes(param_1,0,2,&uStack_14);
  *(undefined1 *)(param_1 + 0x14) = 0;
  nwk_fwd_retry(param_1,param_2);
  return;
}


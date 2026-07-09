/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_intrp_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_intrp_confirm(int *param_1)

{
  int iVar1;
  uint uVar2;
  ushort auStack_12 [3];
  
  iVar1 = *param_1;
  auStack_12[0] = 0;
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x3e2,
                  "nwk_fwd_handle_intrp_confirm",&_L0);
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x3e6,
                  "nwk_fwd_handle_intrp_confirm","nwk_fcf_get_frame_type(fcf) == NWK_FRAME_INTRP");
  }
  else {
    zmsg_read_bytes(iVar1,0,2,auStack_12);
    if ((auStack_12[0] & 3) != 3) goto _L0;
    if (*(byte *)(param_1 + 1) != 0) {
      uVar2 = *(byte *)(param_1 + 1) | 0x200;
      goto _L0;
    }
  }
  uVar2 = 0;
_L0:
  nwk_handle_intrp_data_sent(iVar1,uVar2);
  return;
}


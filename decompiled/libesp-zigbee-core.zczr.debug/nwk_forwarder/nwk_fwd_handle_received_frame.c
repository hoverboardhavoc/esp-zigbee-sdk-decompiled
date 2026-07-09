/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_received_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_received_frame(char param_1,int param_2)

{
  ushort uVar1;
  
  if (((*(ushort **)(param_2 + 0x24) != (ushort *)0x0) && (*(byte *)(param_2 + 0x20) != 0)) &&
     (2 < *(byte *)(param_2 + 0x20))) {
    uVar1 = **(ushort **)(param_2 + 0x24);
    if ((uVar1 & 0x3c) == 8) {
      if ((uVar1 & 3) == 3) {
        nwk_fwd_handle_intrp_frame((int)param_1);
      }
      else {
        nwk_fwd_handle_nwk_frame();
      }
    }
  }
  return;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_data_confirm(undefined4 param_1,int *param_2)

{
  ushort auStack_12 [3];
  
  auStack_12[0] = 0;
  if (*param_2 != 0) {
    zmsg_read_bytes(0,2,auStack_12);
    if ((auStack_12[0] & 0x3c) == 8) {
      if ((auStack_12[0] & 3) == 3) {
        nwk_fwd_handle_intrp_confirm(param_1,param_2);
      }
      else {
        nwk_fwd_handle_nwk_confirm(param_1,param_2);
      }
    }
  }
  return;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_frame_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_frame_confirm(undefined4 param_1,undefined4 param_2)

{
  byte abStack_11 [5];
  
  zmsg_read_bytes(0,1,abStack_11);
  if ((abStack_11[0] & 3) == 0) {
    aps_send_data_confirm(param_1,param_2);
  }
  else if ((abStack_11[0] & 3) == 1) {
    aps_send_cmd_confirm(param_1,param_2);
  }
  else {
    zmsg_free(param_1);
  }
  return;
}


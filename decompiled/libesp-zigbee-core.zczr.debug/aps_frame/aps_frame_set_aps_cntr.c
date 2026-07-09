/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_set_aps_cntr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_frame_set_aps_cntr(undefined4 param_1,undefined1 param_2)

{
  short sVar1;
  undefined1 uStack_12;
  undefined1 auStack_11 [5];
  
  zmsg_read_bytes(0,1,auStack_11);
  sVar1 = aps_fcf_get_hdr_size(auStack_11[0]);
  uStack_12 = param_2;
  zmsg_write_bytes(param_1,sVar1 + -1,1,&uStack_12);
  return;
}


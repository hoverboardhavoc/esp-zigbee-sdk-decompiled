/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_frame.o -> nwk_frame_remove_dst_extaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_frame_remove_dst_extaddr(undefined4 param_1)

{
  ushort uStack_14;
  ushort auStack_12 [5];
  
  zmsg_read_bytes(0,2,auStack_12);
  if ((auStack_12[0] & 0x800) != 0) {
    zmsg_delete_header(param_1,8);
    uStack_14 = auStack_12[0] & 0xf7ff;
    auStack_12[0] = uStack_14;
    zmsg_write_bytes(param_1,0,2,&uStack_14);
  }
  return;
}


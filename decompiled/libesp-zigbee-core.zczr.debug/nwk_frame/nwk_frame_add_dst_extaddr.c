/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_frame.o -> nwk_frame_add_dst_extaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_frame_add_dst_extaddr(undefined4 param_1,undefined4 *param_2)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  ushort auStack_12 [3];
  
  zmsg_read_bytes(0,2,auStack_12);
  if ((auStack_12[0] & 0x800) == 0) {
    zmsg_insert_header(param_1,8);
    local_20 = CONCAT22(local_20._2_2_,auStack_12[0]) | 0x800;
    auStack_12[0] = auStack_12[0] | 0x800;
    zmsg_write_bytes(param_1,0,2,&local_20);
  }
  local_20 = *param_2;
  uStack_1c = param_2[1];
  zmsg_write_bytes(param_1,8,&local_20);
  return;
}


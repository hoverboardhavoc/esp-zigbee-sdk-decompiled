/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_frame.o -> nwk_frame_add_dst_extaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_frame_add_dst_extaddr(undefined4 param_1,undefined4 *param_2)

{
  ushort uStack_1a;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  zmsg_read_bytes(0,2,&uStack_1a);
  if (-1 < (int)((uint)uStack_1a << 0x14)) {
    zmsg_insert_header(param_1,8);
    uStack_18 = CONCAT22(uStack_18._2_2_,uStack_1a) | 0x800;
    uStack_1a = uStack_1a | 0x800;
    zmsg_write_bytes(param_1,0,2,&uStack_18);
  }
  uStack_18 = *param_2;
  uStack_14 = param_2[1];
  zmsg_write_bytes(param_1,8,&uStack_18);
  return;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_fcf_skip_aux_hdr_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint aps_frame_fcf_skip_aux_hdr_offset(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  byte bStack_11;
  
  uVar1 = aps_frame_fcf_skip_ext_hdr_offset();
  if ((param_1 & 0x20) != 0) {
    bStack_11 = 0;
    zmsg_read_bytes(param_2,uVar1,1,&bStack_11);
    if ((bStack_11 & 0x20) == 0) {
      iVar2 = 5;
    }
    else {
      iVar2 = 0xd;
    }
    if ((bStack_11 & 0x18) == 8) {
      iVar2 = iVar2 + 1;
    }
    uVar1 = uVar1 + iVar2 & 0xffff;
  }
  return uVar1;
}


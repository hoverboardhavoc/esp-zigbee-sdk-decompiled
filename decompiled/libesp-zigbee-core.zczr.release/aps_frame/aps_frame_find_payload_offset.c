/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_find_payload_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint aps_frame_find_payload_offset(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bStack_12;
  byte bStack_11;
  
  bStack_12 = 0;
  zmsg_read_u8(0,&bStack_12);
  bVar1 = bStack_12;
  uVar2 = aps_fcf_get_hdr_size(bStack_12);
  if ((char)bVar1 < '\0') {
    bStack_11 = 0;
    zmsg_read_u8(param_1,uVar2,&bStack_11);
    iVar3 = 1;
    if ((byte)((bStack_11 & 3) - 1) < 2) {
      iVar3 = ((bVar1 & 3) == 2) + 2;
    }
    uVar2 = uVar2 + iVar3 & 0xffff;
  }
  if ((bVar1 & 0x20) != 0) {
    bStack_11 = 0;
    zmsg_read_u8(param_1,uVar2,&bStack_11);
    uVar2 = uVar2 + (bStack_11 >> 2 & 8) + 5 + (uint)((bStack_11 & 0x18) == 8) & 0xffff;
  }
  if ((bStack_12 & 3) == 1) {
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return uVar2;
}


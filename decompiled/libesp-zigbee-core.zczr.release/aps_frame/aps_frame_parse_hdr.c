/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_parse_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_frame_parse_hdr(undefined4 param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte abStack_21 [9];
  
  uVar2 = zmsg_read_u8(0,param_2 + 0xc);
  bVar1 = *(byte *)(param_2 + 0xc);
  iVar3 = aps_fcf_has_address(bVar1);
  if (iVar3 != 0) {
    if ((bVar1 & 0xc) == 0xc) {
      iVar3 = zmsg_read_bytes(param_1,uVar2,2,param_2 + 4);
    }
    else {
      iVar3 = zmsg_read_u8(param_1,uVar2,param_2 + 7);
    }
    uVar2 = uVar2 + iVar3 & 0xffff;
    iVar3 = zmsg_read_bytes(param_1,uVar2,2,param_2 + 8);
    uVar2 = uVar2 + iVar3 & 0xffff;
    iVar3 = zmsg_read_bytes(param_1,uVar2,2,param_2 + 10);
    uVar2 = uVar2 + iVar3 & 0xffff;
    iVar3 = zmsg_read_u8(param_1,uVar2,param_2 + 6);
    uVar2 = uVar2 + iVar3 & 0xffff;
  }
  iVar3 = zmsg_read_u8(param_1,uVar2,param_2 + 0xd);
  uVar2 = uVar2 + iVar3 & 0xffff;
  if (*(char *)(param_2 + 0xc) < '\0') {
    *(undefined1 *)(param_2 + 0x12) = 1;
    *(undefined1 *)(param_2 + 0x13) = 0;
    iVar3 = zmsg_read_u8(param_1,uVar2,param_2 + 0x11);
    uVar2 = iVar3 + uVar2 & 0xffff;
    if ((byte)((*(byte *)(param_2 + 0x11) & 3) - 1) < 2) {
      iVar3 = zmsg_read_u8(param_1,uVar2,param_2 + 0x12);
      uVar2 = iVar3 + uVar2 & 0xffff;
      if ((*(byte *)(param_2 + 0xc) & 3) == 2) {
        iVar3 = zmsg_read_u8(param_1,uVar2,param_2 + 0x13);
        uVar2 = iVar3 + uVar2 & 0xffff;
      }
    }
  }
  if ((*(byte *)(param_2 + 0xc) & 0x20) != 0) {
    zmsg_read_u8(param_1,uVar2,abStack_21);
    uVar2 = (abStack_21[0] >> 2 & 8) + 5 + (uint)((abStack_21[0] & 0x18) == 8) + uVar2 & 0xffff;
  }
  if ((*(byte *)(param_2 + 0xc) & 3) == 1) {
    zmsg_read_u8(param_1,uVar2,param_2 + 0xe);
  }
  return 0;
}


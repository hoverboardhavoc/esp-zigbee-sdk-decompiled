/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_parse_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_frame_parse_hdr(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  byte abStack_21 [13];
  
  uVar1 = zmsg_read_bytes(0,1,param_2 + 0xc);
  bVar3 = *(byte *)(param_2 + 0xc);
  if (((bVar3 & 3) != 1) && (((bVar3 & 3) != 2 || ((bVar3 & 0x10) == 0)))) {
    if ((bVar3 & 0xc) == 0xc) {
      iVar2 = zmsg_read_bytes(param_1,uVar1,2,param_2 + 4);
    }
    else {
      iVar2 = zmsg_read_bytes(param_1,uVar1,1,param_2 + 7);
    }
    uVar1 = uVar1 + iVar2 & 0xffff;
    iVar2 = zmsg_read_bytes(param_1,uVar1,2,param_2 + 8);
    uVar1 = uVar1 + iVar2 & 0xffff;
    iVar2 = zmsg_read_bytes(param_1,uVar1,2,param_2 + 10);
    uVar1 = uVar1 + iVar2 & 0xffff;
    iVar2 = zmsg_read_bytes(param_1,uVar1,1,param_2 + 6);
    uVar1 = uVar1 + iVar2 & 0xffff;
  }
  iVar2 = zmsg_read_bytes(param_1,uVar1,1,param_2 + 0xd);
  uVar1 = uVar1 + iVar2 & 0xffff;
  if (*(char *)(param_2 + 0xc) < '\0') {
    *(undefined1 *)(param_2 + 0x12) = 1;
    *(undefined1 *)(param_2 + 0x13) = 0;
    iVar2 = zmsg_read_bytes(param_1,uVar1,1,param_2 + 0x11);
    uVar1 = iVar2 + uVar1 & 0xffff;
    bVar3 = *(byte *)(param_2 + 0x11) & 3;
    if ((bVar3 == 1) || (bVar3 == 2)) {
      iVar2 = zmsg_read_bytes(param_1,uVar1,1,param_2 + 0x12);
      uVar1 = iVar2 + uVar1 & 0xffff;
      if ((*(byte *)(param_2 + 0xc) & 3) == 2) {
        iVar2 = zmsg_read_bytes(param_1,uVar1,1,param_2 + 0x13);
        uVar1 = iVar2 + uVar1 & 0xffff;
      }
    }
  }
  if ((*(byte *)(param_2 + 0xc) & 0x20) != 0) {
    zmsg_read_bytes(param_1,uVar1,1,abStack_21);
    if ((abStack_21[0] & 0x20) == 0) {
      iVar2 = 5;
    }
    else {
      iVar2 = 0xd;
    }
    if ((abStack_21[0] & 0x18) == 8) {
      iVar2 = iVar2 + 1;
    }
    uVar1 = iVar2 + uVar1 & 0xffff;
  }
  if ((*(byte *)(param_2 + 0xc) & 3) == 1) {
    zmsg_read_bytes(param_1,uVar1,1,param_2 + 0xe);
  }
  return 0;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_load_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_load_header(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar1 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,1,param_1 + 0x1a);
  if (uVar1 == 0) {
    uVar1 = 0xffff;
  }
  if ((*(byte *)(param_1 + 0x1a) & 4) == 0) {
    *(undefined2 *)(param_1 + 0x1c) = 0;
  }
  else {
    iVar2 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar1,2,param_1 + 0x1c);
    if (iVar2 == 0) {
      uVar1 = 0xffff;
    }
    else {
      uVar1 = uVar1 + iVar2 & 0xffff;
    }
  }
  iVar2 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar1,1,param_1 + 0x1e);
  if (iVar2 == 0) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = iVar2 + uVar1 & 0xffff;
  }
  iVar2 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar1,1,param_1 + 0x20);
  if (iVar2 == 0) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = iVar2 + uVar1 & 0xffff;
  }
  uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  uVar4 = 0x80;
  if (uVar1 <= uVar3) {
    zmsg_remove_header(*(undefined4 *)(param_1 + 0x24));
    uVar4 = 0;
  }
  return uVar4;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_append_bytes_from_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zmsg_append_bytes_from_msg(undefined4 param_1,undefined4 param_2,int param_3,ushort param_4)

{
  uint uVar1;
  int iVar2;
  ushort auStack_32 [3];
  undefined1 auStack_2c [4];
  undefined4 uStack_28;
  ushort uStack_24;
  
  auStack_32[0] = param_4;
  uVar1 = zmsg_get_length();
  iVar2 = zmsg_get_length(param_2);
  if (iVar2 < (int)(param_3 + (uint)auStack_32[0])) {
    iVar2 = 2;
  }
  else {
    iVar2 = zmsg_set_length(param_1,auStack_32[0] + uVar1 & 0xffff);
    if (iVar2 == 0) {
      zmsg_get_first_chunk(param_2,param_3,auStack_32,auStack_2c);
      while (uStack_24 != 0) {
        zmsg_write_bytes(param_1,uVar1,uStack_28);
        uVar1 = uVar1 + uStack_24 & 0xffff;
        zmsg_get_next_chunk(auStack_32,auStack_2c);
      }
    }
  }
  return iVar2;
}


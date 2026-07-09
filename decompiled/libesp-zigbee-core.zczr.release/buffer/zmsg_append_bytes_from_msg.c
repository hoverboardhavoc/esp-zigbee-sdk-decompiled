/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_append_bytes_from_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zmsg_append_bytes_from_msg(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 auStack_32 [3];
  undefined1 auStack_2c [4];
  undefined4 uStack_28;
  ushort uStack_24;
  
  auStack_32[0] = (undefined2)param_4;
  iVar2 = 2;
  if ((int)(param_4 + param_3) <= (int)(uint)*(ushort *)(param_2 + 0xe)) {
    uVar1 = (uint)*(ushort *)(param_1 + 0xe);
    iVar2 = zmsg_set_length((param_4 & 0xffff) + uVar1 & 0xffff);
    if (iVar2 == 0) {
      zmsg_get_first_chunk(param_2,param_3,auStack_32,auStack_2c);
      while (uVar3 = (uint)uStack_24, uVar3 != 0) {
        zmsg_write_bytes(param_1,uVar1,uVar3,uStack_28);
        uVar1 = uVar1 + uVar3 & 0xffff;
        zmsg_get_next_chunk(auStack_32,auStack_2c);
      }
    }
  }
  return iVar2;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_write_bytes_from_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_write_bytes_from_msg(int param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_60 [46];
  ushort local_32 [3];
  undefined1 auStack_2c [4];
  undefined4 local_28;
  ushort local_24;
  
  local_32[0] = (ushort)param_5;
  if ((param_3 == param_1) && (param_4 < param_2)) {
    uVar1 = param_2 + (param_5 & 0xffff) & 0xffff;
    uVar3 = (param_5 & 0xffff) + param_4 & 0xffff;
    while (uVar2 = (uint)local_32[0], uVar2 != 0) {
      if (0x20 < uVar2) {
        uVar2 = 0x20;
      }
      local_32[0] = local_32[0] - (short)uVar2;
      uVar3 = uVar3 - uVar2 & 0xffff;
      uVar1 = uVar1 - uVar2 & 0xffff;
      zmsg_read_bytes(param_1,uVar3,uVar2,auStack_60);
      zmsg_write_bytes(param_1,uVar1,uVar2,auStack_60);
    }
  }
  else {
    zmsg_get_first_chunk(param_3,param_4,local_32,auStack_2c);
    while (local_24 != 0) {
      zmsg_write_bytes(param_1,param_2,local_28);
      param_2 = local_24 + param_2 & 0xffff;
      zmsg_get_next_chunk(local_32,auStack_2c);
    }
  }
  return;
}


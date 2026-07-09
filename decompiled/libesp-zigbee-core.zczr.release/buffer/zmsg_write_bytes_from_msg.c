/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_write_bytes_from_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_write_bytes_from_msg(int param_1,uint param_2,int param_3,uint param_4,ushort param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_70 [40];
  uint local_48;
  ushort local_42 [3];
  undefined1 auStack_3c [4];
  undefined4 local_38;
  ushort local_34;
  
  local_42[0] = param_5;
  if ((param_3 == param_1) && (param_4 < param_2)) {
    uVar3 = (uint)param_5;
    uVar2 = param_2 + uVar3 & 0xffff;
    uVar1 = uVar3 + param_4 & 0xffff;
    for (; uVar3 != 0; uVar3 = uVar3 & 0xffff) {
      local_48 = uVar3;
      if (0x20 < uVar3) {
        local_48 = 0x20;
      }
      uVar1 = uVar1 - local_48 & 0xffff;
      uVar3 = uVar3 - local_48;
      uVar2 = uVar2 - local_48;
      zmsg_read_bytes(param_1,uVar1,auStack_70);
      uVar2 = uVar2 & 0xffff;
      zmsg_write_bytes(param_1,uVar2,local_48,auStack_70);
    }
  }
  else {
    zmsg_get_first_chunk(param_3,param_4,local_42,auStack_3c);
    while (uVar1 = (uint)local_34, uVar1 != 0) {
      zmsg_write_bytes(param_1,param_2,uVar1,local_38);
      param_2 = param_2 + uVar1 & 0xffff;
      zmsg_get_next_chunk(local_42,auStack_3c);
    }
  }
  return;
}


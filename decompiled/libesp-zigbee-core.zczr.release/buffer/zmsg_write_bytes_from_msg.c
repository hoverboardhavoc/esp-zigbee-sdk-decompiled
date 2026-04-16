/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_write_bytes_from_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_write_bytes_from_msg
               (zmsg_t *dst_msg,uint16_t write_offset,zmsg_t *src_msg,uint16_t read_offset,
               uint16_t length)

{
  uint uVar1;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002036;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_70 [40];
  uint local_48;
  uint16_t local_42 [3];
  undefined1 auStack_3c [4];
  zmsg_chunk_t chunk;
  
  uVar1 = CONCAT22(in_register_0000202e,write_offset);
  local_42[0] = length;
  if ((src_msg == dst_msg) && (CONCAT22(in_register_00002036,read_offset) < uVar1)) {
    uVar3 = (uint)length;
    uVar1 = uVar1 + uVar3;
    uVar2 = uVar3 + CONCAT22(in_register_00002036,read_offset);
    while( true ) {
      if (uVar3 == 0) break;
      local_48 = uVar3;
      if (0x20 < uVar3) {
        local_48 = 0x20;
      }
      uVar2 = (uVar2 & 0xffff) - local_48;
      uVar3 = uVar3 - local_48;
      uVar1 = (uVar1 & 0xffff) - local_48;
      zmsg_read_bytes(dst_msg,(uint16_t)uVar2,(uint16_t)local_48,auStack_70);
      uVar3 = uVar3 & 0xffff;
      zmsg_write_bytes(dst_msg,(uint16_t)uVar1,(uint16_t)local_48,auStack_70);
    }
  }
  else {
    zmsg_get_first_chunk(src_msg,read_offset,local_42,(zmsg_chunk_t *)auStack_3c);
    while (uVar2 = (uint)(ushort)chunk.data, uVar2 != 0) {
      zmsg_write_bytes(dst_msg,(uint16_t)uVar1,(ushort)chunk.data,chunk.buffer);
      uVar1 = uVar1 + uVar2 & 0xffff;
      zmsg_get_next_chunk(local_42,(zmsg_chunk_t *)auStack_3c);
    }
  }
  return;
}


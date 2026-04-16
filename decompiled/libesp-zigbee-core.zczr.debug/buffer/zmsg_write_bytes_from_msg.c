/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_write_bytes_from_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: chunk */
/* WARNING: Unknown calling convention */

void zmsg_write_bytes_from_msg
               (zmsg_t *dst_msg,uint16_t write_offset,zmsg_t *src_msg,uint16_t read_offset,
               uint16_t length)

{
  uint16_t length_00;
  uint uVar1;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002036;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_60 [46];
  uint16_t local_32 [3];
  undefined1 auStack_2c [4];
  zmsg_chunk_t chunk;
  
  uVar1 = CONCAT22(in_register_0000202e,write_offset);
  local_32[0] = length;
  if ((src_msg == dst_msg) && (CONCAT22(in_register_00002036,read_offset) < uVar1)) {
    uVar1 = uVar1 + length;
    uVar3 = (uint)length + CONCAT22(in_register_00002036,read_offset);
    while( true ) {
      uVar2 = (uint)local_32[0];
      if (uVar2 == 0) break;
      if (0x20 < uVar2) {
        uVar2 = 0x20;
      }
      length_00 = (uint16_t)uVar2;
      local_32[0] = local_32[0] - length_00;
      uVar3 = (uVar3 & 0xffff) - uVar2;
      uVar1 = (uVar1 & 0xffff) - uVar2;
      zmsg_read_bytes(dst_msg,(uint16_t)uVar3,length_00,auStack_60);
      zmsg_write_bytes(dst_msg,(uint16_t)uVar1,length_00,auStack_60);
    }
  }
  else {
    zmsg_get_first_chunk(src_msg,read_offset,local_32,(zmsg_chunk_t *)auStack_2c);
    while ((uint16_t)chunk.data != 0) {
      zmsg_write_bytes(dst_msg,(uint16_t)uVar1,(uint16_t)chunk.data,chunk.buffer);
      uVar1 = (uint16_t)chunk.data + uVar1 & 0xffff;
      zmsg_get_next_chunk(local_32,(zmsg_chunk_t *)auStack_2c);
    }
  }
  return;
}


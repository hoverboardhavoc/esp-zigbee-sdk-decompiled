/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_append_bytes_from_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zmsg_append_bytes_from_msg
                    (zmsg_t *dst_msg,zmsg_t *src_msg,uint16_t offset,uint16_t length)

{
  uint16_t uVar1;
  uint16_t offset_00;
  ezb_err_t eVar2;
  undefined2 in_register_00002032;
  undefined2 in_register_00002036;
  uint16_t auStack_32 [3];
  undefined1 auStack_2c [4];
  zmsg_chunk_t chunk;
  
  eVar2 = 2;
  if (CONCAT22(in_register_00002036,length) + CONCAT22(in_register_00002032,offset) <=
      (int)(uint)src_msg->length) {
    offset_00 = dst_msg->length;
    auStack_32[0] = length;
    eVar2 = zmsg_set_length(dst_msg,length + offset_00);
    if (eVar2 == 0) {
      zmsg_get_first_chunk(src_msg,offset,auStack_32,(zmsg_chunk_t *)auStack_2c);
      while( true ) {
        uVar1 = (uint16_t)chunk.data;
        if ((uint16_t)chunk.data == 0) break;
        zmsg_write_bytes(dst_msg,offset_00,(uint16_t)chunk.data,chunk.buffer);
        offset_00 = offset_00 + uVar1;
        zmsg_get_next_chunk(auStack_32,(zmsg_chunk_t *)auStack_2c);
      }
    }
  }
  return eVar2;
}


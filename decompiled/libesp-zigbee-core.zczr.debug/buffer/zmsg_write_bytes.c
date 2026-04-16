/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_write_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_write_bytes(zmsg_t *msg,uint16_t offset,uint16_t length,void *buf)

{
  undefined2 in_register_0000202e;
  char *__n;
  uint16_t auStack_22 [3];
  undefined1 auStack_1c [4];
  zmsg_chunk_t chunk;
  
  auStack_22[0] = length;
  if ((int)((uint)length + CONCAT22(in_register_0000202e,offset)) <= (int)(uint)msg->length) {
    zmsg_get_first_chunk(msg,offset,auStack_22,(zmsg_chunk_t *)auStack_1c);
    while (__n = (char *)(uint)(ushort)chunk.data, __n != (char *)0x0) {
_L0:
      memmove(chunk.buffer,buf,(size_t)__n);
      buf = (void *)((int)buf + (uint)(ushort)chunk.data);
      zmsg_get_next_chunk(auStack_22,(zmsg_chunk_t *)auStack_1c);
    }
    return;
  }
  __n = "zmsg_write_bytes";
  __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0xe6,"offset + length <= msg->length")
  ;
  goto _L0;
}


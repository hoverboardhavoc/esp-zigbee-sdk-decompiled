/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_read_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: chunk */
/* WARNING: Unknown calling convention */

uint16_t zmsg_read_bytes(zmsg_t *msg,uint16_t offset,uint16_t length,void *buf)

{
  void *__dest;
  uint __n;
  uint16_t auStack_22 [3];
  undefined1 auStack_1c [4];
  zmsg_chunk_t chunk;
  
  auStack_22[0] = length;
  zmsg_get_first_chunk(msg,offset,auStack_22,(zmsg_chunk_t *)auStack_1c);
  __dest = buf;
  while (__n = (uint)(ushort)chunk.data, __n != 0) {
    memcpy(__dest,chunk.buffer,__n);
    __dest = (void *)((int)__dest + __n);
    zmsg_get_next_chunk(auStack_22,(zmsg_chunk_t *)auStack_1c);
  }
  return (uint16_t)((uint)(((int)__dest - (int)buf) * 0x10000) >> 0x10);
}


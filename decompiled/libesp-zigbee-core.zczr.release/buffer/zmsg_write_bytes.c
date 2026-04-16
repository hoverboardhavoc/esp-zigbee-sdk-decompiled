/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_write_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_write_bytes(zmsg_t *msg,uint16_t offset,uint16_t length,void *buf)

{
  uint __n;
  undefined2 in_register_0000202e;
  int iVar1;
  int extraout_a1;
  undefined2 in_register_00002032;
  uint16_t auStack_22 [3];
  undefined1 auStack_1c [4];
  zmsg_chunk_t chunk;
  
  iVar1 = CONCAT22(in_register_0000202e,offset);
  auStack_22[0] = length;
  if ((int)(uint)msg->length < CONCAT22(in_register_00002032,length) + iVar1) {
    buf = (void *)0x0;
    msg = (zmsg_t *)__assert_func(0,0,0,0);
    iVar1 = extraout_a1;
  }
  zmsg_get_first_chunk(msg,(uint16_t)iVar1,auStack_22,(zmsg_chunk_t *)auStack_1c);
  while (__n = (uint)(ushort)chunk.data, __n != 0) {
    memmove(chunk.buffer,buf,__n);
    buf = (void *)((int)buf + __n);
    zmsg_get_next_chunk(auStack_22,(zmsg_chunk_t *)auStack_1c);
  }
  return;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_get_first_chunk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_get_first_chunk(zmsg_t *msg,uint16_t offset,uint16_t *length,zmsg_chunk_t *chunk)

{
  ushort uVar1;
  undefined2 in_register_0000202e;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = CONCAT22(in_register_0000202e,offset);
  chunk->buffer = msg->chunks;
  uVar1 = msg->length;
  if (uVar3 < uVar1) {
    if ((int)(uint)uVar1 < (int)(*length + uVar3)) {
      *length = uVar1 - offset;
    }
    for (uVar3 = msg->header + uVar3; uVar3 = uVar3 & 0xffff, 0xab < uVar3; uVar3 = uVar3 - 0xac) {
      if (chunk->buffer == (buffer_t *)0x0) {
        chunk = (zmsg_chunk_t *)0x10650;
        pcVar2 = zmsg_get_first_chunk::__func__;
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x1b7);
        length = (uint16_t *)pcVar2;
        break;
      }
      chunk->buffer = (buffer_t *)chunk->buffer->field_0;
    }
    chunk->data = chunk->buffer->data + uVar3;
    chunk->len = 0xac - (short)uVar3;
  }
  else {
    chunk->len = 0;
  }
  if (*length < chunk->len) {
    chunk->len = *length;
  }
  *length = *length - chunk->len;
  return;
}


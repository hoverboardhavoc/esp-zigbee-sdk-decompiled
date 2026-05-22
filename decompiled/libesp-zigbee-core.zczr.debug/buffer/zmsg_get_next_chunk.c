/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_get_next_chunk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_get_next_chunk(uint16_t *length,zmsg_chunk_t *chunk)

{
  zmsg_t *msg;
  uint16_t offset;
  void *__dest;
  anon_union_4_2_77b2d3ce_for_buffer_s_0 aVar1;
  uint16_t auStack_32 [3];
  zmsg_chunk_t zStack_2c;
  
  if (*length == 0) {
    chunk->len = 0;
  }
  else {
    aVar1 = chunk->buffer->field_0;
    chunk->buffer = (buffer_t *)aVar1;
    if (aVar1 == (anon_union_4_2_77b2d3ce_for_buffer_s_0)0x0) {
      __dest = (void *)0x10650;
      auStack_32[0] = 0xf64;
      msg = (zmsg_t *)
            __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x1cc,0x10650
                         );
      zmsg_get_first_chunk(msg,offset,auStack_32,&zStack_2c);
      while (zStack_2c.len != 0) {
        memcpy(__dest,zStack_2c.data,(uint)zStack_2c.len);
        __dest = (void *)((int)__dest + (uint)zStack_2c.len);
        zmsg_get_next_chunk(auStack_32,&zStack_2c);
      }
      return;
    }
    chunk->data = (uint8_t *)((int)aVar1 + 4);
    chunk->len = 0xac;
    if (*length < 0xac) {
      chunk->len = *length;
    }
    *length = *length - chunk->len;
  }
  return;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> buffer_get_tail_const
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t * buffer_get_tail_const(buffer_t *buf,uint16_t tail_size)

{
  buffer_t *buf_00;
  uint8_t *__dest;
  uint8_t *__src;
  undefined2 in_register_0000202e;
  buffer_t *buf_01;
  char *__n;
  
  if (CONCAT22(in_register_0000202e,tail_size) < 0xad) {
    return (uint8_t *)((int)buf + (0xb0 - CONCAT22(in_register_0000202e,tail_size)));
  }
  __n = "buffer_get_tail_const";
  buf_00 = (buffer_t *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x46,
                         "tail_size <= (176 - sizeof(struct buf_hdr_s))");
  if (__n != (char *)0x0) {
    __dest = buffer_get_tail(buf_00,(uint16_t)__n);
    __src = buffer_get_tail_const(buf_01,(uint16_t)__n);
    buf_00 = (buffer_t *)memmove(__dest,__src,(size_t)__n);
  }
  return (uint8_t *)buf_00;
}


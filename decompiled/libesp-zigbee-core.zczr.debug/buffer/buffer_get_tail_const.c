/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
           __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0x46,
                         "tail_size <= (176 - sizeof(struct buf_hdr_s))");
  if (__n != (char *)0x0) {
    __dest = buffer_get_tail(buf_00,(uint16_t)__n);
    __src = buffer_get_tail_const(buf_01,(uint16_t)__n);
    buf_00 = (buffer_t *)memmove(__dest,__src,(size_t)__n);
  }
  return (uint8_t *)buf_00;
}


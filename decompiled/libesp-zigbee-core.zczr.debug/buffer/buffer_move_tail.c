/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> buffer_move_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void buffer_move_tail(buffer_t *dst_buf,buffer_t *src_buf,uint16_t tail)

{
  uint8_t *__dest;
  uint8_t *__src;
  undefined2 in_register_00002032;
  
  if (CONCAT22(in_register_00002032,tail) != 0) {
    __dest = buffer_get_tail(dst_buf,tail);
    __src = buffer_get_tail_const(src_buf,tail);
    memmove(__dest,__src,CONCAT22(in_register_00002032,tail));
  }
  return;
}


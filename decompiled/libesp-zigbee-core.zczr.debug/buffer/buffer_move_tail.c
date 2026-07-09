/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> buffer_move_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void buffer_move_tail(undefined4 param_1,size_t param_2)

{
  void *__dest;
  void *__src;
  
  if (param_2 != 0) {
    __dest = (void *)buffer_get_tail(param_2);
    __src = (void *)buffer_get_tail_const(param_1,param_2);
    memmove(__dest,__src,param_2);
  }
  return;
}


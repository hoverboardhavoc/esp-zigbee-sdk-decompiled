/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> buffer_get_tail_const
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * buffer_get_tail_const(int param_1,uint param_2)

{
  void *pvVar1;
  void *__src;
  undefined4 extraout_a1;
  char *__n;
  
  if (param_2 < 0xad) {
    return (void *)((param_1 - param_2) + 0xb0);
  }
  __n = "buffer_get_tail_const";
  pvVar1 = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x46,
                                 "tail_size <= (176 - sizeof(struct buf_hdr_s))");
  if (__n != (char *)0x0) {
    pvVar1 = (void *)buffer_get_tail(__n);
    __src = (void *)buffer_get_tail_const(extraout_a1,__n);
    pvVar1 = memmove(pvVar1,__src,(size_t)__n);
  }
  return pvVar1;
}


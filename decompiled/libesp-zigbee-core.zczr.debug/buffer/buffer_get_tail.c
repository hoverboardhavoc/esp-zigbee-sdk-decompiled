/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> buffer_get_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * buffer_get_tail(int param_1,uint param_2)

{
  int iVar1;
  void *pvVar2;
  void *__src;
  uint extraout_a1;
  undefined4 extraout_a1_00;
  char *__n;
  
  if (param_2 < 0xad) {
    return (void *)((param_1 - param_2) + 0xb0);
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x40,
                        "buffer_get_tail","tail_size <= (176 - sizeof(struct buf_hdr_s))");
  if (extraout_a1 < 0xad) {
    return (void *)((iVar1 - extraout_a1) + 0xb0);
  }
  __n = "buffer_get_tail_const";
  pvVar2 = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x46,
                                 "tail_size <= (176 - sizeof(struct buf_hdr_s))");
  if (__n != (char *)0x0) {
    pvVar2 = (void *)buffer_get_tail(__n);
    __src = (void *)buffer_get_tail_const(extraout_a1_00,__n);
    pvVar2 = memmove(pvVar2,__src,(size_t)__n);
  }
  return pvVar2;
}


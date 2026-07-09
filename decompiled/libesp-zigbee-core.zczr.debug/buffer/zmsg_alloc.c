/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * zmsg_alloc(undefined2 param_1)

{
  void *__s;
  int iVar1;
  
  __s = (void *)mempool_malloc(1);
  if (__s != (void *)0x0) {
    memset(__s,0,0x1c);
    *(undefined2 *)((int)__s + 0xc) = param_1;
    iVar1 = zmsg_set_length(__s,0);
    if (iVar1 != 0) {
      mempool_free(1,__s);
      __s = (void *)0x0;
    }
  }
  return __s;
}


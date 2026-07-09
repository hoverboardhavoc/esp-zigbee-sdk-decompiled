/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_read_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zmsg_read_bytes(undefined2 param_1,void *param_2)

{
  void *__dest;
  uint __n;
  undefined2 auStack_22 [3];
  undefined1 auStack_1c [4];
  void *pvStack_18;
  ushort uStack_14;
  
  auStack_22[0] = param_1;
  zmsg_get_first_chunk(auStack_22,auStack_1c);
  __dest = param_2;
  while (__n = (uint)uStack_14, __n != 0) {
    memcpy(__dest,pvStack_18,__n);
    __dest = (void *)((int)__dest + __n);
    zmsg_get_next_chunk(auStack_22,auStack_1c);
  }
  return (int)__dest - (int)param_2 & 0xffff;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_write_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_write_bytes(int param_1,int param_2,ushort param_3,void *param_4)

{
  char *__n;
  ushort auStack_22 [3];
  undefined1 auStack_1c [4];
  void *pvStack_18;
  ushort uStack_14;
  
  auStack_22[0] = param_3;
  if ((int)((uint)param_3 + param_2) <= (int)(uint)*(ushort *)(param_1 + 0xe)) {
    zmsg_get_first_chunk(auStack_22,auStack_1c);
    while (__n = (char *)(uint)uStack_14, __n != (char *)0x0) {
_L0:
      memmove(pvStack_18,param_4,(size_t)__n);
      param_4 = (void *)((int)param_4 + (uint)uStack_14);
      zmsg_get_next_chunk(auStack_22,auStack_1c);
    }
    return;
  }
  __n = "zmsg_write_bytes";
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0xe6,
                "offset + length <= msg->length");
  goto _L0;
}


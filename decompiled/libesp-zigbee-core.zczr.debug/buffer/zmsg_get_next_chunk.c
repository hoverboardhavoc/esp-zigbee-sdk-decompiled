/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_get_next_chunk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * zmsg_get_next_chunk(ushort *param_1,int *param_2)

{
  void *__dest;
  void *pvVar1;
  int iVar2;
  undefined2 auStack_32 [3];
  undefined1 auStack_2c [4];
  void *pvStack_28;
  ushort uStack_24;
  
  if (*param_1 == 0) {
    *(undefined2 *)(param_2 + 2) = 0;
  }
  else {
    iVar2 = *(int *)*param_2;
    *param_2 = iVar2;
    if (iVar2 == 0) {
      pvVar1 = (void *)0x10654;
      auStack_32[0] = 0xf68;
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x1cd,0x10654);
      zmsg_get_first_chunk(auStack_32,auStack_2c);
      __dest = pvVar1;
      while (uStack_24 != 0) {
        memcpy(__dest,pvStack_28,(uint)uStack_24);
        __dest = (void *)((int)__dest + (uint)uStack_24);
        zmsg_get_next_chunk(auStack_32,auStack_2c);
      }
      return (ushort *)((int)__dest - (int)pvVar1 & 0xffff);
    }
    param_2[1] = iVar2 + 4;
    *(undefined2 *)(param_2 + 2) = 0xac;
    if (*param_1 < 0xac) {
      *(ushort *)(param_2 + 2) = *param_1;
    }
    *param_1 = *param_1 - (short)param_2[2];
  }
  return param_1;
}


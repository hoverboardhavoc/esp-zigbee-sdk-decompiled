/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_get_first_chunk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_get_first_chunk(int param_1,uint param_2,char *param_3,int *param_4)

{
  ushort uVar1;
  
  *param_4 = *(int *)(param_1 + 8);
  uVar1 = *(ushort *)(param_1 + 0xe);
  if (param_2 < uVar1) {
    if ((int)(uint)uVar1 < (int)(*(ushort *)param_3 + param_2)) {
      *(ushort *)param_3 = uVar1 - (short)param_2;
    }
    for (param_2 = *(ushort *)(param_1 + 0xc) + param_2; param_2 = param_2 & 0xffff, 0xab < param_2;
        param_2 = param_2 - 0xac) {
      if ((int *)*param_4 == (int *)0x0) {
        param_4 = (int *)0x10654;
        param_3 = __func___4;
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x1b8);
        break;
      }
      *param_4 = *(int *)*param_4;
    }
    param_4[1] = *param_4 + 4 + param_2;
    *(short *)(param_4 + 2) = 0xac - (short)param_2;
  }
  else {
    *(undefined2 *)(param_4 + 2) = 0;
  }
  if (*(ushort *)param_3 < *(ushort *)(param_4 + 2)) {
    *(ushort *)(param_4 + 2) = *(ushort *)param_3;
  }
  *(ushort *)param_3 = *(ushort *)param_3 - (short)param_4[2];
  return;
}


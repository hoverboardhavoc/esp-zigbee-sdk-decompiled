/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_get_first_chunk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_get_first_chunk(int param_1,uint param_2,ushort *param_3,int *param_4)

{
  ushort uVar1;
  undefined4 unaff_retaddr;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  ushort uVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 8);
  uVar1 = *(ushort *)(param_1 + 0xe);
  *param_4 = (int)piVar6;
  if (param_2 < uVar1) {
    if ((int)(uint)uVar1 < (int)(*param_3 + param_2)) {
      *param_3 = uVar1 - (short)param_2;
    }
    uVar4 = 0xab;
    puVar2 = (undefined1 *)register0x00002008;
    for (param_2 = param_2 + *(ushort *)(param_1 + 0xc); param_2 = param_2 & 0xffff, uVar4 < param_2
        ; param_2 = param_2 - 0xac) {
      puVar3 = puVar2;
      if (piVar6 == (int *)0x0) {
        puVar3 = puVar2 + -0x10;
        param_4 = (int *)0x0;
        param_3 = (ushort *)0x0;
        *(undefined4 *)(puVar2 + -4) = unaff_retaddr;
        unaff_retaddr = 0x10400;
        param_2 = __assert_func(0,0);
      }
      piVar6 = (int *)*piVar6;
      *param_4 = (int)piVar6;
      puVar2 = puVar3;
    }
    param_4[1] = (int)piVar6 + param_2 + 4;
    uVar4 = 0xac - param_2 & 0xffff;
  }
  else {
    uVar4 = 0;
  }
  *(ushort *)(param_4 + 2) = (ushort)uVar4;
  uVar1 = *param_3;
  uVar5 = (ushort)uVar4;
  if (uVar1 < uVar4) {
    *(ushort *)(param_4 + 2) = uVar1;
    uVar5 = uVar1;
  }
  *param_3 = *param_3 - uVar5;
  return;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_add_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zmsg_add_footer(int param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  void *extraout_a1;
  
  uVar4 = *(ushort *)(param_1 + 0x10) + param_3;
  uVar5 = uVar4 & 0xffff;
  if (0xac < uVar5) {
    param_3 = 0;
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  iVar6 = zmsg_resize(*(ushort *)(param_1 + 0xe) + param_3 & 0xffff);
  if (iVar6 == 0) {
    *(short *)(param_1 + 0x10) = (short)(uVar4 * 0x10000 >> 0x10);
    piVar3 = (int *)*(int *)(param_1 + 8);
    piVar2 = (int *)*(int *)(param_1 + 8);
    while (piVar1 = piVar3, piVar1 != (int *)0x0) {
      piVar2 = piVar1;
      piVar3 = (int *)*piVar1;
    }
    memcpy((void *)((int)piVar2 + (0xb0 - uVar5)),param_2,param_3);
  }
  return iVar6;
}


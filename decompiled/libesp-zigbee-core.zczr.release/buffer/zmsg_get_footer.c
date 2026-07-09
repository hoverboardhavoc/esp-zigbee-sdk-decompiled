/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_get_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_get_footer(int param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  
  uVar3 = (uint)*(ushort *)(param_1 + 0x10);
  if (uVar3 < param_3) {
    param_3 = 0;
    param_2 = (void *)__assert_func(0,0,0);
  }
  piVar2 = (int *)*(int *)(param_1 + 8);
  piVar4 = (int *)*(int *)(param_1 + 8);
  while (piVar1 = piVar2, piVar1 != (int *)0x0) {
    piVar4 = piVar1;
    piVar2 = (int *)*piVar1;
  }
  if (0xac < uVar3) {
    param_2 = (void *)buffer_get_tail_part_0();
  }
  memcpy(param_2,(void *)((int)piVar4 + (0xb0 - uVar3)),param_3);
  return;
}


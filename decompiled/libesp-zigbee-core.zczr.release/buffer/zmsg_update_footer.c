/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_update_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_update_footer(int param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  void *extraout_a1;
  void *extraout_a1_00;
  uint uVar4;
  
  uVar4 = (uint)*(ushort *)(param_1 + 0x10);
  if (uVar4 < param_3) {
    param_3 = 0;
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  piVar2 = (int *)*(int *)(param_1 + 8);
  piVar3 = (int *)*(int *)(param_1 + 8);
  while (piVar1 = piVar2, piVar1 != (int *)0x0) {
    piVar3 = piVar1;
    piVar2 = (int *)*piVar1;
  }
  if (0xac < uVar4) {
    piVar3 = (int *)buffer_get_tail_part_0();
    param_2 = extraout_a1_00;
  }
  memcpy((void *)((int)piVar3 + (0xb0 - uVar4)),param_2,param_3);
  return;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> timer_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void timer_start(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *extraout_a1;
  uint uVar3;
  undefined4 *extraout_a1_00;
  int *piVar4;
  code *pcVar5;
  int *piVar6;
  
  if (0x7ffffffe < param_3) {
    param_1 = timer_init_part_0();
    param_2 = extraout_a1_00;
  }
  iVar2 = (**(code **)(param_1 + 0x14))(*(code **)(param_1 + 0x14));
  iVar2 = param_3 + iVar2;
  if (param_2 == (undefined4 *)0x0) {
    param_1 = timer_init_part_0();
    param_2 = extraout_a1;
  }
  pcVar5 = *(code **)(param_1 + 0x14);
  param_2[3] = iVar2;
  iVar2 = (*pcVar5)(pcVar5);
  tm_sched_remove(param_1,param_2);
  piVar6 = (int *)(param_1 + 0x10);
  do {
    while( true ) {
      piVar4 = piVar6;
      piVar6 = (int *)*piVar4;
      if (piVar6 == (int *)0x0) goto _L0;
      uVar3 = param_2[3] - iVar2;
      if ((int)(piVar6[3] - iVar2 ^ uVar3) < 0) break;
      if (param_2[3] - piVar6[3] < 0) goto _L0;
    }
  } while (-1 < (int)uVar3);
_L0:
  *param_2 = piVar6;
  *piVar4 = (int)param_2;
  if (param_2 != *(undefined4 **)(param_1 + 0x10)) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    iVar1 = (**(code **)(param_1 + 0x14))(*(code **)(param_1 + 0x14));
    uVar3 = *(int *)(iVar2 + 0xc) - iVar1;
                    /* WARNING: Could not recover jumptable at 0x00010048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 0x18))((int)~uVar3 >> 0x1f & uVar3,*(code **)(param_1 + 0x18));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001002c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0x1c))(*(code **)(param_1 + 0x1c));
  return;
}


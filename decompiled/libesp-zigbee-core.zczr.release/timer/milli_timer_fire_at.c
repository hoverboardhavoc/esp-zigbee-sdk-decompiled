/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> milli_timer_fire_at
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void milli_timer_fire_at(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *extraout_a1;
  uint uVar4;
  undefined4 *puVar5;
  code *pcVar6;
  undefined4 *puVar7;
  
  puVar3 = s_tm_sched_milli;
  if (param_1 == (undefined4 *)0x0) {
    puVar3 = (undefined1 *)timer_init_part_0();
    param_1 = extraout_a1;
  }
  pcVar6 = *(code **)(puVar3 + 0x14);
  param_1[3] = param_2;
  iVar2 = (*pcVar6)(pcVar6);
  tm_sched_remove(puVar3,param_1);
  puVar7 = (undefined4 *)(puVar3 + 0x10);
  do {
    while( true ) {
      puVar5 = puVar7;
      puVar7 = (undefined4 *)*puVar5;
      if (puVar7 == (undefined4 *)0x0) goto _L0;
      uVar4 = param_1[3] - iVar2;
      if ((int)(puVar7[3] - iVar2 ^ uVar4) < 0) break;
      if ((int)(param_1[3] - puVar7[3]) < 0) goto _L0;
    }
  } while (-1 < (int)uVar4);
_L0:
  *param_1 = puVar7;
  *puVar5 = param_1;
  if (param_1 != *(undefined4 **)(puVar3 + 0x10)) {
    return;
  }
  iVar2 = *(int *)(puVar3 + 0x10);
  if (iVar2 != 0) {
    iVar1 = (**(code **)(puVar3 + 0x14))(*(code **)(puVar3 + 0x14));
    uVar4 = *(int *)(iVar2 + 0xc) - iVar1;
                    /* WARNING: Could not recover jumptable at 0x00010048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(puVar3 + 0x18))((int)~uVar4 >> 0x1f & uVar4,*(code **)(puVar3 + 0x18));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001002c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(puVar3 + 0x1c))(*(code **)(puVar3 + 0x1c));
  return;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> tm_sched_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tm_sched_remove(tm_sched_t *sched,timer_base *tm)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = __assert_func(0,0,0,0);
  iVar1 = *(int *)(iVar2 + 0x10);
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001002c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar2 + 0x1c))(*(code **)(iVar2 + 0x1c));
    return;
  }
  iVar3 = (**(code **)(iVar2 + 0x14))(*(code **)(iVar2 + 0x14));
  uVar4 = *(int *)(iVar1 + 0xc) - iVar3;
                    /* WARNING: Could not recover jumptable at 0x00010048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar2 + 0x18))((int)~uVar4 >> 0x1f & uVar4,*(code **)(iVar2 + 0x18));
  return;
}


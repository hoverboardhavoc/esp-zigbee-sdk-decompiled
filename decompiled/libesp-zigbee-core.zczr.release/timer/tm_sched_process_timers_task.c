/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> tm_sched_process_timers_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void tm_sched_process_timers_task(void *ctx)

{
  timer_base *tm;
  int iVar1;
  int iVar2;
  uint uVar3;
  
  tm = *(timer_base **)((int)ctx + 0x10);
  if ((tm != (timer_base *)0x0) &&
     (iVar2 = (**(code **)((int)ctx + 0x14))(*(code **)((int)ctx + 0x14)),
     -1 < (int)(iVar2 - (tm->fire_time).val))) {
    tm_sched_remove((tm_sched_t *)ctx,tm);
    (*tm->timer_func)(tm->user_ctx);
  }
  iVar2 = *(int *)((int)ctx + 0x10);
  if (iVar2 != 0) {
    iVar1 = (**(code **)((int)ctx + 0x14))(*(code **)((int)ctx + 0x14));
    uVar3 = *(int *)(iVar2 + 0xc) - iVar1;
                    /* WARNING: Could not recover jumptable at 0x00010048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((int)ctx + 0x18))((int)~uVar3 >> 0x1f & uVar3,*(code **)((int)ctx + 0x18));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001002c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)ctx + 0x1c))(*(code **)((int)ctx + 0x1c));
  return;
}


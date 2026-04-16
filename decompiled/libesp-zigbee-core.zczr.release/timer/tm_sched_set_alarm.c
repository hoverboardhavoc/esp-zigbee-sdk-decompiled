/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> tm_sched_set_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void tm_sched_set_alarm(tm_sched_t *sched)

{
  timer_base *ptVar1;
  uint32_t uVar2;
  uint uVar3;
  
  ptVar1 = sched->timer_list;
  if (ptVar1 == (timer_base *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001002c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*sched->alarm_stop)(sched->alarm_stop);
    return;
  }
  uVar2 = (*sched->get_now)(sched->get_now);
  uVar3 = (ptVar1->fire_time).val - uVar2;
                    /* WARNING: Could not recover jumptable at 0x00010048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*sched->alarm_start_at)(uVar2,(int)~uVar3 >> 0x1f & uVar3);
  return;
}


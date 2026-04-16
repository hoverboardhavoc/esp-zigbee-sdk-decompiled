/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> micro_timer_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void micro_timer_stop(micro_timer_t *tm)

{
  tm_sched_t *extraout_a0;
  tm_sched_t *sched;
  micro_timer_t *extraout_a1;
  micro_timer_t *pmVar1;
  micro_timer_t *pmVar2;
  micro_timer_t *pmVar3;
  micro_timer_t *pmVar4;
  
  sched = &s_tm_sched_micro;
  if (tm == (micro_timer_t *)0x0) {
    tm_sched_remove(&s_tm_sched_micro,(timer_base *)0x0);
    sched = extraout_a0;
    tm = extraout_a1;
  }
  pmVar1 = tm->next;
  if (pmVar1 != tm) {
    pmVar2 = sched->timer_list;
    pmVar3 = (micro_timer_t *)&sched->timer_list;
    if (pmVar2 == tm) {
      sched->timer_list = pmVar1;
      tm_sched_set_alarm(sched);
    }
    else {
      while (pmVar2 != (micro_timer_t *)0x0) {
        pmVar4 = pmVar3->next;
        if (pmVar4 == tm) {
          pmVar3->next = pmVar1;
          break;
        }
        pmVar3 = pmVar4;
        pmVar2 = pmVar4->next;
      }
    }
    tm->next = tm;
  }
  return;
}


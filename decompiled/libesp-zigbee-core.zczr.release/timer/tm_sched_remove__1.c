/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> tm_sched_remove__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void tm_sched_remove(tm_sched_t *sched,timer_base *tm)

{
  tm_sched_t *extraout_a0;
  timer_base *extraout_a1;
  timer_base *ptVar1;
  timer_base *ptVar2;
  timer_base **p_head;
  timer_base *ptVar3;
  timer_base *ptVar4;
  
  if (tm == (timer_base *)0x0) {
    tm_sched_remove(sched,(timer_base *)0x0);
    sched = extraout_a0;
    tm = extraout_a1;
  }
  ptVar1 = tm->next;
  if (ptVar1 != tm) {
    ptVar2 = sched->timer_list;
    ptVar3 = (timer_base *)&sched->timer_list;
    if (ptVar2 == tm) {
      sched->timer_list = ptVar1;
      tm_sched_set_alarm(sched);
    }
    else {
      while (ptVar2 != (timer_base *)0x0) {
        ptVar4 = ptVar3->next;
        if (ptVar4 == tm) {
          ptVar3->next = ptVar1;
          break;
        }
        ptVar3 = ptVar4;
        ptVar2 = ptVar4->next;
      }
    }
    tm->next = tm;
  }
  return;
}


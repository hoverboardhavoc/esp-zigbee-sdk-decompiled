/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> tm_sched_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void tm_sched_add(tm_sched_t *sched,timer_base *tm)

{
  timer_base *unaff_s0;
  timer_base *unaff_s1;
  _Bool _Var1;
  time32_t now;
  undefined3 extraout_var;
  
  if (tm == (timer_base *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/common/timer.c",0x78,"tm_sched_add",
                  "tm != ((void *)0)");
  }
  else {
    now.val = (*sched->get_now)(sched->get_now);
    tm_sched_remove(sched,tm);
    unaff_s0 = (timer_base *)&sched->timer_list;
    do {
      unaff_s1 = unaff_s0;
      unaff_s0 = unaff_s1->next;
      if (unaff_s0 == (timer_base *)0x0) break;
      _Var1 = timer_fire_before(tm,unaff_s0,now);
    } while (CONCAT31(extraout_var,_Var1) == 0);
  }
  tm->next = unaff_s0;
  unaff_s1->next = tm;
  if (sched->timer_list == tm) {
    tm_sched_set_alarm(sched);
  }
  return;
}


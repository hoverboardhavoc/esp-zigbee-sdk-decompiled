/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> timer_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void timer_init(timer_base *tm,timer_func_t timer_func,void *user_ctx)

{
  timer_base *unaff_s0;
  timer_base *unaff_s1;
  _Bool _Var1;
  tm_sched_t *sched;
  time32_t now;
  undefined3 extraout_var;
  timer_base *tm_00;
  
  if (tm != (timer_base *)0x0) {
    tm->next = tm;
    tm->timer_func = timer_func;
    tm->user_ctx = user_ctx;
    return;
  }
  sched = (tm_sched_t *)
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0xbc,
                        "timer_init","tm != ((void *)0)");
  if (tm_00 == (timer_base *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0x78,"tm_sched_add",
                  "tm != ((void *)0)");
  }
  else {
    now.val = (*sched->get_now)(sched->get_now);
    tm_sched_remove(sched,tm_00);
    unaff_s0 = (timer_base *)&sched->timer_list;
    do {
      unaff_s1 = unaff_s0;
      unaff_s0 = unaff_s1->next;
      if (unaff_s0 == (timer_base *)0x0) break;
      _Var1 = timer_fire_before(tm_00,unaff_s0,now);
    } while (CONCAT31(extraout_var,_Var1) == 0);
  }
  tm_00->next = unaff_s0;
  unaff_s1->next = tm_00;
  if (sched->timer_list == tm_00) {
    tm_sched_set_alarm(sched);
  }
  return;
}


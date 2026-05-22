/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> tm_sched_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void tm_sched_remove(tm_sched_t *sched,timer_base *tm)

{
  timer_base *ptVar1;
  timer_base *in_a4;
  timer_base *ptVar2;
  timer_base *ptVar3;
  
  if (tm == (timer_base *)0x0) {
    sched = (tm_sched_t *)
            __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0x60,
                          "tm_sched_remove","tm != ((void *)0)");
  }
  else {
    in_a4 = tm->next;
    if (in_a4 == tm) {
      return;
    }
    ptVar2 = sched->timer_list;
    if (ptVar2 != tm) {
      ptVar1 = (timer_base *)&sched->timer_list;
      while (ptVar2 != (timer_base *)0x0) {
        ptVar3 = ptVar1->next;
        if (ptVar3 == tm) {
          ptVar1->next = in_a4;
          break;
        }
        ptVar1 = ptVar3;
        ptVar2 = ptVar3->next;
      }
      goto _L0;
    }
  }
  sched->timer_list = in_a4;
  tm_sched_set_alarm(sched);
_L0:
  tm->next = tm;
  return;
}


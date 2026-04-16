/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> timer.o -> micro_timer_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void micro_timer_start(micro_timer_t *tm,uint32_t delay_us)

{
  uint32_t uVar1;
  uint32_t uVar2;
  tm_sched_t *sched;
  uint uVar3;
  timer_base *ptVar4;
  uint32_t uVar5;
  _func_uint32_t *p_Var6;
  timer_base *ptVar7;
  
  sched = &s_tm_sched_micro;
  if (0x7ffffffe < delay_us) {
    tm_sched_remove(&s_tm_sched_micro,tm);
  }
  uVar2 = (*sched->get_now)(sched->get_now);
  uVar2 = delay_us + uVar2;
  if (tm == (micro_timer_t *)0x0) {
    tm_sched_remove(sched,(timer_base *)0x0);
  }
  p_Var6 = sched->get_now;
  (tm->fire_time).val = uVar2;
  uVar2 = (*p_Var6)(p_Var6);
  tm_sched_remove(sched,tm);
  ptVar7 = (timer_base *)&sched->timer_list;
  do {
    while( true ) {
      ptVar4 = ptVar7;
      ptVar7 = ptVar4->next;
      if (ptVar7 == (timer_base *)0x0) goto _L0;
      uVar5 = (tm->fire_time).val;
      uVar1 = (ptVar7->fire_time).val;
      uVar3 = uVar5 - uVar2;
      if ((int)(uVar1 - uVar2 ^ uVar3) < 0) break;
      if ((int)(uVar5 - uVar1) < 0) goto _L0;
    }
  } while (-1 < (int)uVar3);
_L0:
  tm->next = ptVar7;
  ptVar4->next = tm;
  if (tm != sched->timer_list) {
    return;
  }
  ptVar7 = sched->timer_list;
  if (ptVar7 != (timer_base *)0x0) {
    uVar2 = (*sched->get_now)(sched->get_now);
    uVar3 = (ptVar7->fire_time).val - uVar2;
                    /* WARNING: Could not recover jumptable at 0x00010048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*sched->alarm_start_at)(uVar2,(int)~uVar3 >> 0x1f & uVar3);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001002c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*sched->alarm_stop)(sched->alarm_stop);
  return;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> timer_fire_at
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void timer_fire_at(tm_sched_t *sched,timer_base *tm,time32_t fire_time)

{
  if (tm != (timer_base *)0x0) {
    (tm->fire_time).val = fire_time.val;
    tm_sched_add(sched,tm);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0xcb,"timer_fire_at",
                "tm != ((void *)0)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


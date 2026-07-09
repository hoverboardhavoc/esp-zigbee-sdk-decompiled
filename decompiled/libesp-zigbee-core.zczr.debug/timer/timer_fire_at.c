/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> timer.o -> timer_fire_at
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void timer_fire_at(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0xc) = param_2;
    tm_sched_add();
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/timer.c",0xcb,"timer_fire_at",
                "tm != ((void *)0)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


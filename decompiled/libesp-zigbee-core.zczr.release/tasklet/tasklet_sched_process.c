/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> tasklet.o -> tasklet_sched_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tasklet_sched_process(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  list_pop_all_ll(&s_tasklet_chain);
  piVar2 = (int *)list_reverse_order();
  while (piVar1 = piVar2, piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    fence();
    fence();
    if (((piVar1[1] & 1U) == 0) && (uVar3 = __atomic_fetch_and_4(0xfffffffd,5), (uVar3 & 2) != 0)) {
      (*(code *)piVar1[2])(piVar1[3],(code *)piVar1[2]);
    }
  }
  return;
}


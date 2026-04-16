/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> tasklet.o -> tasklet_sched_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

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


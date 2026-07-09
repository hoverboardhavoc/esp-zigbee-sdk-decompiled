/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> tasklet.o -> tasklet_process_common
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tasklet_process_common(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  list_pop_all_ll();
  piVar2 = (int *)list_reverse_order();
  while (piVar1 = piVar2, piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    fence();
    fence();
    if (((piVar1[1] & 1U) == 0) && (iVar3 = test_and_clr_bit(1), iVar3 != 0)) {
      (*(code *)piVar1[2])(piVar1[3],(code *)piVar1[2]);
    }
  }
  return;
}


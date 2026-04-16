/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> tasklet.o -> tasklet_process_common
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void tasklet_process_common(tasklet_chain_t *chain)

{
  int *piVar1;
  _Bool _Var2;
  int *piVar3;
  undefined3 extraout_var;
  
  list_pop_all_ll();
  piVar3 = (int *)list_reverse_order();
  while (piVar1 = piVar3, piVar1 != (int *)0x0) {
    piVar3 = (int *)*piVar1;
    fence();
    fence();
    if (((piVar1[1] & 1U) == 0) &&
       (_Var2 = test_and_clr_bit(1,(bitfield_t *)(piVar1 + 1)), CONCAT31(extraout_var,_Var2) != 0))
    {
      (*(code *)piVar1[2])(piVar1[3],(code *)piVar1[2]);
    }
  }
  return;
}


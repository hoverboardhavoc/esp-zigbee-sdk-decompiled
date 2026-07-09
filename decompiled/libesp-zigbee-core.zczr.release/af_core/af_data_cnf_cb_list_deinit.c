/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_data_cnf_cb_list_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_data_cnf_cb_list_deinit(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = core_globals_get();
  while( true ) {
    puVar2 = *(undefined4 **)(iVar1 + 0xca4);
    if (puVar2 == (undefined4 *)0x0) break;
    *(undefined4 *)(iVar1 + 0xca4) = *puVar2;
    *puVar2 = puVar2;
    mm_free(puVar2 + -3);
    iVar1 = core_globals_get();
  }
  return;
}


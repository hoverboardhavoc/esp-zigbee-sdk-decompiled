/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_store_frame_cntr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

void nwk_secur_store_frame_cntr(void)

{
  int iVar1;
  int aiStack_18 [5];
  
  iVar1 = core_globals_get();
  aiStack_18[0] = *(int *)(iVar1 + 0x9fc) + 0x400;
  aiStack_18[1] = 0;
  ds_internal_save_entry(8,aiStack_18,aiStack_18 + 1,4);
  return;
}


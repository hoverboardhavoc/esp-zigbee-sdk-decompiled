/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_restore_frame_cntr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_secur_restore_frame_cntr(void)

{
  int iVar1;
  undefined4 auStack_14 [4];
  
  auStack_14[0] = 0;
  ds_internal_read_entry(8,0,auStack_14,4);
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0x9fc) = auStack_14[0];
  return;
}


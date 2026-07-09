/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_set_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_set_panid(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(undefined2 *)(iVar1 + 0x9e4) = param_1;
  iVar1 = core_globals_get();
  nwk_mm_set_pib_attr(0xff,0x50,iVar1 + 0x9e4);
  return;
}


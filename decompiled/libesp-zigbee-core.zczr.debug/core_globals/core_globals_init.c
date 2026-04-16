/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> core_globals.o -> core_globals_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void core_globals_init(void)

{
  _Bool _Var1;
  undefined3 extraout_var;
  
  _Var1 = core_globals_inited();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    s_core_ptr = (core_globals *)mm_calloc(1,0x1454);
  }
  return;
}


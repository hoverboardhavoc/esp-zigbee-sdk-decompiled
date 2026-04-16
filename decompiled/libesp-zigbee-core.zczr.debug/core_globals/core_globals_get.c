/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> core_globals.o -> core_globals_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

core_globals * core_globals_get(void)

{
  _Bool _Var1;
  undefined3 extraout_var;
  
  _Var1 = core_globals_inited();
  if (CONCAT31(extraout_var,_Var1) != 0) {
    return s_core_ptr;
  }
  __assert_func("//build/esp-zigbee/src/core/common/core_globals.c",0x43,"core_globals_get",
                "core_globals_inited()");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


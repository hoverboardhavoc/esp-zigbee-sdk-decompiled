/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/core_globals.c",0x43,
                "core_globals_get","core_globals_inited()");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


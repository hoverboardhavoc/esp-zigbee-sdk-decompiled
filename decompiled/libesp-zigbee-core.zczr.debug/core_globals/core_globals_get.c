/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> core_globals.o -> core_globals_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 core_globals_get(void)

{
  int iVar1;
  
  iVar1 = core_globals_inited();
  if (iVar1 != 0) {
    return s_core_ptr;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/core_globals.c",0x43,
                "core_globals_get","core_globals_inited()");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_init(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  memset((void *)(iVar1 + 0xd60),0,0x6a0);
  iVar1 = core_globals_get();
  *(undefined2 *)(iVar1 + 0xd64) = 0x8000;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd62) = 0;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd63) = 0xc0;
  iVar1 = core_globals_get();
  memset((void *)(iVar1 + 0xd66),0,0x10);
  return 0;
}


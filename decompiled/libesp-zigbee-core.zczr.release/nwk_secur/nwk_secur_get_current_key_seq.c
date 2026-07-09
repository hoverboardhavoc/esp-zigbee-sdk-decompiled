/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_secur_get_current_key_seq
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 nwk_secur_get_current_key_seq(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  return *(undefined1 *)(iVar1 + (*(byte *)(iVar1 + 0xa23) & 1) * 0x11 + 0xa10);
}


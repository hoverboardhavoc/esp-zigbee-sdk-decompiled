/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_init(void)

{
  int iVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = core_globals_get();
  memset((void *)(iVar1 + 0x990),0,0x44);
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9b4) = 10;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9c0) = 1;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9c1) = 5;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9d0) = 0xc;
  aps_secur_key_pair_set_init(0x40);
  uStack_14 = 0;
  uStack_18 = 0;
  aps_secur_set_tc_address(&uStack_18);
  return;
}


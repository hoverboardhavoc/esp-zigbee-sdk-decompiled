/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001036e) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_init(void)

{
  int iVar1;
  
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
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9ac) = 0;
  *(undefined1 *)(iVar1 + 0x9ad) = 0;
  *(undefined1 *)(iVar1 + 0x9ae) = 0;
  *(undefined1 *)(iVar1 + 0x9af) = 0;
  *(undefined1 *)(iVar1 + 0x9b0) = 0;
  *(undefined1 *)(iVar1 + 0x9b1) = 0;
  *(undefined1 *)(iVar1 + 0x9b2) = 0;
  *(undefined1 *)(iVar1 + 0x9b3) = 0;
  return;
}


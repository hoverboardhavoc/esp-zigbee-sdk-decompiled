/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_set_distributed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_set_distributed(_Bool enabled)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  if (CONCAT31(in_register_00002029,enabled) == 0) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x9ac) = 0;
    *(undefined1 *)(iVar1 + 0x9ad) = 0;
    *(undefined1 *)(iVar1 + 0x9ae) = 0;
    *(undefined1 *)(iVar1 + 0x9af) = 0;
    *(undefined1 *)(iVar1 + 0x9b0) = 0;
    *(undefined1 *)(iVar1 + 0x9b1) = 0;
    *(undefined1 *)(iVar1 + 0x9b2) = 0;
    *(undefined1 *)(iVar1 + 0x9b3) = 0;
  }
  else {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x9ac) = 0xff;
    *(undefined1 *)(iVar1 + 0x9ad) = 0xff;
    *(undefined1 *)(iVar1 + 0x9ae) = 0xff;
    *(undefined1 *)(iVar1 + 0x9af) = 0xff;
    *(undefined1 *)(iVar1 + 0x9b0) = 0xff;
    *(undefined1 *)(iVar1 + 0x9b1) = 0xff;
    *(undefined1 *)(iVar1 + 0x9b2) = 0xff;
    *(undefined1 *)(iVar1 + 0x9b3) = 0xff;
  }
  return;
}


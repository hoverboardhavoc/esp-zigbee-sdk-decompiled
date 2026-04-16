/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_get_max_asdu
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t aps_get_max_asdu(_Bool frag_permitted,_Bool aps_secured,_Bool extnonce_included)

{
  uint16_t uVar1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  
  iVar2 = core_globals_get();
  uVar1 = *(uint16_t *)(iVar2 + 4);
  if (CONCAT31(in_register_00002029,frag_permitted) == 0) {
    if (CONCAT31(in_register_0000202d,aps_secured) == 0) {
      uVar1 = 0x52;
    }
    else if (CONCAT31(in_register_00002031,extnonce_included) == 0) {
      uVar1 = 0x49;
    }
    else {
      uVar1 = 0x41;
    }
  }
  return uVar1;
}


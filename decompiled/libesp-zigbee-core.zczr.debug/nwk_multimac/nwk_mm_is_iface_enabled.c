/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac.o -> nwk_mm_is_iface_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_mm_is_iface_enabled(uint8_t iface_id)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  iVar1 = core_globals_get();
  return (*(uint *)(iVar1 + CONCAT31(in_register_00002029,iface_id) * 0xc + 0xce0) >> 5 & 3) == 2;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> oui_table_get_oui
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_oui_t * oui_table_get_oui(nwk_oui_ref_t oui_ref)

{
  undefined3 in_register_00002029;
  int iVar1;
  nwk_oui_t *pauVar2;
  
  iVar1 = core_globals_get();
  if (CONCAT31(in_register_00002029,oui_ref) < 0x20) {
    pauVar2 = (nwk_oui_t *)(iVar1 + 0xc4a + CONCAT31(in_register_00002029,oui_ref) * 3);
  }
  else {
    pauVar2 = (nwk_oui_t *)0x0;
  }
  return pauVar2;
}


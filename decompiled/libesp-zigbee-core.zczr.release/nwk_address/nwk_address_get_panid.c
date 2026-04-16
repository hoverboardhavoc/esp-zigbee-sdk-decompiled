/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_get_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_get_panid(nwk_panid_ref_t ref,ezb_panid_t *panid_p)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined3 extraout_var;
  
  iVar2 = core_globals_get();
  _Var1 = check_table_ref((uint16_t)CONCAT31(in_register_00002029,ref),(bitmap_t *)(iVar2 + 0xc48),
                          0x10);
  if (CONCAT31(extraout_var,_Var1) != 0) {
    *panid_p = *(ezb_panid_t *)(iVar2 + CONCAT31(in_register_00002029,ref) * 10 + 0xbb0);
  }
  return;
}


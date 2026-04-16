/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_reset_panid_table_except
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_reset_panid_table_except(ezb_extpanid_t *ext_panid)

{
  nwk_panid_ref_t nVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  
  iVar2 = core_globals_get();
  nVar1 = nwk_address_get_panid_ref(ext_panid);
  uVar3 = CONCAT31(extraout_var,nVar1);
  if (uVar3 == 0xff) {
    uVar3 = __assert_func(0,0,0,0);
  }
  nwk_address_reset_panid_table();
  __atomic_fetch_or_1((uVar3 >> 3) + iVar2 + 0xc48,1 << (uVar3 & 7) & 0xff,5);
  return;
}


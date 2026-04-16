/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_reset_panid_table_except
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
  int iVar3;
  
  iVar2 = core_globals_get();
  nVar1 = nwk_address_get_panid_ref(ext_panid);
  if (CONCAT31(extraout_var,nVar1) != 0xff) {
    nwk_address_reset_panid_table();
    test_and_set_bitmap(CONCAT31(extraout_var,nVar1),(bitmap_t *)(iVar2 + 0xc48));
    return;
  }
  iVar2 = __assert_func("//build/esp-zigbee/src/core/nwk/nwk_address.c",0x9f,
                        "nwk_address_reset_panid_table_except",&_L0);
  iVar3 = core_globals_get();
  do_lock_ref((nwk_addr_table_t *)(iVar3 + 0xcb0),(nwk_addr_ref_t)iVar2);
  iVar2 = *(int *)(iVar3 + 0xcb4) + iVar2 * 0x10;
  if ((*(byte *)(iVar2 + 0xf) & 4) != 0) {
    do_lock_ref((nwk_addr_table_t *)(iVar3 + 0xcb0),*(nwk_addr_ref_t *)(iVar2 + 0xc));
  }
  return;
}


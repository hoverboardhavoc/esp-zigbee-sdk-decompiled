/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x9e,
                        "nwk_address_reset_panid_table_except",&_L0);
  iVar3 = core_globals_get();
  do_lock_ref((nwk_addr_table_t *)(iVar3 + 0xc4c),(nwk_addr_ref_t)iVar2);
  iVar2 = *(int *)(iVar3 + 0xc50) + iVar2 * 0x12;
  if ((*(byte *)(iVar2 + 0x11) & 4) != 0) {
    do_lock_ref((nwk_addr_table_t *)(iVar3 + 0xc4c),*(nwk_addr_ref_t *)(iVar2 + 0xe));
  }
  return;
}


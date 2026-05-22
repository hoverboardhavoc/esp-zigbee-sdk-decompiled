/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_ref_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010b0c) */
/* WARNING: Removing unreachable block (ram,0x00010af8) */
/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_ref_by_short(ezb_shortaddr_t shortaddr,nwk_addr_ref_t *ref_p)

{
  nwk_addr_ref_t ref;
  int iVar1;
  undefined2 extraout_var;
  ezb_err_t eVar2;
  undefined2 in_register_0000202a;
  
  iVar1 = core_globals_get();
  if (CONCAT22(in_register_0000202a,shortaddr) < 0xfff8) {
    ref = search_short((nwk_addr_table_t *)(iVar1 + 0xc4c),shortaddr);
    if (CONCAT22(extraout_var,ref) < (uint)*(ushort *)(iVar1 + 0xc54)) {
      addr_table_lru_update((nwk_addr_table_t *)(iVar1 + 0xc4c),ref);
      *ref_p = ref;
      eVar2 = 0;
    }
    else {
      eVar2 = 5;
    }
  }
  else {
    eVar2 = 2;
  }
  return eVar2;
}


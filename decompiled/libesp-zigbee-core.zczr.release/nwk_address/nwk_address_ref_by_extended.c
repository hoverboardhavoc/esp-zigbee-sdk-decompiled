/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_ref_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010a0c) */
/* WARNING: Removing unreachable block (ram,0x00010a3c) */
/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_ref_by_extended(ezb_extaddr_t *extaddr,nwk_addr_ref_t *ref_p)

{
  nwk_addr_ref_t ref;
  int iVar1;
  ezb_err_t eVar2;
  undefined2 extraout_var;
  
  iVar1 = core_globals_get();
  if (extaddr == (ezb_extaddr_t *)0x0) {
    eVar2 = 2;
  }
  else if ((*(int *)((int)&extaddr->field_0 + 4) + 1U != (uint)(*(int *)&extaddr->field_0 == 0)) ||
          (eVar2 = 2, *(int *)&extaddr->field_0 - 1U < 0xfffffffe)) {
    ref = search_extended((nwk_addr_table_t *)(iVar1 + 0xc4c),extaddr);
    if (CONCAT22(extraout_var,ref) < (uint)*(ushort *)(iVar1 + 0xc54)) {
      addr_table_lru_update((nwk_addr_table_t *)(iVar1 + 0xc4c),ref);
      *ref_p = ref;
      eVar2 = 0;
    }
    else {
      eVar2 = 5;
    }
  }
  return eVar2;
}


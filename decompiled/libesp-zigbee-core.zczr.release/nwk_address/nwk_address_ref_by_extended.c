/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_ref_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010ade) */
/* WARNING: Removing unreachable block (ram,0x00010b0e) */
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
    ref = search_extended((nwk_addr_table_t *)(iVar1 + 0xcb0),extaddr);
    if (CONCAT22(extraout_var,ref) < (uint)*(ushort *)(iVar1 + 0xcb8)) {
      addr_table_lru_update((nwk_addr_table_t *)(iVar1 + 0xcb0),ref);
      *ref_p = ref;
      eVar2 = 0;
    }
    else {
      eVar2 = 5;
    }
  }
  return eVar2;
}


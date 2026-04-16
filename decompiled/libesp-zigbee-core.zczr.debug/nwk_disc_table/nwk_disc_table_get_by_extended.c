/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> nwk_disc_table_get_by_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_potential_parent_t *
nwk_disc_table_get_by_extended(nwk_panid_ref_t panid_ref,ezb_extaddr_t *extaddr)

{
  int iVar1;
  nwk_potential_parent_t *pnVar2;
  undefined1 auStack_18 [4];
  ezb_addr_t addr;
  
  iVar1 = core_globals_get();
  auStack_18 = *(undefined1 (*) [4])&extaddr->field_0;
  addr.group_addr = *(ezb_grpaddr_t *)((int)&extaddr->field_0 + 4);
  pnVar2 = disc_table_find((nwk_disc_table_t *)(iVar1 + 0xb2c),panid_ref,false,
                           (ezb_addr_t *)auStack_18);
  return pnVar2;
}


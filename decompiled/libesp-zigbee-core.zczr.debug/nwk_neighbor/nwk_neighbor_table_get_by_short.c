/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_get_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nwk_neighbor_table_get_by_short(ezb_shortaddr_t shortaddr)

{
  undefined2 in_register_0000202a;
  int iVar1;
  nwk_neighbor_t *pnVar2;
  nwk_addr_ref_t anStack_12 [2];
  nwk_addr_ref_t addr_ref;
  
  iVar1 = nwk_address_ref_by_short(CONCAT22(in_register_0000202a,shortaddr),anStack_12);
  if (iVar1 == 0) {
    pnVar2 = nwk_neighbor_table_get_by_addr_ref(anStack_12[0]);
  }
  else {
    pnVar2 = (nwk_neighbor_t *)0x0;
  }
  return pnVar2;
}


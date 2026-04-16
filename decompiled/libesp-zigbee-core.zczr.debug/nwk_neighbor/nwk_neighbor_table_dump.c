/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_neighbor_table_dump(void)

{
  nwk_addr_ref_t nVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  nwk_neighbor_t *nbr;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  ezb_shortaddr_t short_addr;
  ezb_extaddr_t ext_addr;
  
  log_write(3,"nwk_neighbor.c","Dump NWK Neighbor Table");
  nbr = (nwk_neighbor_t *)0x0;
  while (nbr = nwk_neighbor_table_next(nbr), nbr != (nwk_neighbor_t *)0x0) {
    nwk_address_by_ref(nbr->addr_ref,&uStack_3a,&stack0xffffffc8);
    uVar4 = ext_addr.field_0.u64._0_4_;
    uVar3 = uStack_38;
    uVar2 = uStack_3a;
    nVar1 = nbr->addr_ref;
    nwk_neighbor_get_lqa(nbr);
    nwk_neighbor_get_link_status(nbr);
    log_write(3,"nwk_neighbor.c",
              "  - Addr[%d:0x%04x:0x%016llx] type(%d) rel(%d) depth(%d) lqa(%d) cost(0x%02x) age(%d)"
              ,nVar1,uVar2,uVar3,uVar4);
  }
  return;
}


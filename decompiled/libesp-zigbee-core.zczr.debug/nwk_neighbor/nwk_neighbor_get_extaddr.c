/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_get_extaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void nwk_neighbor_get_extaddr(nwk_neighbor_t *nbr,ezb_extaddr_t *extaddr)

{
  int iVar1;
  
  iVar1 = nwk_address_extended_by_ref(nbr->addr_ref);
  if (iVar1 == 0) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xa6,"nwk_neighbor_get_extaddr",
                "(nwk_address_extended_by_ref(nbr->addr_ref, extaddr)) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


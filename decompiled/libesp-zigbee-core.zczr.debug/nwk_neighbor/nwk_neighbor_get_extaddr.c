/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xa6,
                "nwk_neighbor_get_extaddr",
                "(nwk_address_extended_by_ref(nbr->addr_ref, extaddr)) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


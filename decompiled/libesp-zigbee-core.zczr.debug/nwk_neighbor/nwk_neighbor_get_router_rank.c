/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_get_router_rank
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t nwk_neighbor_get_router_rank(nwk_neighbor_t *nbr)

{
  uint uVar1;
  
  uVar1 = *(uint *)&nbr->field_0xc & 3;
  if ((uVar1 != 0) && (uVar1 != 1)) {
    nbr = (nwk_neighbor_t *)
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x6d,
                        "nwk_neighbor_get_router_rank","nwk_device_type_is_zczr(nbr->device_type)");
  }
  return (ushort)(nbr->dev).r.connectivity +
         (((ushort)(nbr->dev).r.outbound_activity + (ushort)(nbr->dev).r.inbound_activity) * 2 +
         (ushort)(nbr->dev).r.nbrset_diversity) * 4;
}


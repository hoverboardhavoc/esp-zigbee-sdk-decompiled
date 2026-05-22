/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btr_set_passive_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_btr_set_passive_ack(nwk_bt_record_t *btr,ezb_shortaddr_t mac_src_addr)

{
  int iVar1;
  uint n;
  undefined2 in_register_0000202e;
  
  iVar1 = nwk_neighbor_table_get_by_short(CONCAT22(in_register_0000202e,mac_src_addr));
  if (iVar1 != 0) {
    n = nwk_neighbor_table_get_nbr_idx();
    test_and_clr_bitmap(n,btr->passive_ack);
  }
  return;
}


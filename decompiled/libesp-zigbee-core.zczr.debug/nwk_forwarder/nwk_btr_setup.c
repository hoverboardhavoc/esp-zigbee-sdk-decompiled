/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btr_setup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_btr_setup(nwk_bt_record_t *btr,ezb_shortaddr_t src_addr,uint8_t seq_num)

{
  bitmap_t *__s;
  int iVar1;
  int iVar2;
  uint n;
  
  btr->src_addr = src_addr;
  btr->seq_num = seq_num;
  btr->expire_time = '\t';
  time_ticker_register_receiver(0);
  __s = btr->passive_ack;
  iVar1 = nwk_neighbor_table_get_capacity();
  memset(__s,0,iVar1 + 7U >> 3);
  iVar1 = 0;
  while (iVar1 = nwk_router_table_next(iVar1), iVar1 != 0) {
    iVar2 = nwk_neighbor_get_incoming_cost(iVar1);
    if ((iVar2 != 0) && (iVar2 = nwk_neighbor_get_outgoing_cost(iVar1), iVar2 != 0)) {
      n = nwk_neighbor_table_get_nbr_idx(iVar1);
      test_and_set_bitmap(n,btr->passive_ack);
    }
  }
  return;
}


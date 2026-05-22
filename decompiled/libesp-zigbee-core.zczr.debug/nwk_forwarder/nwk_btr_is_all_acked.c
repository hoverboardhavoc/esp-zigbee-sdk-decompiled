/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btr_is_all_acked
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_btr_is_all_acked(nwk_bt_record_t *btr)

{
  bitmap_t *pbVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  pbVar1 = btr->passive_ack;
  uVar2 = nwk_neighbor_table_get_capacity();
  uVar3 = bitmap_find_first_bit(pbVar1,uVar2);
  uVar4 = nwk_neighbor_table_get_capacity();
  return uVar4 <= uVar3;
}


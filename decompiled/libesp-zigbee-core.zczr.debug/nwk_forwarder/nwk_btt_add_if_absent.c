/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btt_add_if_absent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: seq_num */
/* WARNING: Unknown calling convention */

_Bool nwk_btt_add_if_absent(nwk_rx_info_t *rx_info,zmsg_t *msg)

{
  ezb_shortaddr_t src_addr;
  _Bool _Var1;
  nwk_bt_record_t *btr;
  uint8_t auStack_11 [4];
  uint8_t seq_num;
  
  zmsg_read_bytes(msg,7,1,auStack_11);
  src_addr = rx_info->nwk_src_addr;
  btr = nwk_btt_find(src_addr,auStack_11[0]);
  if (btr == (nwk_bt_record_t *)0x0) {
    btr = nwk_btr_create(src_addr,auStack_11[0]);
    if (btr == (nwk_bt_record_t *)0x0) {
      return false;
    }
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  nwk_btr_set_passive_ack(btr,rx_info->mac_src_addr);
  return _Var1;
}


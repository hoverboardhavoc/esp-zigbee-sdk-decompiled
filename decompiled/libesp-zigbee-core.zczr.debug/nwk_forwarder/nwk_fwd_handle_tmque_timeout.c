/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_tmque_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_handle_tmque_timeout(zmsg_t *msg)

{
  _Bool _Var1;
  nwk_bt_record_t *btr;
  undefined3 extraout_var;
  ezb_shortaddr_t eStack_14;
  uint8_t uStack_11;
  ezb_shortaddr_t src_addr;
  uint8_t seq_num;
  
  zmsg_read_bytes(7,1,&uStack_11);
  zmsg_read_bytes(msg,4,2,&eStack_14);
  btr = nwk_btt_find(eStack_14,uStack_11);
  if ((btr == (nwk_bt_record_t *)0x0) ||
     (_Var1 = nwk_btr_is_all_acked(btr), CONCAT31(extraout_var,_Var1) == 0)) {
    nwk_fwd_do_send_msg(msg);
  }
  else {
    nwk_fwd_finish_tx(msg,0);
  }
  return;
}


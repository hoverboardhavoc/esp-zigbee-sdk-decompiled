/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_nwk_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: retry_limit */
/* WARNING: Unknown calling convention */

void nwk_fwd_handle_nwk_confirm(uint8_t iface_id,mac_data_cnf_t *cnf)

{
  zmsg_t *msg;
  undefined3 in_register_00002029;
  int iVar1;
  uint error;
  ushort uStack_1c;
  undefined1 auStack_1a [2];
  ezb_shortaddr_t dst_addr;
  ezb_shortaddr_t src_addr;
  uint32_t retry_delay;
  uint8_t retry_limit;
  
  msg = cnf->msdu;
  if (cnf->status == 0) {
    error = 0;
  }
  else {
    error = cnf->status | 0x100;
  }
  iVar1 = nwk_process_receive_security(CONCAT31(in_register_00002029,iface_id),msg);
  if (iVar1 == 0) {
    zmsg_read_bytes(msg,4,2,auStack_1a);
    zmsg_read_bytes(msg,2,&uStack_1c);
    if (((*(uint *)&cnf->status >> 8 & 1) == 0) &&
       ((0xfff7 < uStack_1c ||
        ((error - 0x1e1 < 0x11 && ((0x10101U >> (error - 0x1e1 & 0x1f) & 1) != 0)))))) {
      nwk_fwd_get_retry_params(msg,(uint8_t *)((int)&retry_delay + 3),(uint32_t *)&dst_addr);
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x3be,
                  "nwk_fwd_handle_nwk_confirm","(nwk_process_receive_security(iface_id, msg)) == 0")
    ;
  }
  retry_delay._3_1_ = 0;
_L0:
  if (msg->nwk_retries < retry_delay._3_1_) {
    msg->nwk_retries = msg->nwk_retries + 1;
    nwk_fwd_retry(msg,_dst_addr);
  }
  else if (((*(uint *)&cnf->status >> 8 & 1) == 0) || (uStack_1c < 0xfff8)) {
    nwk_fwd_finish_tx(msg,error);
  }
  else {
    zmsg_free(msg);
  }
  return;
}


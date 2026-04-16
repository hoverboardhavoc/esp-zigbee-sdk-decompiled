/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_mac_data_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_mac_data_req(zmsg_t *msg,uint8_t iface_id,ezb_shortaddr_t dst_addr,_Bool indirect_tx)

{
  int iVar1;
  undefined3 in_register_0000202d;
  zmsg_t *pzStack_3c;
  mac_data_req_t req;
  
  memset(&req,0,0x18);
  req.msdu._0_1_ = 2;
  pzStack_3c = msg;
  iVar1 = core_globals_get();
  req.msdu._2_2_ = *(undefined2 *)(iVar1 + 0x9e2);
  req.addresses.source.u._4_1_ = 2;
  req.addresses.source.u._6_2_ = dst_addr;
  iVar1 = core_globals_get();
  req.addresses.destination.u._4_2_ = *(undefined2 *)(iVar1 + 0x9e4);
  req.addresses.destination.u._6_1_ =
       req.addresses.destination.u._6_1_ & 0xfd | (byte)((indirect_tx & 1) << 1);
  iVar1 = nwk_process_transmit_security(CONCAT31(in_register_0000202d,iface_id),msg);
  if (iVar1 == 0) {
    nwk_mm_data_request(CONCAT31(in_register_0000202d,iface_id),&pzStack_3c);
  }
  else {
    nwk_fwd_finish_tx(msg,iVar1);
  }
  return;
}


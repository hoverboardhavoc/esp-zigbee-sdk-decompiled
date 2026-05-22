/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_mac_data_req
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
  
  req.addresses.source._0_4_ = 0;
  req.addresses.source.u._2_4_ = 0;
  req.addresses._8_4_ = 0;
  req.addresses.destination.u._0_2_ = 0;
  req.addresses.destination.u._2_2_ = 0;
  req.addresses.destination.u._4_4_ = 0;
  req.msdu = (zmsg_t *)0x2;
  pzStack_3c = msg;
  iVar1 = core_globals_get();
  req.msdu = (zmsg_t *)CONCAT22(*(undefined2 *)(iVar1 + 0x9e2),req.msdu._0_2_);
  req.addresses.source.u._4_1_ = 2;
  req.addresses.source.u._6_2_ = dst_addr;
  iVar1 = core_globals_get();
  req.addresses.destination.u._6_1_ =
       (byte)((uint)req.addresses.destination.u._4_4_ >> 0x10) & 0xfd |
       (byte)((indirect_tx & 1) << 1);
  req.addresses.destination.u._4_2_ = *(undefined2 *)(iVar1 + 0x9e4);
  iVar1 = nwk_process_transmit_security(CONCAT31(in_register_0000202d,iface_id),msg);
  if ((iVar1 != 0) ||
     (iVar1 = nwk_mm_data_request(CONCAT31(in_register_0000202d,iface_id),&pzStack_3c), iVar1 != 0))
  {
    nwk_fwd_finish_tx(msg,iVar1);
  }
  return;
}


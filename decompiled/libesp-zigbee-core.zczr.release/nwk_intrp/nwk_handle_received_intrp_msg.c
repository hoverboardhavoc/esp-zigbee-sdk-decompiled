/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_intrp.o -> nwk_handle_received_intrp_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_handle_received_intrp_msg(zmsg_t *msg,nwk_intrp_rx_info_t *rx_info)

{
  ushort uStack_32;
  undefined1 auStack_30 [2];
  uint16_t nwk_fcf;
  nwk_intrp_data_ind_t ind;
  
  zmsg_read_bytes(0,2,&uStack_32);
  if ((uStack_32 & 3) != 3) {
    __assert_func(0,0,0,0);
  }
  zmsg_remove_header(msg,2);
  auStack_30 = (undefined1  [2])rx_info->src_panid;
  memcpy(&nwk_fcf,&rx_info->mac_src_addr,10);
  ind.src_addr.u._4_2_ = rx_info->dst_panid;
  memcpy((void *)((int)&ind.src_addr.u + 6),rx_info,10);
  ind.nsdu._0_1_ = rx_info->lqi;
  ind.nsdu._1_1_ = rx_info->rssi;
  ind.dst_addr.u._4_4_ = msg;
  nwk_intrp_data_indication((nwk_intrp_data_ind_t *)auStack_30);
  return 0;
}


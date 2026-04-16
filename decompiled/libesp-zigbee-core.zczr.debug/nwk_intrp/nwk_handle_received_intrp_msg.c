/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_handle_received_intrp_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

ezb_err_t nwk_handle_received_intrp_msg(zmsg_t *msg,nwk_intrp_rx_info_t *rx_info)

{
  zmsg_t *apzStack_44 [4];
  undefined1 auStack_34 [4];
  nwk_intrp_data_ind_t ind;
  uint16_t nwk_fcf;
  
  apzStack_44[0] = msg;
  zmsg_read_bytes(0,2,&ind.field_0x1e);
  if ((ind._30_2_ & 3) == 3) {
    zmsg_remove_header(apzStack_44[0],2);
    auStack_34._0_2_ = rx_info->src_panid;
    auStack_34[2] = (rx_info->mac_src_addr).addr_mode;
    auStack_34[3] = (rx_info->mac_src_addr).field_0x1;
    ind.src_panid = (rx_info->mac_src_addr).u.short_addr;
    ind.src_addr._0_2_ = (rx_info->mac_src_addr).u.group_addr.bcast;
    ind.src_addr.u.short_addr = *(ezb_shortaddr_t *)((int)&(rx_info->mac_src_addr).u + 4);
    ind.src_addr.u.group_addr.bcast = *(ezb_shortaddr_t *)((int)&(rx_info->mac_src_addr).u + 6);
    ind.src_addr.u._4_2_ = rx_info->dst_panid;
    ind.src_addr.u._6_2_ = *(undefined2 *)&rx_info->mac_dst_addr;
    ind.dst_panid = (rx_info->mac_dst_addr).u.short_addr;
    ind.dst_addr._0_2_ = (rx_info->mac_dst_addr).u.group_addr.bcast;
    ind.dst_addr.u.short_addr = *(ezb_shortaddr_t *)((int)&(rx_info->mac_dst_addr).u + 4);
    ind.dst_addr.u.group_addr.bcast = *(ezb_shortaddr_t *)((int)&(rx_info->mac_dst_addr).u + 6);
    ind.dst_addr.u._4_4_ = nwk_intrp_msg_transfer_ownership(apzStack_44);
    ind.nsdu._0_1_ = rx_info->lqi;
    ind.nsdu._1_1_ = rx_info->rssi;
    nwk_intrp_data_indication((nwk_intrp_data_ind_t *)auStack_34);
    if (apzStack_44[0] != (zmsg_t *)0x0) {
      zmsg_free();
    }
    return 0;
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/interpan/nwk_intrp.c",0x6b,
                "nwk_handle_received_intrp_msg","nwk_fcf_get_frame_type(nwk_fcf) == NWK_FRAME_INTRP"
               );
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


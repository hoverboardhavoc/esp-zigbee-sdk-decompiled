/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_intrp_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_fwd_handle_intrp_frame(int8_t iface_id,mac_frame_t *rx_frame)

{
  int iVar1;
  ezb_err_t eVar2;
  undefined4 uStack_2c;
  nwk_intrp_rx_info_t rx_info;
  
  uStack_2c = *(undefined4 *)&(rx_frame->mhr).dst_addr;
  rx_info.mac_dst_addr._0_4_ = *(undefined4 *)((int)&(rx_frame->mhr).dst_addr.u + 2);
  rx_info.mac_dst_addr.u.group_addr.bcast =
       *(ezb_shortaddr_t *)((int)&(rx_frame->mhr).dst_addr.u + 6);
  rx_info.mac_dst_addr.u._4_2_ = *(undefined2 *)&(rx_frame->mhr).src_addr;
  rx_info.mac_dst_addr.u._6_2_ = (rx_frame->mhr).src_addr.u.short_addr;
  rx_info.mac_src_addr._0_2_ = (rx_frame->mhr).src_addr.u.group_addr.bcast;
  rx_info.mac_src_addr.u.short_addr = *(ezb_shortaddr_t *)((int)&(rx_frame->mhr).src_addr.u + 4);
  rx_info.mac_src_addr.u.group_addr.bcast =
       *(ezb_shortaddr_t *)((int)&(rx_frame->mhr).src_addr.u + 6);
  rx_info.mac_src_addr.u._4_2_ = (rx_frame->mhr).dst_panid;
  rx_info.mac_src_addr.u._6_2_ = (rx_frame->mhr).src_panid;
  rx_info.dst_panid._1_1_ = (rx_frame->from->info).tx.max_csma_backoffs;
  rx_info.src_panid._0_1_ = (rx_frame->from->info).tx.max_frame_retries;
  rx_info.dst_panid._0_1_ = iface_id;
  iVar1 = zmsg_alloc(9);
  if (iVar1 == 0) {
    eVar2 = 1;
  }
  else {
    eVar2 = zmsg_append_bytes((rx_frame->mpl).len,(rx_frame->mpl).buf);
    if (eVar2 == 0) {
      *(ushort *)(iVar1 + 0x16) = *(ushort *)(iVar1 + 0x16) | 8;
      eVar2 = nwk_handle_received_intrp_msg(iVar1,&uStack_2c);
    }
  }
  return eVar2;
}


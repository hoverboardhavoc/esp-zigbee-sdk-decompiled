/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_direct_tx_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_direct_tx_task(void *ctx)

{
  zmsg_t *msg;
  zmsg_t *msg_00;
  undefined1 auStack_18 [4];
  nwk_tx_info_t tx_info;
  
  auStack_18 = (undefined1  [4])0x0;
  tx_info.nwk_src_addr = 0;
  tx_info.nwk_dst_addr = 0;
  msg = nwk_fwd_prepare_next_direct_tx((nwk_tx_info_t *)auStack_18);
  if (msg != (zmsg_t *)0x0) {
    if (((tx_info._0_4_ & 0x1000000) != 0) &&
       (msg_00 = (zmsg_t *)
                 nwk_mesh_generate_rrec((uint)auStack_18 & 0xffff,(uint)auStack_18 >> 0x10),
       msg_00 != (zmsg_t *)0x0)) {
      nwk_fwd_mac_data_req(msg_00,(uint8_t)tx_info.nwk_dst_addr,tx_info.nwk_src_addr,false);
    }
    zmsg_queue_dequeue(&s_nwk_fwd,msg);
    nwk_fwd_mac_data_req(msg,(uint8_t)tx_info.nwk_dst_addr,tx_info.nwk_src_addr,false);
    tasklet_post(&s_nwk_fwd);
  }
  return;
}


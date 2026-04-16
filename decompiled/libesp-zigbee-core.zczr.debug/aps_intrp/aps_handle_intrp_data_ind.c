/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_handle_intrp_data_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_handle_intrp_data_ind(aps_intrp_header_t *aps_hdr,zmsg_t *msg)

{
  zmsg_t *apzStack_44 [3];
  undefined1 auStack_38 [4];
  aps_intrp_data_ind_t ind;
  
  auStack_38._0_2_ = aps_hdr->src_panid;
  auStack_38[2] = (aps_hdr->src_addr).addr_mode;
  auStack_38[3] = (aps_hdr->src_addr).field_0x1;
  ind.src_pan_id = (aps_hdr->src_addr).u.short_addr;
  ind.src_addr._0_2_ = (aps_hdr->src_addr).u.group_addr.bcast;
  ind.src_addr.u.short_addr = *(ezb_shortaddr_t *)((int)&(aps_hdr->src_addr).u + 4);
  ind.src_addr.u.group_addr.bcast = *(ezb_shortaddr_t *)((int)&(aps_hdr->src_addr).u + 6);
  ind.src_addr.u._4_2_ = aps_hdr->dst_panid;
  ind.src_addr.u._6_2_ = *(undefined2 *)&aps_hdr->dst_addr;
  ind.dst_pan_id = (aps_hdr->dst_addr).u.short_addr;
  ind.dst_addr._0_2_ = (aps_hdr->dst_addr).u.group_addr.bcast;
  ind.dst_addr.u.short_addr = *(ezb_shortaddr_t *)((int)&(aps_hdr->dst_addr).u + 4);
  ind.dst_addr.u.group_addr.bcast = *(ezb_shortaddr_t *)((int)&(aps_hdr->dst_addr).u + 6);
  ind.dst_addr.u._4_2_ = aps_hdr->profile_id;
  ind.dst_addr.u._6_2_ = aps_hdr->cluster_id;
  ind.profile_id._0_1_ = 0;
  apzStack_44[0] = msg;
  ind._28_4_ = aps_intrp_msg_transfer_ownership(apzStack_44);
  ind.asdu._0_1_ = aps_hdr->lqi;
  ind.asdu._1_1_ = aps_hdr->rssi;
  aps_intrp_data_indication((aps_intrp_data_ind_t *)auStack_38);
  if (apzStack_44[0] != (zmsg_t *)0x0) {
    zmsg_free();
  }
  return;
}


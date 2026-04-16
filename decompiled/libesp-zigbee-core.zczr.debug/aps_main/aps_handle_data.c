/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_handle_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_handle_data(aps_header_t *aps_hdr,zmsg_t *msg)

{
  _Bool _Var1;
  undefined4 uVar2;
  undefined3 extraout_var;
  undefined1 local_20 [4];
  aps_apsde_data_ind_t ind;
  
  local_20._0_2_ = (aps_hdr->addr_info).src_addr;
  local_20._2_2_ = (aps_hdr->addr_info).dst_addr;
  ind.addr_info.src_addr = (aps_hdr->addr_info).grp_addr;
  ind.addr_info.dst_addr._0_1_ = (aps_hdr->addr_info).src_ep;
  ind.addr_info.dst_addr._1_1_ = (aps_hdr->addr_info).dst_ep;
  ind.addr_info.grp_addr = (aps_hdr->addr_info).cluster_id;
  ind.addr_info._6_2_ = (aps_hdr->addr_info).profile_id;
  ind.addr_info._8_4_ = msg;
  uVar2 = zmsg_get_offset(msg);
  zmsg_remove_header(msg,uVar2);
  _Var1 = aps_apsde_user_data_indication((aps_apsde_data_ind_t *)local_20);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    aps_apsde_data_indication((aps_apsde_data_ind_t *)local_20);
  }
  return;
}


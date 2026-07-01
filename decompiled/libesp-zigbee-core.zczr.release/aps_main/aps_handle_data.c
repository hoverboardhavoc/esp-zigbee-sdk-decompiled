/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_handle_data
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
  undefined1 auStack_24 [4];
  aps_apsde_data_ind_t ind;
  
  memcpy(auStack_24,aps_hdr,0xc);
  ind.addr_info.cluster_id._0_1_ = aps_hdr->lqi;
  ind.addr_info.cluster_id._1_1_ = aps_hdr->rssi;
  ind._12_4_ = msg;
  uVar2 = zmsg_get_offset(msg);
  zmsg_remove_header(msg,uVar2);
  _Var1 = aps_apsde_user_data_indication((aps_apsde_data_ind_t *)auStack_24);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    aps_apsde_data_indication((aps_apsde_data_ind_t *)auStack_24);
  }
  return;
}


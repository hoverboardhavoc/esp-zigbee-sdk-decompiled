/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_handle_received_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_handle_received_msg(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ezb_err_t eVar3;
  _Bool _Var4;
  undefined3 extraout_var;
  undefined4 uVar5;
  ezb_shortaddr_t local_20;
  ezb_shortaddr_t eStack_1e;
  nwk_nlde_data_ind_t ind;
  uint16_t nwk_fcf;
  
  zmsg_read_bytes(0,2,(undefined1 *)((int)&ind.nsdu + 2));
  if ((ind.nsdu._2_2_ & 3) == 0) {
    _Var4 = nwk_is_joined();
    if (CONCAT31(extraout_var,_Var4) != 0) {
      ind.lqi = '\0';
      ind.rssi = '\0';
      ind._6_2_ = 0;
      _local_20 = CONCAT22(rx_info->nwk_dst_addr,rx_info->nwk_src_addr);
      uVar1 = rx_info->lqi;
      uVar2 = rx_info->rssi;
      ind.src_addr._1_1_ = uVar2;
      ind.src_addr._0_1_ = uVar1;
      ind.dst_addr = 0;
      uVar5 = zmsg_get_offset(msg);
      zmsg_remove_header(msg,uVar5);
      ind._4_4_ = msg;
      nwk_nlde_data_indication(&local_20);
      return 0;
    }
    eVar3 = 3;
  }
  else {
    if ((ind.nsdu._2_2_ & 3) == 1) {
      nwk_handle_received_cmd(msg,rx_info);
      return 0;
    }
    eVar3 = 0x10;
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return eVar3;
}


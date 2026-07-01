/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_handle_received_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_handle_received_msg(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ezb_err_t eVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  undefined4 uVar3;
  ushort uStack_1e;
  ezb_shortaddr_t eStack_1c;
  uint16_t nwk_fcf;
  nwk_nlde_data_ind_t ind;
  
  zmsg_read_bytes(0,2,&uStack_1e);
  if ((uStack_1e & 3) == 0) {
    _Var2 = nwk_is_joined();
    if (CONCAT31(extraout_var,_Var2) != 0) {
      eStack_1c = rx_info->nwk_src_addr;
      ind.dst_addr = 0;
      nwk_fcf = rx_info->nwk_dst_addr;
      ind.lqi = '\0';
      ind.rssi = '\0';
      ind._6_2_ = 0;
      ind.src_addr._0_1_ = rx_info->lqi;
      ind.src_addr._1_1_ = rx_info->rssi;
      uVar3 = zmsg_get_offset(msg);
      zmsg_remove_header(msg,uVar3);
      ind._4_4_ = msg;
      nwk_nlde_data_indication(&eStack_1c);
      return 0;
    }
    eVar1 = 3;
  }
  else {
    if ((uStack_1e & 3) == 1) {
      nwk_handle_received_cmd(msg,rx_info);
      return 0;
    }
    eVar1 = 0x10;
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return eVar1;
}


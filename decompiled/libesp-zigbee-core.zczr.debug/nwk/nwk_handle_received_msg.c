/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_handle_received_msg
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
  ezb_shortaddr_t eStack_1c;
  ezb_shortaddr_t eStack_1a;
  nwk_nlde_data_ind_t ind;
  uint16_t nwk_fcf;
  
  zmsg_read_bytes(0,2,(undefined1 *)((int)&ind.nsdu + 2));
  if ((ind.nsdu._2_2_ & 3) == 0) {
    _Var2 = nwk_is_joined();
    if (CONCAT31(extraout_var,_Var2) != 0) {
      ind.src_addr = 0;
      ind.dst_addr = 0;
      _eStack_1c = CONCAT22(rx_info->nwk_dst_addr,rx_info->nwk_src_addr);
      uVar3 = zmsg_get_offset(msg);
      zmsg_remove_header(msg,uVar3);
      ind._0_4_ = msg;
      nwk_nlde_data_indication(&eStack_1c);
      return 0;
    }
    eVar1 = 3;
  }
  else {
    if ((ind.nsdu._2_2_ & 3) == 1) {
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


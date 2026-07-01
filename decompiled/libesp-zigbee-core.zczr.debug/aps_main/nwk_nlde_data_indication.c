/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> nwk_nlde_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_nlde_data_indication(nwk_nlde_data_ind_t *ind)

{
  zmsg_t *msg;
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  undefined1 auStack_24 [4];
  aps_header_t aps_hdr;
  
  msg = ind->nsdu;
  iVar2 = aps_frame_validate_nsdu(msg);
  if (iVar2 != 0) {
    auStack_24 = (undefined1  [4])0x0;
    aps_hdr.addr_info.src_addr = 0;
    aps_hdr.addr_info.dst_addr = 0;
    aps_hdr.addr_info.grp_addr = 0;
    aps_hdr.addr_info.src_ep = '\0';
    aps_hdr.addr_info.dst_ep = '\0';
    aps_hdr.addr_info.cluster_id = 0;
    aps_hdr.addr_info.profile_id = 0;
    aps_hdr.fcf = '\0';
    aps_hdr.aps_cntr = '\0';
    aps_hdr.cmd_id = '\0';
    aps_hdr.lqi = '\0';
    iVar2 = aps_frame_parse_hdr(msg,auStack_24);
    uVar3 = aps_hdr.addr_info._8_4_;
    if (iVar2 == 0) {
      auStack_24._0_2_ = ind->src_addr;
      auStack_24._2_2_ = ind->dst_addr;
      aps_hdr.addr_info.profile_id._1_1_ = ind->lqi;
      aps_hdr.fcf = ind->rssi;
      if ((uVar3 & 0xc) == 0xc) {
        _Var1 = aps_is_in_group(aps_hdr.addr_info.src_addr);
        if (CONCAT31(extraout_var,_Var1) == 0) goto _L0;
      }
      iVar2 = aps_process_receive_security((uint)auStack_24 & 0xffff,msg);
      if (iVar2 == 0) {
        if ((aps_hdr.addr_info._8_4_ & 3) == 1) {
          uVar3 = zmsg_get_offset(msg);
          zmsg_read_bytes(msg,uVar3,1,&aps_hdr.addr_info.profile_id);
        }
        else {
          aps_hdr.addr_info.profile_id._0_1_ = 0;
        }
        if (-1 < (char)aps_hdr.addr_info.cluster_id) {
          aps_handle_datagram((aps_header_t *)auStack_24,msg);
          return;
        }
        aps_handle_fragment((aps_header_t *)auStack_24,msg);
        return;
      }
    }
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}


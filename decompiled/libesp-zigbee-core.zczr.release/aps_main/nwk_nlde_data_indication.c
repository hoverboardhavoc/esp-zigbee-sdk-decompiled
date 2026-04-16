/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> nwk_nlde_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_nlde_data_indication(nwk_nlde_data_ind_t *ind)

{
  zmsg_t *msg;
  int iVar1;
  undefined4 uVar2;
  byte bStack_25;
  undefined1 auStack_24 [3];
  uint8_t fcf;
  aps_header_t aps_hdr;
  
  msg = ind->nsdu;
  iVar1 = aps_frame_validate_nsdu(msg);
  if (iVar1 != 0) {
    zmsg_read_bytes(msg,0,1,&bStack_25);
    _auStack_24 = 0;
    aps_hdr.addr_info.src_addr = 0;
    aps_hdr.addr_info.dst_addr = 0;
    aps_hdr.addr_info.grp_addr = 0;
    aps_hdr.addr_info.src_ep = '\0';
    aps_hdr.addr_info.dst_ep = '\0';
    aps_hdr.addr_info.cluster_id = 0;
    aps_hdr.addr_info.profile_id = 0;
    aps_hdr.fcf = '\0';
    aps_hdr.aps_cntr = '\0';
    iVar1 = aps_frame_parse_hdr(msg,auStack_24);
    if ((iVar1 == 0) &&
       (((auStack_24._0_2_ = ind->src_addr, register0x0000203e = ind->dst_addr,
         (bStack_25 & 0xc) != 0xc ||
         (iVar1 = aps_group_table_find(aps_hdr.addr_info._0_4_ & 0xffff), iVar1 != 0)) &&
        (iVar1 = aps_process_receive_security(_auStack_24 & 0xffff,msg), iVar1 == 0)))) {
      if ((bStack_25 & 3) == 1) {
        uVar2 = zmsg_get_offset(msg);
        zmsg_read_bytes(msg,uVar2,1,&aps_hdr.addr_info.profile_id);
      }
      else {
        aps_hdr.addr_info.profile_id._0_1_ = 0;
      }
      if (((char)bStack_25 < '\0') && ((aps_hdr.addr_info._8_4_ & 3) != 2)) {
        aps_reasm_handle_frag(auStack_24,msg);
        return;
      }
      aps_handle_datagram((aps_header_t *)auStack_24,msg);
      return;
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> nwk_intrp_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: aps_hdr */
/* WARNING: Unknown calling convention */

void nwk_intrp_data_indication(nwk_intrp_data_ind_t *ind)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  zmsg_t *msg;
  undefined1 local_30 [4];
  aps_intrp_header_t aps_hdr;
  
  local_30 = (undefined1  [4])0x0;
  aps_hdr.fcf = '\0';
  aps_hdr._1_1_ = 0;
  aps_hdr.cluster_id = 0;
  aps_hdr.profile_id = 0;
  aps_hdr.src_panid = 0;
  aps_hdr.src_addr._0_4_ = 0;
  aps_hdr.src_addr.u._2_4_ = 0;
  aps_hdr._16_4_ = 0;
  aps_hdr.dst_addr._0_4_ = 0;
  aps_hdr.dst_addr.u._2_4_ = 0;
  msg = ind->nsdu;
  iVar2 = zmsg_get_offset(msg);
  iVar3 = aps_frame_validate_nsdu(msg);
  if (iVar3 == 0) {
    if (msg != (zmsg_t *)0x0) {
      zmsg_free(msg);
    }
  }
  else {
    iVar3 = zmsg_read_bytes(msg,iVar2,1,local_30);
    uVar1 = iVar2 + iVar3 & 0xffff;
    if (((uint)local_30 & 3) == 3) {
      if (((uint)local_30 & 0xc) == 0xc) {
        aps_hdr.src_addr.u._6_1_ = 1;
        iVar2 = zmsg_read_bytes(msg,uVar1,2,&aps_hdr.dst_panid);
        uVar1 = iVar2 + uVar1 & 0xffff;
      }
      else {
        aps_hdr._16_4_ = *(undefined4 *)&ind->dst_addr;
        aps_hdr.dst_addr._0_4_ = *(undefined4 *)((int)&(ind->dst_addr).u + 2);
        aps_hdr.dst_addr.u.group_addr.bcast = *(undefined2 *)((int)&(ind->dst_addr).u + 6);
      }
      iVar2 = zmsg_read_bytes(msg,uVar1,2,local_30 + 2);
      uVar1 = uVar1 + iVar2 & 0xffff;
      iVar2 = zmsg_read_bytes(msg,uVar1,2,&aps_hdr);
      aps_hdr._4_4_ = *(undefined4 *)&ind->src_addr;
      aps_hdr.src_addr._0_4_ = *(undefined4 *)((int)&(ind->src_addr).u + 2);
      aps_hdr.cluster_id = ind->src_panid;
      aps_hdr.src_addr.u._2_4_ = *(undefined4 *)((int)&(ind->src_addr).u + 6);
      aps_hdr.dst_addr.u._4_1_ = ind->lqi;
      aps_hdr.dst_addr.u._5_1_ = ind->rssi;
      zmsg_remove_header(msg,uVar1 + iVar2 & 0xffff);
      aps_handle_intrp_data_ind((aps_intrp_header_t *)local_30,msg);
    }
    else if (msg != (zmsg_t *)0x0) {
      zmsg_free(msg);
    }
  }
  return;
}


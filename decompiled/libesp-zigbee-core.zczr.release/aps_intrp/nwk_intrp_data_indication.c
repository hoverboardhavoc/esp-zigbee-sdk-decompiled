/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_intrp.o -> nwk_intrp_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_intrp_data_indication(nwk_intrp_data_ind_t *ind)

{
  uint uVar1;
  zmsg_t *pzVar2;
  int iVar3;
  int iVar4;
  byte abStack_68 [2];
  undefined2 uStack_66;
  aps_intrp_header_t aps_hdr;
  aps_intrp_data_ind_t ind_1;
  
  memset(abStack_68,0,0x20);
  pzVar2 = ind->nsdu;
  iVar3 = zmsg_get_offset(pzVar2);
  iVar4 = aps_frame_validate_nsdu(pzVar2);
  if ((iVar4 != 0) && (iVar4 = zmsg_read_bytes(pzVar2,iVar3,1,abStack_68), (abStack_68[0] & 3) == 3)
     ) {
    uVar1 = iVar3 + iVar4 & 0xffff;
    if ((abStack_68[0] & 0xc) == 0xc) {
      aps_hdr.src_addr.u._6_1_ = 1;
      iVar3 = zmsg_read_bytes(pzVar2,uVar1,2,&aps_hdr.dst_panid);
      uVar1 = uVar1 + iVar3 & 0xffff;
    }
    else {
      memcpy((void *)((int)&aps_hdr.src_addr.u + 6),&ind->dst_addr,10);
    }
    iVar3 = zmsg_read_bytes(pzVar2,uVar1,2,&uStack_66);
    uVar1 = uVar1 + iVar3 & 0xffff;
    iVar3 = zmsg_read_bytes(pzVar2,uVar1,2,&aps_hdr);
    memcpy(&aps_hdr.profile_id,&ind->src_addr,10);
    aps_hdr.cluster_id = ind->src_panid;
    aps_hdr.src_addr.u._4_2_ = ind->dst_panid;
    aps_hdr.dst_addr.u._4_1_ = ind->lqi;
    aps_hdr.dst_addr.u._5_1_ = ind->rssi;
    zmsg_remove_header(pzVar2,uVar1 + iVar3 & 0xffff);
    aps_hdr.dst_addr.u._6_2_ = aps_hdr.cluster_id;
    memcpy(&aps_hdr.lqi,&aps_hdr.profile_id,10);
    ind_1.src_addr.u._4_2_ = aps_hdr.src_addr.u._4_2_;
    memcpy((void *)((int)&ind_1.src_addr.u + 6),(void *)((int)&aps_hdr.src_addr.u + 6),10);
    ind_1.profile_id._0_1_ = 0;
    ind_1.dst_addr.u._4_2_ = aps_hdr._0_2_;
    ind_1.dst_addr.u._6_2_ = uStack_66;
    ind_1.asdu._0_2_ = aps_hdr.dst_addr.u._4_2_;
    ind_1._28_4_ = pzVar2;
    aps_intrp_data_indication((aps_intrp_data_ind_t *)((int)&aps_hdr.dst_addr.u + 6));
    return;
  }
  if (pzVar2 != (zmsg_t *)0x0) {
    zmsg_free(pzVar2);
  }
  return;
}


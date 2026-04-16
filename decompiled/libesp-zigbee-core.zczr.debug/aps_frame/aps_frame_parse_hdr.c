/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_parse_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_frame_parse_hdr(zmsg_t *msg,aps_header_t *aps_hdr)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  byte abStack_21 [4];
  uint8_t scf;
  
  uVar1 = zmsg_read_bytes(0,1,&aps_hdr->fcf);
  bVar3 = aps_hdr->fcf;
  if (((bVar3 & 3) != 1) && (((bVar3 & 3) != 2 || ((bVar3 & 0x10) == 0)))) {
    if ((bVar3 & 0xc) == 0xc) {
      iVar2 = zmsg_read_bytes(msg,uVar1,2,&(aps_hdr->addr_info).grp_addr);
    }
    else {
      iVar2 = zmsg_read_bytes(msg,uVar1,1,&(aps_hdr->addr_info).dst_ep);
    }
    uVar1 = uVar1 + iVar2 & 0xffff;
    iVar2 = zmsg_read_bytes(msg,uVar1,2,&(aps_hdr->addr_info).cluster_id);
    uVar1 = uVar1 + iVar2 & 0xffff;
    iVar2 = zmsg_read_bytes(msg,uVar1,2,&(aps_hdr->addr_info).profile_id);
    uVar1 = uVar1 + iVar2 & 0xffff;
    iVar2 = zmsg_read_bytes(msg,uVar1,1,&(aps_hdr->addr_info).src_ep);
    uVar1 = uVar1 + iVar2 & 0xffff;
  }
  iVar2 = zmsg_read_bytes(msg,uVar1,1,&aps_hdr->aps_cntr);
  uVar1 = uVar1 + iVar2 & 0xffff;
  if ((char)aps_hdr->fcf < '\0') {
    (aps_hdr->ext_hdr).block_nr = '\x01';
    (aps_hdr->ext_hdr).ack_bits = '\0';
    iVar2 = zmsg_read_bytes(msg,uVar1,1,&aps_hdr->ext_hdr);
    uVar1 = iVar2 + uVar1 & 0xffff;
    bVar3 = (aps_hdr->ext_hdr).ext_fcf & 3;
    if ((bVar3 == 1) || (bVar3 == 2)) {
      iVar2 = zmsg_read_bytes(msg,uVar1,1,&(aps_hdr->ext_hdr).block_nr);
      uVar1 = iVar2 + uVar1 & 0xffff;
      if ((aps_hdr->fcf & 3) == 2) {
        iVar2 = zmsg_read_bytes(msg,uVar1,1,&(aps_hdr->ext_hdr).ack_bits);
        uVar1 = iVar2 + uVar1 & 0xffff;
      }
    }
  }
  if ((aps_hdr->fcf & 0x20) != 0) {
    zmsg_read_bytes(msg,uVar1,1,abStack_21);
    if ((abStack_21[0] & 0x20) == 0) {
      iVar2 = 5;
    }
    else {
      iVar2 = 0xd;
    }
    if ((abStack_21[0] & 0x18) == 8) {
      iVar2 = iVar2 + 1;
    }
    uVar1 = iVar2 + uVar1 & 0xffff;
  }
  if ((aps_hdr->fcf & 3) == 1) {
    zmsg_read_bytes(msg,uVar1,1,&aps_hdr->cmd_id);
  }
  return 0;
}


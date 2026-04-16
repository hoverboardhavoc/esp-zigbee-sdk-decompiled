/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_parse_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_frame_parse_hdr(zmsg_t *msg,aps_header_t *aps_hdr)

{
  byte fcf;
  _Bool _Var1;
  uint16_t uVar2;
  uint16_t uVar3;
  short sVar4;
  short sVar5;
  undefined3 extraout_var;
  byte abStack_21 [4];
  uint8_t scf;
  
  uVar2 = zmsg_read_u8(msg,0,&aps_hdr->fcf);
  fcf = aps_hdr->fcf;
  _Var1 = aps_fcf_has_address(fcf);
  if (CONCAT31(extraout_var,_Var1) != 0) {
    if ((fcf & 0xc) == 0xc) {
      uVar3 = zmsg_read_bytes(msg,uVar2,2,&(aps_hdr->addr_info).grp_addr);
    }
    else {
      uVar3 = zmsg_read_u8(msg,uVar2,&(aps_hdr->addr_info).dst_ep);
    }
    sVar4 = zmsg_read_bytes(msg,uVar2 + uVar3,2,&(aps_hdr->addr_info).cluster_id);
    sVar4 = uVar2 + uVar3 + sVar4;
    sVar5 = zmsg_read_bytes(msg,sVar4,2,&(aps_hdr->addr_info).profile_id);
    uVar2 = sVar4 + sVar5;
    uVar3 = zmsg_read_u8(msg,uVar2,&(aps_hdr->addr_info).src_ep);
    uVar2 = uVar2 + uVar3;
  }
  uVar3 = zmsg_read_u8(msg,uVar2,&aps_hdr->aps_cntr);
  uVar2 = uVar2 + uVar3;
  if ((char)aps_hdr->fcf < '\0') {
    (aps_hdr->ext_hdr).block_nr = '\x01';
    (aps_hdr->ext_hdr).ack_bits = '\0';
    uVar3 = zmsg_read_u8(msg,uVar2,&(aps_hdr->ext_hdr).ext_fcf);
    uVar2 = uVar3 + uVar2;
    if ((byte)(((aps_hdr->ext_hdr).ext_fcf & 3) - 1) < 2) {
      uVar3 = zmsg_read_u8(msg,uVar2,&(aps_hdr->ext_hdr).block_nr);
      uVar2 = uVar3 + uVar2;
      if ((aps_hdr->fcf & 3) == 2) {
        uVar3 = zmsg_read_u8(msg,uVar2,&(aps_hdr->ext_hdr).ack_bits);
        uVar2 = uVar3 + uVar2;
      }
    }
  }
  if ((aps_hdr->fcf & 0x20) != 0) {
    zmsg_read_u8(msg,uVar2,abStack_21);
    uVar2 = (abStack_21[0] >> 2 & 8) + 5 + (ushort)((abStack_21[0] & 0x18) == 8) + uVar2;
  }
  if ((aps_hdr->fcf & 3) == 1) {
    zmsg_read_u8(msg,uVar2,&aps_hdr->cmd_id);
  }
  return 0;
}


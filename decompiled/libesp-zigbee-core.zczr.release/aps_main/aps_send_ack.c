/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_send_ack(aps_header_t *aps_hdr,uint8_t block_num,uint8_t ack_bits)

{
  uint16_t uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  undefined4 uStack_38;
  ezb_extaddr_t src_addr;
  aps_hdr_addr_s addr_field;
  
  iVar3 = zmsg_alloc(0x2f);
  if (iVar3 == 0) {
    return 1;
  }
  uVar7 = (uint)aps_hdr->fcf;
  if ((aps_hdr->fcf & 3) != 0) {
    bVar8 = 0x12;
    if ((uVar7 & 3) == 1) goto _L0;
    __assert_func(0,0,0,0);
  }
  bVar8 = 2;
_L0:
  bVar9 = bVar8 | (byte)uVar7 & 0xa0;
  src_addr.field_0.u8[4] = bVar9;
  zmsg_append_bytes(iVar3,1,(undefined1 *)((int)&src_addr.field_0 + 4));
  if ((bVar8 & 0x10) == 0) {
    uVar1 = (aps_hdr->addr_info).cluster_id;
    src_addr.field_0.u8[5] = (char)uVar1;
    src_addr.field_0.u8[4] = (aps_hdr->addr_info).src_ep;
    src_addr.field_0.u8[6] = (char)(uVar1 >> 8);
    src_addr.field_0.u8[7] = (char)(aps_hdr->addr_info).profile_id;
    zmsg_append_bytes(iVar3,6,(undefined1 *)((int)&src_addr.field_0 + 4));
  }
  src_addr.field_0.u8[4] = aps_hdr->aps_cntr;
  zmsg_append_bytes(iVar3,1,(undefined1 *)((int)&src_addr.field_0 + 4));
  if ((char)bVar9 < '\0') {
    bVar8 = (aps_hdr->ext_hdr).ext_fcf;
    uVar2 = src_addr.field_0.u8[7];
    src_addr.field_0.u64._4_4_ = (uint)src_addr.field_0.u8[7] << 0x18;
    src_addr.field_0.u8[4] = bVar8;
    uVar5 = 1;
    if ((byte)((bVar8 & 3) - 1) < 2) {
      src_addr.field_0.u8[5] = block_num;
      src_addr.field_0.u8[6] = ack_bits;
      src_addr.field_0.u64._4_4_ = CONCAT13(uVar2,src_addr.field_0.u64._4_3_);
      puVar6 = (undefined4 *)((int)&src_addr.field_0 + 4);
      uVar5 = 3;
    }
    else {
      uStack_38 = CONCAT31(uStack_38._1_3_,bVar8);
      puVar6 = &uStack_38;
    }
    zmsg_append_bytes(iVar3,uVar5,puVar6);
  }
  if ((uVar7 & 0x20) != 0) {
    src_addr.field_0.u64._4_4_ = 0;
    zmsg_append_bytes(iVar3,5,(undefined1 *)((int)&src_addr.field_0 + 4));
  }
  uStack_38 = 0;
  src_addr.field_0.u64._0_4_ = 0;
  nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,&uStack_38);
  iVar4 = aps_process_transmit_security(&uStack_38,iVar3);
  if ((iVar4 == 0) &&
     (src_addr.field_0.u64._4_4_ = iVar3,
     iVar4 = nwk_nlde_data_request((undefined1 *)((int)&src_addr.field_0 + 4)), iVar4 == 0)) {
    return 0;
  }
  zmsg_free(iVar3);
  return iVar4;
}


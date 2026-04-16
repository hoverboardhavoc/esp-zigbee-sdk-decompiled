/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_send_ack(aps_header_t *aps_hdr,uint8_t block_num,uint8_t ack_bits)

{
  uint16_t uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  byte bStack_39;
  undefined4 uStack_38;
  aps_hdr_addr_s addr_field;
  undefined4 uStack_28;
  ezb_extaddr_t src_addr;
  
  iVar2 = zmsg_alloc(0x2f);
  if (iVar2 == 0) {
    iVar3 = 1;
    goto _L0;
  }
  uVar4 = (uint)aps_hdr->fcf;
  if ((aps_hdr->fcf & 3) == 0) {
_L0:
    bVar5 = 2;
  }
  else {
    if ((uVar4 & 3) != 1) {
      __assert_func("//build/esp-zigbee/src/core/aps/aps_main.c",0x9b,"aps_send_ack",&_L0);
      goto _L0;
    }
    bVar5 = 0x12;
  }
  bVar6 = bVar5 | (byte)uVar4 & 0xa0;
  uStack_38 = CONCAT31(uStack_38._1_3_,bVar6);
  zmsg_append_bytes(iVar2,1,&uStack_38);
  if (((bVar5 & 2) != 1) && (((bVar5 & 2) == 0 || ((bVar5 & 0x10) == 0)))) {
    addr_field._2_2_ = SUB42(addr_field._0_4_,2);
    addr_field.cluster_id._0_1_ = (aps_hdr->addr_info).dst_ep;
    uVar1 = (aps_hdr->addr_info).cluster_id;
    uStack_38._0_2_ = CONCAT11((char)uVar1,(aps_hdr->addr_info).src_ep);
    uStack_38._0_3_ = CONCAT12((char)(uVar1 >> 8),(undefined2)uStack_38);
    uVar1 = (aps_hdr->addr_info).profile_id;
    uStack_38 = CONCAT13((char)uVar1,(undefined3)uStack_38);
    addr_field.dst_ep = (uint8_t)(uVar1 >> 8);
    zmsg_append_bytes(iVar2,6,&uStack_38);
  }
  uStack_38 = CONCAT31(uStack_38._1_3_,aps_hdr->aps_cntr);
  zmsg_append_bytes(iVar2,1,&uStack_38);
  if ((char)bVar6 < '\0') {
    bVar6 = uStack_38._3_1_;
    uStack_38 = (uint)uStack_38._3_1_ << 0x18;
    bVar5 = (aps_hdr->ext_hdr).ext_fcf;
    uStack_38 = CONCAT31(uStack_38._1_3_,bVar5);
    if (((bVar5 & 3) == 1) || ((bVar5 & 3) == 2)) {
      uStack_38._0_2_ = CONCAT11(block_num,bVar5);
      uStack_38._0_3_ = CONCAT12(ack_bits,(undefined2)uStack_38);
      uStack_38 = CONCAT13(bVar6,(undefined3)uStack_38);
      zmsg_append_bytes(iVar2,3,&uStack_38);
    }
    else {
      bStack_39 = bVar5;
      zmsg_append_bytes(iVar2,1,&bStack_39);
    }
  }
  if ((uVar4 & 0x20) != 0) {
    uStack_38 = 0;
    addr_field._0_4_ = 0;
    stack0xffffffd0 = 0;
    zmsg_append_bytes(iVar2,5,&uStack_38);
  }
  uStack_28 = 0;
  src_addr.field_0.u64._0_4_ = 0;
  nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,&uStack_28);
  iVar3 = aps_process_transmit_security(&uStack_28,iVar2);
  if (iVar3 == 0) {
    addr_field._2_2_ = 0;
    addr_field._0_2_ = (aps_hdr->addr_info).src_addr;
    stack0xffffffd0 = 0x30000;
    uStack_38 = iVar2;
    iVar3 = nwk_nlde_data_request(&uStack_38);
    if (iVar3 == 0) {
      return 0;
    }
  }
_L0:
  if (iVar2 != 0) {
    zmsg_free(iVar2);
  }
  return iVar3;
}


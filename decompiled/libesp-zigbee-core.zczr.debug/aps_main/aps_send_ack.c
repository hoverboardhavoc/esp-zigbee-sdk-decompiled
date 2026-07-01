/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_send_ack(aps_header_t *aps_hdr,zmsg_t *rx_msg,uint8_t block_num,uint8_t ack_bits)

{
  uint16_t uVar1;
  byte bVar2;
  zmsg_t *pzVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  undefined4 local_50;
  aps_device_key_pair_t *key_pair;
  aps_hdr_addr_s addr_field;
  aps_apsde_data_req_t aStack_3c;
  
  pzVar3 = (zmsg_t *)zmsg_alloc(0x2f);
  if (pzVar3 == (zmsg_t *)0x0) {
_L0:
    iVar4 = 1;
  }
  else {
    uVar5 = (uint)aps_hdr->fcf;
    if ((aps_hdr->fcf & 3) == 0) {
_L0:
      bVar2 = 2;
    }
    else {
      if ((uVar5 & 3) != 1) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x92,
                      "aps_send_ack",&_LC2);
        goto _L0;
      }
      bVar2 = 0x12;
    }
    bVar6 = bVar2 | (byte)uVar5 & 0xa0;
    key_pair = (aps_device_key_pair_t *)CONCAT31(key_pair._1_3_,bVar6);
    zmsg_append_bytes(pzVar3,1,&key_pair);
    if (((bVar2 & 2) != 1) && (((bVar2 & 2) == 0 || ((bVar2 & 0x10) == 0)))) {
      addr_field._2_2_ = SUB42(addr_field._0_4_,2);
      addr_field.cluster_id._0_1_ = (aps_hdr->addr_info).dst_ep;
      uVar1 = (aps_hdr->addr_info).cluster_id;
      key_pair._0_2_ = CONCAT11((char)uVar1,(aps_hdr->addr_info).src_ep);
      key_pair._0_3_ = CONCAT12((char)(uVar1 >> 8),key_pair._0_2_);
      uVar1 = (aps_hdr->addr_info).profile_id;
      key_pair = (aps_device_key_pair_t *)CONCAT13((char)uVar1,key_pair._0_3_);
      addr_field.dst_ep = (uint8_t)(uVar1 >> 8);
      zmsg_append_bytes(pzVar3,6,&key_pair);
    }
    key_pair = (aps_device_key_pair_t *)CONCAT31(key_pair._1_3_,aps_hdr->aps_cntr);
    zmsg_append_bytes(pzVar3,1,&key_pair);
    if ((char)bVar6 < '\0') {
      bVar6 = key_pair._3_1_;
      key_pair = (aps_device_key_pair_t *)((uint)key_pair._3_1_ << 0x18);
      bVar2 = (aps_hdr->ext_hdr).ext_fcf;
      key_pair = (aps_device_key_pair_t *)CONCAT31(key_pair._1_3_,bVar2);
      if (((bVar2 & 3) == 1) || ((bVar2 & 3) == 2)) {
        key_pair._0_2_ = CONCAT11(block_num,bVar2);
        key_pair._0_3_ = CONCAT12(ack_bits,key_pair._0_2_);
        key_pair = (aps_device_key_pair_t *)CONCAT13(bVar6,key_pair._0_3_);
        zmsg_append_bytes(pzVar3,3,&key_pair);
      }
      else {
        local_50 = CONCAT31(local_50._1_3_,bVar2);
        zmsg_append_bytes(pzVar3,1,&local_50);
      }
    }
    if ((uVar5 & 0x20) != 0) {
      if ((rx_msg->flags & 4) == 0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0xb6,
                      "aps_send_ack",
                      "zmsg_test_flag(rx_msg, ((1 << ((2) % (sizeof(unsigned long) * 8)))))");
        goto _L0;
      }
      key_pair = (aps_device_key_pair_t *)0x0;
      addr_field._0_4_ = 0;
      stack0xffffffbc = 0;
      zmsg_append_bytes(pzVar3,5,&key_pair);
      zmsg_get_footer(rx_msg,&local_50,4);
      iVar4 = aps_process_transmit_security_by_key_pair(local_50,pzVar3);
      if (iVar4 != 0) goto _L0;
    }
    aStack_3c.dst_addr._0_4_ = 0;
    aStack_3c.dst_addr.u._2_4_ = 0;
    aStack_3c._12_4_ = 0;
    aStack_3c.cluster_id = 0;
    aStack_3c.profile_id = 0;
    aStack_3c.radius = '\0';
    aStack_3c.alias_seq_num = '\0';
    aStack_3c.alias_src_addr = 0;
    aStack_3c.field_9 = (anon_union_1_2_0b76fd53_for_aps_apsde_data_req_s_9)0x0;
    aStack_3c._25_3_ = 0;
    aStack_3c.asdu = pzVar3;
    iVar4 = aps_send_frame((aps_hdr->addr_info).src_addr,&aStack_3c);
    if (iVar4 == 0) {
      return 0;
    }
  }
_L0:
  if (pzVar3 != (zmsg_t *)0x0) {
    zmsg_free(pzVar3);
  }
  return iVar4;
}


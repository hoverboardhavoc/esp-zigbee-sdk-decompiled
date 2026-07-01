/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_send_ack(aps_header_t *aps_hdr,zmsg_t *rx_msg,uint8_t block_num,uint8_t ack_bits)

{
  uint16_t uVar1;
  ezb_shortaddr_t dst_addr;
  aps_device_key_pair_t *paVar2;
  int iVar3;
  undefined4 uVar4;
  aps_device_key_pair_t **ppaVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  aps_device_key_pair_t *local_40;
  aps_device_key_pair_t *key_pair;
  aps_hdr_addr_s addr_field;
  
  paVar2 = (aps_device_key_pair_t *)zmsg_alloc(0x2f);
  if (paVar2 == (aps_device_key_pair_t *)0x0) {
    iVar3 = 1;
  }
  else {
    uVar6 = (uint)aps_hdr->fcf;
    if ((aps_hdr->fcf & 3) == 0) goto _L0;
    bVar7 = 0x12;
    if ((uVar6 & 3) == 1) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      bVar7 = 2;
_L0:
      bVar8 = bVar7 | (byte)uVar6 & 0xa0;
      key_pair = (aps_device_key_pair_t *)CONCAT31(key_pair._1_3_,bVar8);
      zmsg_append_bytes(paVar2,1,&key_pair);
      if ((bVar7 & 0x10) == 0) {
        addr_field.cluster_id._0_1_ = (aps_hdr->addr_info).dst_ep;
        uVar1 = (aps_hdr->addr_info).cluster_id;
        key_pair._0_2_ = CONCAT11((char)uVar1,(aps_hdr->addr_info).src_ep);
        key_pair._0_3_ = CONCAT12((char)(uVar1 >> 8),key_pair._0_2_);
        uVar1 = (aps_hdr->addr_info).profile_id;
        key_pair = (aps_device_key_pair_t *)CONCAT13((char)uVar1,key_pair._0_3_);
        addr_field.dst_ep = (uint8_t)(uVar1 >> 8);
        zmsg_append_bytes(paVar2,6,&key_pair);
      }
      key_pair = (aps_device_key_pair_t *)CONCAT31(key_pair._1_3_,aps_hdr->aps_cntr);
      zmsg_append_bytes(paVar2,1,&key_pair);
      if ((char)bVar8 < '\0') {
        bVar7 = (aps_hdr->ext_hdr).ext_fcf;
        bVar8 = key_pair._3_1_;
        key_pair = (aps_device_key_pair_t *)((uint)key_pair._3_1_ << 0x18);
        key_pair = (aps_device_key_pair_t *)CONCAT31(key_pair._1_3_,bVar7);
        uVar4 = 1;
        if ((byte)((bVar7 & 3) - 1) < 2) {
          key_pair._0_2_ = CONCAT11(block_num,bVar7);
          key_pair._0_3_ = CONCAT12(ack_bits,key_pair._0_2_);
          key_pair = (aps_device_key_pair_t *)CONCAT13(bVar8,key_pair._0_3_);
          uVar4 = 3;
          ppaVar5 = &key_pair;
        }
        else {
          local_40 = (aps_device_key_pair_t *)CONCAT31(local_40._1_3_,bVar7);
          ppaVar5 = &local_40;
        }
        zmsg_append_bytes(paVar2,uVar4,ppaVar5);
      }
      if ((uVar6 & 0x20) == 0) goto _L0;
      uVar6 = 0;
    } while ((rx_msg->flags & 4) == 0);
    key_pair = (aps_device_key_pair_t *)0x0;
    addr_field._0_4_ = 0;
    stack0xffffffcc = 0;
    zmsg_append_bytes(paVar2,5,&key_pair);
    zmsg_get_footer(rx_msg,&local_40,4);
    iVar3 = aps_process_transmit_security_by_key_pair(local_40,paVar2);
    if (iVar3 == 0) {
_L0:
      dst_addr = (aps_hdr->addr_info).src_addr;
      memset(&addr_field,0,0x18);
      key_pair = paVar2;
      iVar3 = aps_send_frame(dst_addr,(aps_apsde_data_req_t *)&key_pair);
      if (iVar3 == 0) {
        return 0;
      }
    }
    zmsg_free(paVar2);
  }
  return iVar3;
}


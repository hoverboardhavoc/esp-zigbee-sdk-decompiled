/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_process_transmit_security_by_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_process_transmit_security_by_key_pair(aps_device_key_pair_t *key_pair,zmsg_t *msg)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  uint16_t uVar4;
  short sVar5;
  int iVar6;
  uint32_t uVar7;
  undefined4 *puVar8;
  short sVar9;
  uint uVar10;
  aps_device_key_pair_t *apaStack_64 [4];
  byte bStack_51;
  uint uStack_50;
  uint8_t ext_fcf;
  secur_ccm_nonce_t ccm_nonce;
  uint8_t key [16];
  secur_aux_hdr_t aux_hdr;
  uint8_t aps_fcf;
  
  apaStack_64[0] = key_pair;
  iVar6 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,1,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 6));
  uVar3 = aux_hdr.src_address.field_0.u8[6];
  uVar4 = aps_fcf_get_hdr_size(aux_hdr.src_address.field_0.u8[6]);
  if ((char)uVar3 < '\0') {
    sVar5 = zmsg_read_bytes(msg,uVar4,1,&bStack_51);
    if ((bStack_51 & 3) == 1) {
      sVar9 = 1;
    }
    else if ((bStack_51 & 3) == 2) {
      sVar9 = 1;
    }
    else {
      sVar9 = 0;
    }
    uVar4 = uVar4 + sVar5 + sVar9;
  }
  if ((aux_hdr.src_address.field_0.u8[6] & 0x20) == 0) {
    iVar6 = 0;
  }
  else if (iVar6 == 0) {
    iVar6 = 0x13;
  }
  else if (apaStack_64[0] == (aps_device_key_pair_t *)0x0) {
    iVar6 = 0x13;
  }
  else {
    zmsg_read_bytes(msg,uVar4,0xe,key + 0xc);
    key[0xc] = key[0xc] | (byte)iVar6 & 7;
    uVar7 = aps_secur_inc_frame_cntr(apaStack_64[0]);
    key[0xd] = (uint8_t)uVar7;
    key[0xe] = (uint8_t)(uVar7 >> 8);
    key[0xf] = (uint8_t)(uVar7 >> 0x10);
    aux_hdr.scf = (uint8_t)(uVar7 >> 0x18);
    puVar8 = (undefined4 *)nwk_get_extended_address();
    uVar1 = *puVar8;
    uVar2 = puVar8[1];
    aux_hdr.frame_cntr._0_1_ = (char)*(undefined3 *)puVar8;
    aux_hdr.frame_cntr._1_1_ = (char)((uint)uVar1 >> 8);
    aux_hdr.frame_cntr._2_1_ = (char)((uint)uVar1 >> 0x10);
    aux_hdr.src_address.field_0.u8[0] = (char)*(undefined3 *)(puVar8 + 1);
    aux_hdr.frame_cntr._3_1_ = (char)((uint)uVar1 >> 0x18);
    aux_hdr.src_address.field_0.u8[1] = (char)((uint)uVar2 >> 8);
    aux_hdr.src_address.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
    aux_hdr.src_address.field_0.u8[3] = (uint8_t)((uint)uVar2 >> 0x18);
    if ((key._12_4_ & 0x20) == 0) {
      sVar5 = 5;
    }
    else {
      sVar5 = 0xd;
    }
    if ((key._12_4_ & 0x18) == 8) {
      sVar5 = sVar5 + 1;
    }
    zmsg_write_bytes(msg,uVar4,sVar5,key + 0xc);
    if ((aux_hdr._0_4_ << 0x18 | (uint)key._12_4_ >> 8) == 0xffffffff) {
      iVar6 = 0x13;
    }
    else {
      aps_secur_key_pair_get_key
                (apaStack_64[0],&ccm_nonce.security_control,key._12_4_ & SECUR_SCF_KL_KEY);
      uVar10 = 0x10;
      do {
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1 & 0xff;
      } while ((&ccm_nonce.security_control)[uVar10] == '\0');
      if (uVar10 == 0) {
        iVar6 = 0x13;
      }
      else {
        uStack_50 = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
        ccm_nonce.source_address.field_0.u64._0_4_ =
             (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
        ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | (uint)key._12_4_ >> 8;
        ccm_nonce.frame_counter._0_1_ = key[0xc];
        iVar6 = secur_secure_msg(iVar6,&ccm_nonce.security_control,&stack0xffffffb0,msg,
                                 sVar5 + uVar4);
        if (iVar6 == 0) {
          msg->flags = msg->flags | 4;
          zmsg_add_footer(msg,apaStack_64,4);
          bStack_51 = (byte)key._12_4_ & 0xf8;
          key._12_4_ = key._12_4_ & 0xfffffff8;
          zmsg_write_bytes(msg,uVar4,1,&bStack_51);
        }
      }
    }
  }
  return iVar6;
}


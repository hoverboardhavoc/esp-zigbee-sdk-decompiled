/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_process_transmit_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_process_transmit_security(ezb_extaddr_t *dst_addr,zmsg_t *msg)

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
  byte bStack_55;
  uint uStack_54;
  uint8_t ext_fcf;
  secur_ccm_nonce_t ccm_nonce;
  uint8_t key [16];
  aps_device_key_pair_t *key_pair;
  secur_aux_hdr_t aux_hdr;
  uint8_t aps_fcf;
  
  iVar6 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,1,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 6));
  uVar3 = aux_hdr.src_address.field_0.u8[6];
  uVar4 = aps_fcf_get_hdr_size(aux_hdr.src_address.field_0.u8[6]);
  if ((char)uVar3 < '\0') {
    sVar5 = zmsg_read_bytes(msg,uVar4,1,&bStack_55);
    if ((bStack_55 & 3) == 1) {
      sVar9 = 1;
    }
    else if ((bStack_55 & 3) == 2) {
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
  else {
    msg->flags = msg->flags | 4;
    if (iVar6 == 0) {
      iVar6 = 0x13;
    }
    else {
      key._12_4_ = aps_secur_get_key_pair_by_addr(dst_addr);
      if ((aps_device_key_pair_t *)key._12_4_ == (aps_device_key_pair_t *)0x0) {
        iVar6 = 0x13;
      }
      else {
        zmsg_read_bytes(msg,uVar4,0xe,&key_pair);
        key_pair = (aps_device_key_pair_t *)
                   CONCAT31(key_pair._1_3_,(byte)key_pair | (byte)iVar6 & 7);
        uVar7 = aps_secur_inc_frame_cntr((aps_device_key_pair_t *)key._12_4_);
        key_pair = (aps_device_key_pair_t *)
                   CONCAT13((char)(uVar7 >> 0x10),
                            CONCAT12((char)(uVar7 >> 8),CONCAT11((char)uVar7,(byte)key_pair)));
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
        if (((uint)key_pair & 0x20) == 0) {
          sVar5 = 5;
        }
        else {
          sVar5 = 0xd;
        }
        if (((uint)key_pair & 0x18) == 8) {
          sVar5 = sVar5 + 1;
        }
        zmsg_write_bytes(msg,uVar4,sVar5,&key_pair);
        if ((aux_hdr._0_4_ << 0x18 | (uint)key_pair >> 8) == 0xffffffff) {
          iVar6 = 0x13;
        }
        else {
          aps_secur_key_pair_get_key
                    ((aps_device_key_pair_t *)key._12_4_,&ccm_nonce.security_control,
                     (uint)key_pair & SECUR_SCF_KL_KEY);
          uVar10 = 0x10;
          do {
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1 & 0xff;
          } while ((&ccm_nonce.security_control)[uVar10] == '\0');
          if (uVar10 == 0) {
            iVar6 = 0x13;
          }
          else {
            uStack_54 = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
            ccm_nonce.source_address.field_0.u64._0_4_ =
                 (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
            ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | (uint)key_pair >> 8
            ;
            ccm_nonce.frame_counter._0_1_ = (byte)key_pair;
            iVar6 = secur_secure_msg(iVar6,&ccm_nonce.security_control,&stack0xffffffac,msg,
                                     sVar5 + uVar4);
            if (iVar6 == 0) {
              zmsg_add_footer(msg,key + 0xc,4);
              bStack_55 = (byte)key_pair & 0xf8;
              key_pair = (aps_device_key_pair_t *)((uint)key_pair & 0xfffffff8);
              zmsg_write_bytes(msg,uVar4,1,&bStack_55);
            }
          }
        }
      }
    }
  }
  return iVar6;
}


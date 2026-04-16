/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_process_transmit_security
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
  byte bVar3;
  aps_device_key_pair_t *paVar4;
  uint uVar5;
  uint8_t uVar6;
  _Bool _Var7;
  uint16_t uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint32_t uVar12;
  byte bStack_56;
  byte bStack_55;
  uint8_t aps_fcf;
  aps_device_key_pair_t *paStack_54;
  aps_device_key_pair_t *key_pair;
  secur_ccm_nonce_t ccm_nonce;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  secur_aux_hdr_t aux_hdr;
  uint8_t key [16];
  
  iVar9 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,1,&bStack_56);
  bVar3 = bStack_56;
  uVar8 = aps_fcf_get_hdr_size(bStack_56);
  uVar5 = (uint)uVar8;
  if ((char)bVar3 < '\0') {
    iVar10 = zmsg_read_bytes(msg,uVar5,1,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 7));
    uVar5 = ((aux_hdr.src_address.field_0.u8[7] & 3) - 1 < 2) + uVar5 + iVar10 & 0xffff;
  }
  iVar10 = 0;
  if ((bStack_56 & 0x20) != 0) {
    msg->flags = msg->flags | 4;
    if (iVar9 != 0) {
      paStack_54 = aps_secur_get_key_pair_by_addr(dst_addr);
      if (paStack_54 != (aps_device_key_pair_t *)0x0) {
        zmsg_read_bytes(msg,uVar5,0xe,&ccm_nonce.security_control);
        paVar4 = paStack_54;
        stack0xffffffc0 = CONCAT31(_uStack_3f,ccm_nonce.security_control | (byte)iVar9 & 7);
        if ((paStack_54->outgoing_frame_cntr & 0x3ff) == 0) {
          aps_secur_store_key_pair(paStack_54);
        }
        uVar12 = paVar4->outgoing_frame_cntr;
        paVar4->outgoing_frame_cntr = uVar12 + 1;
        stack0xffffffc0 =
             CONCAT13((char)(uVar12 >> 0x10),
                      CONCAT12((char)(uVar12 >> 8),CONCAT11((char)uVar12,ccm_nonce.security_control)
                              ));
        aux_hdr.scf = (uint8_t)(uVar12 >> 0x18);
        puVar11 = (undefined4 *)nwk_get_extended_address();
        uVar1 = *puVar11;
        uVar2 = puVar11[1];
        aux_hdr.frame_cntr._0_1_ = (char)*(undefined3 *)puVar11;
        aux_hdr.frame_cntr._1_1_ = (char)((uint)uVar1 >> 8);
        aux_hdr.src_address.field_0.u8[3] = (uint8_t)((uint)uVar2 >> 0x18);
        aux_hdr.frame_cntr._2_1_ = (char)((uint)uVar1 >> 0x10);
        aux_hdr.src_address.field_0.u8[0] = (char)*(undefined3 *)(puVar11 + 1);
        aux_hdr.frame_cntr._3_1_ = (char)((uint)uVar1 >> 0x18);
        aux_hdr.src_address.field_0.u64._1_2_ = (short)((uint)uVar2 >> 8);
        uVar6 = secur_scf_get_aux_hdr_size(ccm_nonce.security_control);
        zmsg_write_bytes(msg,uVar5,CONCAT31(extraout_var,uVar6),&ccm_nonce.security_control);
        if ((aux_hdr._0_4_ << 0x18 | stack0xffffffc0 >> 8) != 0xffffffff) {
          aps_secur_key_pair_get_key
                    (paStack_54,aux_hdr.src_address.field_0.u8 + 7,
                     stack0xffffffc0 & SECUR_SCF_KL_KEY);
          _Var7 = secur_is_key_valid(aux_hdr.src_address.field_0.u8 + 7);
          if (CONCAT31(extraout_var_00,_Var7) != 0) {
            key_pair = (aps_device_key_pair_t *)(aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8);
            ccm_nonce.source_address.field_0.u64._0_4_ =
                 (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
            ccm_nonce.source_address.field_0.u64._4_4_ =
                 aux_hdr._0_4_ << 0x18 | stack0xffffffc0 >> 8;
            ccm_nonce.frame_counter._0_1_ = ccm_nonce.security_control;
            iVar10 = secur_secure_msg(iVar9,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 7),
                                      &key_pair,msg,CONCAT31(extraout_var,uVar6) + uVar5 & 0xffff);
            if (iVar10 == 0) {
              zmsg_add_footer(msg,&stack0xffffffac,4);
              bStack_55 = (byte)stack0xffffffc0 & 0xf8;
              stack0xffffffc0 = stack0xffffffc0 & 0xfffffff8;
              zmsg_write_bytes(msg,uVar5,1,&bStack_55);
            }
            goto _L0;
          }
        }
      }
    }
    iVar10 = 0x13;
  }
_L0:
  secur_key_clear(aux_hdr.src_address.field_0.u8 + 7);
  return iVar10;
}


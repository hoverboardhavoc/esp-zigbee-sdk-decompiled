/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_process_transmit_done_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_process_transmit_done_security(zmsg_t *msg)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte bVar3;
  secur_scf_key_id_t sVar4;
  uint uVar5;
  uint8_t uVar6;
  _Bool _Var7;
  uint16_t uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined3 extraout_var;
  undefined4 *puVar11;
  undefined3 extraout_var_00;
  ezb_err_t eVar12;
  uint uVar13;
  byte bStack_55;
  aps_device_key_pair_t *paStack_54;
  uint8_t aps_fcf;
  aps_device_key_pair_t *key_pair;
  secur_ccm_nonce_t ccm_nonce;
  undefined3 uStack_3f;
  secur_aux_hdr_t aux_hdr;
  uint8_t key [16];
  
  uVar9 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,1,&bStack_55);
  bVar3 = bStack_55;
  uVar8 = aps_fcf_get_hdr_size(bStack_55);
  uVar5 = (uint)uVar8;
  if ((char)bVar3 < '\0') {
    iVar10 = zmsg_read_bytes(msg,uVar5,1,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 7));
    uVar5 = ((aux_hdr.src_address.field_0.u8[7] & 3) - 1 < 2) + uVar5 + iVar10 & 0xffff;
  }
  zmsg_set_offset(msg,uVar5);
  eVar12 = 0;
  if ((bStack_55 & 0x20) != 0) {
    msg->flags = msg->flags | 4;
    zmsg_read_bytes(msg,uVar5,0xe,&ccm_nonce.security_control);
    sVar4 = stack0xffffffc0;
    uVar6 = secur_scf_get_aux_hdr_size(ccm_nonce.security_control);
    if ((sVar4 & 0x20) == SECUR_SCF_DATA_KEY) {
      puVar11 = (undefined4 *)nwk_get_extended_address();
      uVar1 = *puVar11;
      uVar2 = puVar11[1];
      aux_hdr.frame_cntr._0_1_ = (char)*(undefined3 *)puVar11;
      aux_hdr.frame_cntr._1_1_ = (char)((uint)uVar1 >> 8);
      aux_hdr.src_address.field_0._1_1_ = (char)((uint)uVar2 >> 8);
      aux_hdr.src_address.field_0._0_1_ = (char)*(undefined3 *)(puVar11 + 1);
      aux_hdr.frame_cntr._2_1_ = (char)((uint)uVar1 >> 0x10);
      aux_hdr.frame_cntr._3_1_ = (char)((uint)uVar1 >> 0x18);
      aux_hdr.src_address.field_0._2_1_ = (char)((uint)uVar2 >> 0x10);
      aux_hdr.src_address.field_0.u8[3] = (uint8_t)((uint)uVar2 >> 0x18);
    }
    aux_hdr.src_address.field_0.u8[7] = (byte)stack0xffffffc0 | (byte)uVar9 & 7;
    stack0xffffffc0 = CONCAT31(uStack_3f,aux_hdr.src_address.field_0.u8[7]);
    uVar13 = CONCAT31(extraout_var,uVar6) + uVar5 & 0xffff;
    zmsg_write_bytes(msg,uVar5,1,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 7));
    zmsg_set_offset(msg,uVar13);
    zmsg_get_footer(msg,&stack0xffffffac,4);
    zmsg_remove_footer(msg,4);
    if (paStack_54 != (aps_device_key_pair_t *)0x0) {
      aps_secur_key_pair_get_key
                (paStack_54,aux_hdr.src_address.field_0.u8 + 7,stack0xffffffc0 & SECUR_SCF_KL_KEY);
      _Var7 = secur_is_key_valid(aux_hdr.src_address.field_0.u8 + 7);
      if (CONCAT31(extraout_var_00,_Var7) != 0) {
        key_pair = (aps_device_key_pair_t *)(aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8);
        ccm_nonce.source_address.field_0.u64._0_4_ =
             (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
        ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | stack0xffffffc0 >> 8;
        ccm_nonce.frame_counter._0_1_ = ccm_nonce.security_control;
        eVar12 = secur_unsecure_msg(uVar9,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 7),
                                    &key_pair,msg,uVar13);
        goto _L0;
      }
    }
    eVar12 = 0x13;
  }
_L0:
  secur_key_clear(aux_hdr.src_address.field_0.u8 + 7);
  return eVar12;
}


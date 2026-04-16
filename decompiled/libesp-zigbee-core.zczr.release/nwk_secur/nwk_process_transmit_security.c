/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_process_transmit_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_process_transmit_security(uint8_t iface_id,zmsg_t *msg)

{
  undefined2 uVar1;
  undefined1 uVar2;
  uint16_t uVar3;
  uint uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  _Bool _Var7;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar8;
  int iVar9;
  uint8_t *key;
  undefined3 extraout_var_01;
  undefined4 uVar10;
  uint16_t uStack_46;
  uint uStack_44;
  uint16_t nwk_fcf;
  dataset_nib_cntr_t nib_cntr;
  secur_ccm_nonce_t ccm_nonce;
  undefined1 auStack_2f [2];
  undefined1 uStack_2d;
  secur_aux_hdr_t aux_hdr;
  
  uVar5 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,2,&uStack_46);
  uVar3 = uStack_46;
  uVar6 = nwk_fcf_get_hdr_size(uStack_46);
  uVar4 = CONCAT31(extraout_var_00,uVar6);
  if ((uVar3 & 0x400) != 0) {
    iVar8 = zmsg_read_bytes(msg,uVar4,2,&ccm_nonce.security_control);
    uVar4 = (stack0xffffffd0 & 0xff) * 2 + uVar4 + iVar8 & 0xffff;
  }
  if ((uStack_46 & 0x200) != 0) {
    msg->flags = msg->flags | 2;
    if (CONCAT31(extraout_var,uVar5) == 0) {
      return 0x13;
    }
    stack0xffffffd0 = CONCAT31(_auStack_2f,uVar5) | 0x28;
    iVar8 = core_globals_get();
    if ((*(uint *)(iVar8 + 0x9fc) & 0x3ff) == 0) {
      iVar9 = core_globals_get();
      uStack_44 = *(int *)(iVar9 + 0x9fc) + 0x400;
      nib_cntr.counter = 0;
      ds_internal_save_entry(8,&stack0xffffffbc,&nib_cntr,4);
    }
    iVar9 = *(int *)(iVar8 + 0x9fc);
    *(int *)(iVar8 + 0x9fc) = iVar9 + 1;
    stack0xffffffd0 =
         CONCAT13((char)((uint)iVar9 >> 0x10),
                  CONCAT12((char)((uint)iVar9 >> 8),CONCAT11((char)iVar9,ccm_nonce.security_control)
                          ));
    iVar8 = core_globals_get();
    uVar10 = *(undefined4 *)(iVar8 + 0x9e8);
    uVar1 = *(undefined2 *)(iVar8 + 0x9ec);
    aux_hdr.frame_cntr._0_1_ = (char)*(undefined2 *)(iVar8 + 0x9e6);
    aux_hdr.scf = (uint8_t)((uint)iVar9 >> 0x18);
    aux_hdr.frame_cntr._1_1_ = (char)((ushort)*(undefined2 *)(iVar8 + 0x9e6) >> 8);
    aux_hdr.src_address.field_0.u64._0_3_ = CONCAT12((char)uVar1,(short)((uint)uVar10 >> 0x10));
    aux_hdr.frame_cntr._2_1_ = (char)uVar10;
    aux_hdr.frame_cntr._3_1_ = (char)((uint)uVar10 >> 8);
    iVar8 = core_globals_get();
    uVar6 = *(uint8_t *)(iVar8 + 0xa22);
    zmsg_write_bytes(msg,uVar4,0xe,&ccm_nonce.security_control);
    if (((uint)(uint3)aux_hdr._0_3_ << 0x18 | stack0xffffffd0 >> 8) == 0xffffffff) {
      return 0x2cc;
    }
    key = nwk_secur_get_key_by_seq(uVar6);
    _Var7 = secur_is_key_valid(key);
    if (CONCAT31(extraout_var_01,_Var7) == 0) {
      return 0x2cd;
    }
    nib_cntr.counter = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
    ccm_nonce.source_address.field_0.u64._0_4_ =
         CONCAT13((char)((ushort)uVar1 >> 8),aux_hdr.src_address.field_0.u64._0_3_);
    ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8;
    ccm_nonce.frame_counter._0_1_ = ccm_nonce.security_control;
    iVar8 = secur_secure_msg(CONCAT31(extraout_var,uVar5),key,&nib_cntr,msg,uVar4 + 0xe & 0xffff);
    if (iVar8 != 0) {
      return 0x2ce;
    }
    uVar2 = (undefined1)stack0xffffffd0;
    stack0xffffffd0 = stack0xffffffd0 & 0xfffffff8;
    uStack_44 = CONCAT31(uStack_44._1_3_,uVar2) & 0xfffffff8;
    zmsg_write_bytes(msg,uVar4,1,&stack0xffffffbc);
  }
  return 0;
}


/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_process_transmit_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_process_transmit_security(uint8_t iface_id,zmsg_t *msg)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  uint16_t uVar4;
  uint uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  _Bool _Var8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar9;
  int iVar10;
  uint8_t *key;
  undefined3 extraout_var_01;
  uint16_t uStack_46;
  uint uStack_44;
  uint16_t nwk_fcf;
  dataset_nib_cntr_t nib_cntr;
  secur_ccm_nonce_t ccm_nonce;
  undefined1 auStack_2f [2];
  undefined1 uStack_2d;
  secur_aux_hdr_t aux_hdr;
  
  uVar6 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,2,&uStack_46);
  uVar4 = uStack_46;
  uVar7 = nwk_fcf_get_hdr_size(uStack_46);
  uVar5 = CONCAT31(extraout_var_00,uVar7);
  if ((uVar4 & 0x400) != 0) {
    iVar9 = zmsg_read_bytes(msg,uVar5,2,&ccm_nonce.security_control);
    uVar5 = (stack0xffffffd0 & 0xff) * 2 + uVar5 + iVar9 & 0xffff;
  }
  if ((uStack_46 & 0x200) != 0) {
    uVar1 = msg->flags;
    msg->flags = uVar1 | 2;
    if (CONCAT31(extraout_var,uVar6) == 0) {
      return 0x13;
    }
    if ((uVar1 & 8) == 0) {
      iVar9 = core_globals_get();
      aux_hdr.src_address.field_0.u8[4] = *(uint8_t *)(iVar9 + 0xa22);
    }
    else {
      zmsg_read_bytes(msg,uVar5,0xe,&ccm_nonce.security_control);
    }
    stack0xffffffd0 = CONCAT31(_auStack_2f,uVar6) | 0x28;
    iVar9 = core_globals_get();
    if ((*(uint *)(iVar9 + 0x9fc) & 0x3ff) == 0) {
      iVar10 = core_globals_get();
      uStack_44 = *(int *)(iVar10 + 0x9fc) + 0x400;
      nib_cntr.counter = 0;
      ds_internal_save_entry(8,&stack0xffffffbc,&nib_cntr,4);
    }
    iVar10 = *(int *)(iVar9 + 0x9fc);
    *(int *)(iVar9 + 0x9fc) = iVar10 + 1;
    stack0xffffffd0 =
         CONCAT13((char)((uint)iVar10 >> 0x10),
                  CONCAT12((char)((uint)iVar10 >> 8),
                           CONCAT11((char)iVar10,ccm_nonce.security_control)));
    iVar9 = core_globals_get();
    uVar2 = *(undefined2 *)(iVar9 + 0x9ec);
    aux_hdr.frame_cntr._0_1_ = (char)*(undefined2 *)(iVar9 + 0x9e6);
    aux_hdr.scf = (uint8_t)((uint)iVar10 >> 0x18);
    aux_hdr.frame_cntr._1_1_ = (char)((ushort)*(undefined2 *)(iVar9 + 0x9e6) >> 8);
    aux_hdr.frame_cntr._2_1_ = (char)*(undefined4 *)(iVar9 + 0x9e8);
    aux_hdr._4_3_ = (undefined3)((uint)*(undefined4 *)(iVar9 + 0x9e8) >> 8);
    aux_hdr.src_address.field_0.u8[2] = (char)uVar2;
    zmsg_write_bytes(msg,uVar5,0xe,&ccm_nonce.security_control);
    if (((uint)(uint3)aux_hdr._0_3_ << 0x18 | stack0xffffffd0 >> 8) == 0xffffffff) {
      return 0x2cc;
    }
    key = nwk_secur_get_key_by_seq(aux_hdr.src_address.field_0.u8[4]);
    _Var8 = secur_is_key_valid(key);
    if (CONCAT31(extraout_var_01,_Var8) == 0) {
      return 0x2cd;
    }
    nib_cntr.counter = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
    ccm_nonce.source_address.field_0.u64._0_4_ =
         (uint)(byte)((ushort)uVar2 >> 8) << 0x18 | (uint)aux_hdr._4_4_ >> 8;
    ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8;
    ccm_nonce.frame_counter._0_1_ = ccm_nonce.security_control;
    iVar9 = secur_secure_msg(CONCAT31(extraout_var,uVar6),key,&nib_cntr,msg,uVar5 + 0xe & 0xffff);
    if (iVar9 != 0) {
      return 0x2ce;
    }
    uVar3 = (undefined1)stack0xffffffd0;
    stack0xffffffd0 = stack0xffffffd0 & 0xfffffff8;
    uStack_44 = CONCAT31(uStack_44._1_3_,uVar3) & 0xfffffff8;
    zmsg_write_bytes(msg,uVar5,1,&stack0xffffffbc);
  }
  return 0;
}


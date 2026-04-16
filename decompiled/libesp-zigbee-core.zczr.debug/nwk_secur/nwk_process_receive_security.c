/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_process_receive_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_process_receive_security(uint8_t iface_id,zmsg_t *msg)

{
  undefined2 uVar1;
  byte bVar2;
  uint8_t uVar3;
  _Bool _Var4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint8_t *key;
  undefined3 extraout_var_01;
  int iVar5;
  uint uVar6;
  byte abStack_44 [4];
  nwk_sroute_field_t sroute;
  secur_ccm_nonce_t ccm_nonce;
  undefined3 uStack_2f;
  secur_aux_hdr_t aux_hdr;
  uint16_t nwk_fcf;
  
  bVar2 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,2,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 5));
  uVar1 = aux_hdr.src_address.field_0.u64._5_2_;
  uVar3 = nwk_fcf_get_hdr_size(aux_hdr.src_address.field_0.u64._5_2_);
  uVar6 = CONCAT31(extraout_var_00,uVar3);
  if ((uVar1 & 0x400) != 0) {
    iVar5 = zmsg_read_bytes(msg,uVar6,2,abStack_44);
    uVar6 = (uint)abStack_44[0] * 2 + (uVar6 + iVar5 & 0xffff) & 0xffff;
  }
  if ((aux_hdr.src_address.field_0.u64._5_2_ & 0x200) != 0) {
    msg->flags = msg->flags | 2;
    if (CONCAT31(extraout_var,bVar2) == 0) {
      return 0x13;
    }
    zmsg_read_bytes(msg,uVar6,0xe,&ccm_nonce.security_control);
    if (ccm_nonce.security_control != '(') {
      return 0x13;
    }
    if ((aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8) == 0xffffffff) {
      return 0x13;
    }
    key = nwk_secur_get_key_by_seq(aux_hdr.src_address.field_0.u8[4]);
    _Var4 = secur_is_key_valid(key);
    if (CONCAT31(extraout_var_01,_Var4) == 0) {
      return 0x2cd;
    }
    stack0xffffffd0 = CONCAT31(uStack_2f,(byte)stack0xffffffd0 | bVar2 & 7);
    zmsg_write_bytes(msg,uVar6,1,&ccm_nonce.security_control);
    uVar6 = uVar6 + 0xe & 0xffff;
    _sroute = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
    ccm_nonce.source_address.field_0.u64._0_4_ =
         (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
    ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8;
    ccm_nonce.frame_counter._0_1_ = ccm_nonce.security_control;
    iVar5 = secur_unsecure_msg(CONCAT31(extraout_var,bVar2),key,&sroute,msg,uVar6);
    if (iVar5 != 0) {
      return 0x2ce;
    }
  }
  zmsg_set_offset(msg,uVar6);
  return 0;
}


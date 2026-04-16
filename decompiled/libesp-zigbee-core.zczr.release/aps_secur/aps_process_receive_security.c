/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_process_receive_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_process_receive_security(ezb_shortaddr_t src_shortaddr,zmsg_t *msg)

{
  byte bVar1;
  uint uVar2;
  secur_scf_key_id_t sVar3;
  uint8_t uVar4;
  _Bool _Var5;
  uint16_t uVar6;
  undefined2 in_register_0000202a;
  int iVar7;
  int iVar8;
  undefined3 extraout_var;
  aps_device_key_pair_t *key_pair_00;
  undefined3 extraout_var_00;
  undefined4 uVar9;
  uint uVar10;
  byte bStack_5d;
  aps_device_key_pair_t *paStack_5c;
  uint8_t aps_fcf;
  aps_device_key_pair_t *key_pair;
  ezb_extaddr_t src_addr;
  secur_ccm_nonce_t ccm_nonce;
  undefined3 uStack_3f;
  secur_aux_hdr_t aux_hdr;
  uint8_t ext_fcf;
  
  iVar7 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,1,&bStack_5d);
  bVar1 = bStack_5d;
  uVar6 = aps_fcf_get_hdr_size(bStack_5d);
  uVar10 = (uint)uVar6;
  if ((char)bVar1 < '\0') {
    iVar8 = zmsg_read_bytes(msg,uVar10,1,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 7));
    uVar10 = ((aux_hdr.src_address.field_0.u8[7] & 3) - 1 < 2) + uVar10 + iVar8 & 0xffff;
  }
  zmsg_set_offset(msg,uVar10);
  if ((bStack_5d & 0x20) == 0) {
    return 0;
  }
  msg->flags = msg->flags | 4;
  if (iVar7 == 0) {
    return 0x13;
  }
  zmsg_read_bytes(msg,uVar10,0xe,&ccm_nonce.security_control);
  uVar2 = stack0xffffffc0;
  uVar4 = secur_scf_get_aux_hdr_size(ccm_nonce.security_control);
  if ((aux_hdr._0_4_ << 0x18 | stack0xffffffc0 >> 8) == 0xffffffff) {
    return 0x13;
  }
  if ((uVar2 & 0x20) == 0) {
    iVar8 = nwk_address_extended_by_short(CONCAT22(in_register_0000202a,src_shortaddr),&key_pair);
    if (iVar8 != 0) {
      return iVar8;
    }
    aux_hdr.frame_cntr._0_1_ = (char)key_pair;
    aux_hdr.frame_cntr._1_1_ = (char)((uint)key_pair >> 8);
    aux_hdr.frame_cntr._2_1_ = (char)((uint)key_pair >> 0x10);
    aux_hdr.src_address.field_0.u8[0] = (char)src_addr.field_0.u64._0_4_;
    aux_hdr.frame_cntr._3_1_ = (char)((uint)key_pair >> 0x18);
    aux_hdr.src_address.field_0.u8[1] = (char)((uint)src_addr.field_0._0_4_ >> 8);
    aux_hdr.src_address.field_0.u8[2] = (char)((uint)src_addr.field_0._0_4_ >> 0x10);
    aux_hdr.src_address.field_0.u8[3] = (uint8_t)((uint)src_addr.field_0._0_4_ >> 0x18);
  }
  else {
    key_pair = (aps_device_key_pair_t *)(aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8);
    src_addr.field_0.u64._0_4_ =
         (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
  }
  stack0xffffffc0 = CONCAT31(uStack_3f,(byte)stack0xffffffc0 | (byte)iVar7 & 7);
  zmsg_write_bytes(msg,uVar10,1,&ccm_nonce.security_control);
  zmsg_set_offset(msg,CONCAT31(extraout_var,uVar4) + uVar10 & 0xffff);
  key_pair_00 = aps_secur_get_key_pair_by_addr((ezb_extaddr_t *)&key_pair);
  if (key_pair_00 == (aps_device_key_pair_t *)0x0) {
    return 0x13;
  }
  uVar10 = aux_hdr._0_4_ << 0x18 | stack0xffffffc0 >> 8;
  paStack_5c = key_pair_00;
  aps_secur_key_pair_get_key
            (key_pair_00,aux_hdr.src_address.field_0.u8 + 7,stack0xffffffc0 & SECUR_SCF_KL_KEY);
  _Var5 = secur_is_key_valid(aux_hdr.src_address.field_0.u8 + 7);
  sVar3 = stack0xffffffc0;
  if (CONCAT31(extraout_var_00,_Var5) != 0) {
    src_addr.field_0.u64._4_4_ = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
    ccm_nonce.source_address.field_0.u64._0_4_ =
         (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
    ccm_nonce.frame_counter._0_1_ = ccm_nonce.security_control;
    ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | stack0xffffffc0 >> 8;
    uVar9 = zmsg_get_offset(msg);
    iVar7 = secur_unsecure_msg(sVar3 & 7,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 7),
                               (undefined1 *)((int)&src_addr.field_0 + 4),msg,uVar9);
    if (iVar7 != 0) goto _L0;
    if ((key_pair_00->incoming_frame_cntr == 0xffffffff) ||
       (key_pair_00->incoming_frame_cntr < uVar10)) {
      key_pair_00->incoming_frame_cntr = uVar10;
      goto _L0;
    }
  }
  iVar7 = 0x13;
_L0:
  secur_key_clear(aux_hdr.src_address.field_0.u8 + 7);
  if (iVar7 == 0) {
    zmsg_add_footer(msg,&stack0xffffffa4);
    return 0;
  }
  return iVar7;
}


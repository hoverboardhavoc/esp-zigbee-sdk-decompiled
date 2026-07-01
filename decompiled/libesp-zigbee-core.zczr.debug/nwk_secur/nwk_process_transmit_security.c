/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_process_transmit_security
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
  ezb_err_t eVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  _Bool _Var6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint32_t uVar7;
  int iVar8;
  uint8_t *key;
  undefined3 extraout_var_01;
  uint uVar9;
  byte abStack_44 [4];
  nwk_sroute_field_t sroute;
  secur_ccm_nonce_t ccm_nonce;
  undefined1 auStack_2f [2];
  undefined1 uStack_2d;
  secur_aux_hdr_t aux_hdr;
  uint16_t nwk_fcf;
  
  uVar4 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,2,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 5));
  uVar2 = aux_hdr.src_address.field_0.u64._5_2_;
  uVar5 = nwk_fcf_get_hdr_size(aux_hdr.src_address.field_0.u64._5_2_);
  uVar9 = CONCAT31(extraout_var_00,uVar5);
  if ((uVar2 & 0x400) != 0) {
    iVar8 = zmsg_read_bytes(msg,uVar9,2,abStack_44);
    uVar9 = (uint)abStack_44[0] * 2 + (uVar9 + iVar8 & 0xffff) & 0xffff;
  }
  if ((aux_hdr.src_address.field_0.u64._5_2_ & 0x200) == 0) {
    eVar3 = 0;
  }
  else {
    uVar1 = msg->flags;
    msg->flags = uVar1 | 2;
    if (CONCAT31(extraout_var,uVar4) == 0) {
      eVar3 = 0x13;
    }
    else {
      if ((uVar1 & 8) == 0) {
        iVar8 = core_globals_get();
        aux_hdr.src_address.field_0.u8[4] = *(uint8_t *)(iVar8 + 0xa22);
      }
      else {
        zmsg_read_bytes(msg,uVar9,0xe,&ccm_nonce.security_control);
      }
      stack0xffffffd0 = CONCAT31(_auStack_2f,uVar4) | 0x28;
      uVar7 = nwk_secur_inc_frame_cntr();
      stack0xffffffd0 =
           CONCAT13((char)(uVar7 >> 0x10),
                    CONCAT12((char)(uVar7 >> 8),CONCAT11((char)uVar7,ccm_nonce.security_control)));
      aux_hdr.scf = (uint8_t)(uVar7 >> 0x18);
      iVar8 = core_globals_get();
      aux_hdr.frame_cntr._0_1_ = (char)*(undefined2 *)(iVar8 + 0x9e6);
      aux_hdr.frame_cntr._1_1_ = (char)((ushort)*(undefined2 *)(iVar8 + 0x9e6) >> 8);
      aux_hdr.frame_cntr._2_1_ = (char)*(undefined4 *)(iVar8 + 0x9e8);
      aux_hdr._4_3_ = (undefined3)((uint)*(undefined4 *)(iVar8 + 0x9e8) >> 8);
      aux_hdr.src_address.field_0.u8[2] = (char)*(undefined2 *)(iVar8 + 0x9ec);
      aux_hdr.src_address.field_0.u8[3] = (uint8_t)((ushort)*(undefined2 *)(iVar8 + 0x9ec) >> 8);
      zmsg_write_bytes(msg,uVar9,0xe,&ccm_nonce.security_control);
      if ((aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8) == 0xffffffff) {
        eVar3 = 0x2cc;
      }
      else {
        key = nwk_secur_get_key_by_seq(aux_hdr.src_address.field_0.u8[4]);
        _Var6 = secur_is_key_valid(key);
        if (CONCAT31(extraout_var_01,_Var6) == 0) {
          eVar3 = 0x2cd;
        }
        else {
          _sroute = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
          ccm_nonce.source_address.field_0.u64._0_4_ =
               (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
          ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8;
          ccm_nonce.frame_counter._0_1_ = ccm_nonce.security_control;
          iVar8 = secur_secure_msg(CONCAT31(extraout_var,uVar4),key,&sroute,msg,uVar9 + 0xe & 0xffff
                                  );
          if (iVar8 == 0) {
            abStack_44[0] = (byte)stack0xffffffd0 & 0xf8;
            stack0xffffffd0 = stack0xffffffd0 & 0xfffffff8;
            zmsg_write_bytes(msg,uVar9,1,abStack_44);
            eVar3 = 0;
          }
          else {
            eVar3 = 0x2ce;
          }
        }
      }
    }
  }
  return eVar3;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_process_transmit_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_process_transmit_security(uint8_t iface_id,zmsg_t *msg)

{
  undefined2 uVar1;
  ezb_err_t eVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  _Bool _Var5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint32_t uVar6;
  int iVar7;
  uint8_t *key;
  undefined3 extraout_var_01;
  uint uVar8;
  byte abStack_44 [4];
  nwk_sroute_field_t sroute;
  secur_ccm_nonce_t ccm_nonce;
  undefined1 auStack_2f [2];
  undefined1 uStack_2d;
  secur_aux_hdr_t aux_hdr;
  uint16_t nwk_fcf;
  
  uVar3 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,2,(undefined1 *)((int)&aux_hdr.src_address.field_0 + 5));
  uVar1 = aux_hdr.src_address.field_0.u64._5_2_;
  uVar4 = nwk_fcf_get_hdr_size(aux_hdr.src_address.field_0.u64._5_2_);
  uVar8 = CONCAT31(extraout_var_00,uVar4);
  if ((uVar1 & 0x400) != 0) {
    iVar7 = zmsg_read_bytes(msg,uVar8,2,abStack_44);
    uVar8 = (uint)abStack_44[0] * 2 + (uVar8 + iVar7 & 0xffff) & 0xffff;
  }
  if ((aux_hdr.src_address.field_0.u64._5_2_ & 0x200) == 0) {
    eVar2 = 0;
  }
  else {
    msg->flags = msg->flags | 2;
    if (CONCAT31(extraout_var,uVar3) == 0) {
      eVar2 = 0x13;
    }
    else {
      stack0xffffffd0 = CONCAT31(_auStack_2f,uVar3) | 0x28;
      uVar6 = nwk_secur_inc_frame_cntr();
      stack0xffffffd0 =
           CONCAT13((char)(uVar6 >> 0x10),
                    CONCAT12((char)(uVar6 >> 8),CONCAT11((char)uVar6,ccm_nonce.security_control)));
      aux_hdr.scf = (uint8_t)(uVar6 >> 0x18);
      iVar7 = core_globals_get();
      aux_hdr.frame_cntr._0_1_ = (char)*(undefined2 *)(iVar7 + 0x9e6);
      aux_hdr.frame_cntr._1_1_ = (char)((ushort)*(undefined2 *)(iVar7 + 0x9e6) >> 8);
      aux_hdr.frame_cntr._2_1_ = (char)*(undefined4 *)(iVar7 + 0x9e8);
      aux_hdr._4_3_ = (undefined3)((uint)*(undefined4 *)(iVar7 + 0x9e8) >> 8);
      aux_hdr.src_address.field_0.u8[2] = (char)*(undefined2 *)(iVar7 + 0x9ec);
      aux_hdr.src_address.field_0.u8[3] = (uint8_t)((ushort)*(undefined2 *)(iVar7 + 0x9ec) >> 8);
      iVar7 = core_globals_get();
      aux_hdr.src_address.field_0.u8[4] = *(uint8_t *)(iVar7 + 0xa22);
      zmsg_write_bytes(msg,uVar8,0xe,&ccm_nonce.security_control);
      if ((aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8) == 0xffffffff) {
        eVar2 = 0x2cc;
      }
      else {
        key = nwk_secur_get_key_by_seq(aux_hdr.src_address.field_0.u8[4]);
        _Var5 = secur_is_key_valid(key);
        if (CONCAT31(extraout_var_01,_Var5) == 0) {
          eVar2 = 0x2cd;
        }
        else {
          _sroute = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
          ccm_nonce.source_address.field_0.u64._0_4_ =
               (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
          ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8;
          ccm_nonce.frame_counter._0_1_ = ccm_nonce.security_control;
          iVar7 = secur_secure_msg(CONCAT31(extraout_var,uVar3),key,&sroute,msg,uVar8 + 0xe & 0xffff
                                  );
          if (iVar7 == 0) {
            abStack_44[0] = (byte)stack0xffffffd0 & 0xf8;
            stack0xffffffd0 = stack0xffffffd0 & 0xfffffff8;
            zmsg_write_bytes(msg,uVar8,1,abStack_44);
            eVar2 = 0;
          }
          else {
            eVar2 = 0x2ce;
          }
        }
      }
    }
  }
  return eVar2;
}


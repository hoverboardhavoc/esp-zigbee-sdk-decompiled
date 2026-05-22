/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_process_receive_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_process_receive_security(uint8_t iface_id,zmsg_t *msg)

{
  uint16_t uVar1;
  uint uVar2;
  byte bVar3;
  uint8_t uVar4;
  _Bool _Var5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar6;
  uint8_t *key;
  undefined3 extraout_var_01;
  int iVar7;
  ezb_err_t eVar8;
  uint16_t uStack_42;
  uint uStack_40;
  uint16_t nwk_fcf;
  secur_ccm_nonce_t ccm_nonce;
  undefined3 uStack_2f;
  secur_aux_hdr_t aux_hdr;
  
  bVar3 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,2,&uStack_42);
  uVar1 = uStack_42;
  uVar4 = nwk_fcf_get_hdr_size(uStack_42);
  uVar2 = CONCAT31(extraout_var_00,uVar4);
  if ((uVar1 & 0x400) != 0) {
    iVar6 = zmsg_read_bytes(msg,uVar2,2,&ccm_nonce.security_control);
    uVar2 = (stack0xffffffd0 & 0xff) * 2 + uVar2 + iVar6 & 0xffff;
  }
  if ((uStack_42 & 0x200) == 0) {
_L0:
    zmsg_set_offset(msg,uVar2);
    eVar8 = 0;
  }
  else {
    msg->flags = msg->flags | 2;
    if (CONCAT31(extraout_var,bVar3) != 0) {
      zmsg_read_bytes(msg,uVar2,0xe,&ccm_nonce.security_control);
      if ((ccm_nonce.security_control == '(') &&
         ((aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8) != 0xffffffff)) {
        key = nwk_secur_get_key_by_seq(aux_hdr.src_address.field_0.u8[4]);
        _Var5 = secur_is_key_valid(key);
        if (CONCAT31(extraout_var_01,_Var5) == 0) {
          return 0x2cd;
        }
        iVar6 = nwk_neighbor_table_get_by_extended(&aux_hdr.frame_cntr);
        if (((iVar6 == 0) || (*(uint8_t *)(iVar6 + 7) != aux_hdr.src_address.field_0.u8[4])) ||
           (*(uint *)(iVar6 + 8) <= (aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8))) {
          stack0xffffffd0 = CONCAT31(uStack_2f,bVar3 | (byte)stack0xffffffd0);
          zmsg_write_bytes(msg,uVar2,1,&ccm_nonce.security_control);
          uStack_40 = aux_hdr._4_4_ << 0x18 | (uint)aux_hdr._0_4_ >> 8;
          ccm_nonce.source_address.field_0.u64._0_4_ =
               (uint)aux_hdr.src_address.field_0.u8[3] << 0x18 | (uint)aux_hdr._4_4_ >> 8;
          uVar2 = uVar2 + 0xe & 0xffff;
          ccm_nonce.source_address.field_0.u64._4_4_ = aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8;
          ccm_nonce.frame_counter._0_1_ = ccm_nonce.security_control;
          iVar7 = secur_unsecure_msg(CONCAT31(extraout_var,bVar3),key,&stack0xffffffc0,msg,uVar2);
          if (iVar7 != 0) {
            return 0x2ce;
          }
          if (iVar6 != 0) {
            *(uint *)(iVar6 + 8) = (aux_hdr._0_4_ << 0x18 | stack0xffffffd0 >> 8) + 1;
            *(uint8_t *)(iVar6 + 7) = aux_hdr.src_address.field_0.u8[4];
          }
          goto _L0;
        }
      }
    }
    eVar8 = 0x13;
  }
  return eVar8;
}


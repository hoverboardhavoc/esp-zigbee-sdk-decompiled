/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
  aps_device_key_pair_t *paVar3;
  byte bVar4;
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
  aps_device_key_pair_t *apaStack_64 [4];
  byte bStack_52;
  byte bStack_51;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined1 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  byte bStack_34;
  byte abStack_30 [28];
  
  apaStack_64[0] = aps_secur_get_key_pair_by_addr(dst_addr);
  iVar9 = nwk_secur_get_seclevel();
  zmsg_read_bytes(msg,0,1,&bStack_52);
  bVar4 = bStack_52;
  uVar8 = aps_fcf_get_hdr_size(bStack_52);
  uVar5 = (uint)uVar8;
  if ((char)bVar4 < '\0') {
    iVar10 = zmsg_read_bytes(msg,uVar5,1,abStack_30);
    uVar5 = ((abStack_30[0] & 3) - 1 < 2) + uVar5 + iVar10 & 0xffff;
  }
  iVar10 = 0;
  if ((bStack_52 & 0x20) != 0) {
    if ((iVar9 != 0) && (apaStack_64[0] != (aps_device_key_pair_t *)0x0)) {
      zmsg_read_bytes(msg,uVar5,0xe,&uStack_40);
      paVar3 = apaStack_64[0];
      uStack_40 = CONCAT31(uStack_40._1_3_,(byte)uStack_40 | (byte)iVar9 & 7);
      if ((apaStack_64[0]->outgoing_frame_cntr & 0x3ff) == 0) {
        aps_secur_store_key_pair(apaStack_64[0]);
      }
      uVar12 = paVar3->outgoing_frame_cntr;
      paVar3->outgoing_frame_cntr = uVar12 + 1;
      uStack_40 = CONCAT13((char)(uVar12 >> 0x10),
                           CONCAT12((char)(uVar12 >> 8),CONCAT11((char)uVar12,(byte)uStack_40)));
      uStack_3c = CONCAT31(uStack_3c._1_3_,(char)(uVar12 >> 0x18));
      puVar11 = (undefined4 *)nwk_get_extended_address();
      uVar1 = *puVar11;
      uVar2 = puVar11[1];
      bStack_34 = (byte)((uint)uVar2 >> 0x18);
      uStack_3c = CONCAT13((char)((uint)uVar1 >> 0x10),
                           CONCAT12((char)((uint)uVar1 >> 8),
                                    CONCAT11((char)*(undefined3 *)puVar11,(undefined1)uStack_3c)));
      uStack_38 = CONCAT22((short)((uint)uVar2 >> 8),
                           CONCAT11((char)*(undefined3 *)(puVar11 + 1),(char)((uint)uVar1 >> 0x18)))
      ;
      uVar6 = secur_scf_get_aux_hdr_size((byte)uStack_40);
      zmsg_write_bytes(msg,uVar5,CONCAT31(extraout_var,uVar6),&uStack_40);
      if ((uStack_3c << 0x18 | uStack_40 >> 8) != 0xffffffff) {
        aps_secur_key_pair_get_key(apaStack_64[0],abStack_30,uStack_40 & SECUR_SCF_KL_KEY);
        _Var7 = secur_is_key_valid(abStack_30);
        if (CONCAT31(extraout_var_00,_Var7) != 0) {
          uStack_50 = uStack_38 << 0x18 | uStack_3c >> 8;
          uStack_4c = (uint)bStack_34 << 0x18 | uStack_38 >> 8;
          uStack_48 = uStack_3c << 0x18 | uStack_40 >> 8;
          uStack_44 = (byte)uStack_40;
          iVar10 = secur_secure_msg(iVar9,abStack_30,&uStack_50,msg,
                                    CONCAT31(extraout_var,uVar6) + uVar5 & 0xffff);
          if (iVar10 == 0) {
            msg->flags = msg->flags | 4;
            zmsg_add_footer(msg,apaStack_64,4);
            bStack_51 = (byte)uStack_40 & 0xf8;
            uStack_40 = uStack_40 & 0xfffffff8;
            zmsg_write_bytes(msg,uVar5,1,&bStack_51);
          }
          goto _L0;
        }
      }
    }
    iVar10 = 0x13;
  }
_L0:
  secur_key_clear(abStack_30);
  return iVar10;
}


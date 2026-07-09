/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_process_transmit_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_process_transmit_security(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int aiStack_64 [4];
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
  
  aiStack_64[0] = aps_secur_get_key_pair_by_addr();
  iVar4 = nwk_secur_get_seclevel();
  zmsg_read_bytes(param_1,0,1,&bStack_52);
  bVar3 = bStack_52;
  uVar5 = aps_fcf_get_hdr_size(bStack_52);
  if ((char)bVar3 < '\0') {
    iVar6 = zmsg_read_bytes(param_1,uVar5,1,abStack_30);
    uVar5 = ((abStack_30[0] & 3) - 1 < 2) + uVar5 + iVar6 & 0xffff;
  }
  iVar6 = 0;
  if ((bStack_52 & 0x20) != 0) {
    if ((iVar4 != 0) && (aiStack_64[0] != 0)) {
      zmsg_read_bytes(param_1,uVar5,0xe,&uStack_40);
      iVar6 = aiStack_64[0];
      uStack_40 = CONCAT31(uStack_40._1_3_,(byte)uStack_40 | (byte)iVar4 & 7);
      if ((*(uint *)(aiStack_64[0] + 8) & 0x3ff) == 0) {
        aps_secur_store_key_pair(aiStack_64[0]);
      }
      iVar8 = *(int *)(iVar6 + 8);
      *(int *)(iVar6 + 8) = iVar8 + 1;
      uStack_40 = CONCAT13((char)((uint)iVar8 >> 0x10),
                           CONCAT12((char)((uint)iVar8 >> 8),CONCAT11((char)iVar8,(byte)uStack_40)))
      ;
      uStack_3c = CONCAT31(uStack_3c._1_3_,(char)((uint)iVar8 >> 0x18));
      puVar7 = (undefined4 *)nwk_get_extended_address();
      uVar1 = *puVar7;
      uVar2 = puVar7[1];
      bStack_34 = (byte)((uint)uVar2 >> 0x18);
      uStack_3c = CONCAT13((char)((uint)uVar1 >> 0x10),
                           CONCAT12((char)((uint)uVar1 >> 8),
                                    CONCAT11((char)*(undefined3 *)puVar7,(undefined1)uStack_3c)));
      uStack_38 = CONCAT22((short)((uint)uVar2 >> 8),
                           CONCAT11((char)*(undefined3 *)(puVar7 + 1),(char)((uint)uVar1 >> 0x18)));
      iVar6 = secur_scf_get_aux_hdr_size(uStack_40 & 0xff);
      zmsg_write_bytes(param_1,uVar5,iVar6,&uStack_40);
      if ((uStack_3c << 0x18 | uStack_40 >> 8) != 0xffffffff) {
        aps_secur_key_pair_get_key(aiStack_64[0],abStack_30,uStack_40 & 0x18);
        iVar8 = secur_is_key_valid(abStack_30);
        if (iVar8 != 0) {
          uStack_50 = uStack_38 << 0x18 | uStack_3c >> 8;
          uStack_4c = (uint)bStack_34 << 0x18 | uStack_38 >> 8;
          uStack_48 = uStack_3c << 0x18 | uStack_40 >> 8;
          uStack_44 = (byte)uStack_40;
          iVar6 = secur_secure_msg(iVar4,abStack_30,&uStack_50,param_1,iVar6 + uVar5 & 0xffff);
          if (iVar6 == 0) {
            *(ushort *)(param_1 + 0x16) = *(ushort *)(param_1 + 0x16) | 4;
            zmsg_add_footer(param_1,aiStack_64,4);
            bStack_51 = (byte)uStack_40 & 0xf8;
            uStack_40 = uStack_40 & 0xfffffff8;
            zmsg_write_bytes(param_1,uVar5,1,&bStack_51);
          }
          goto _L0;
        }
      }
    }
    iVar6 = 0x13;
  }
_L0:
  secur_key_clear(abStack_30);
  return iVar6;
}


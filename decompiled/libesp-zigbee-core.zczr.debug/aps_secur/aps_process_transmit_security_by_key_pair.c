/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_process_transmit_security_by_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_process_transmit_security_by_key_pair(int param_1,int param_2)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int aiStack_64 [4];
  byte bStack_51;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined1 uStack_44;
  char acStack_40 [16];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  byte bStack_24;
  byte abStack_21 [13];
  
  aiStack_64[0] = param_1;
  iVar3 = nwk_secur_get_seclevel();
  zmsg_read_bytes(param_2,0,1,abStack_21);
  bVar2 = abStack_21[0];
  uVar4 = aps_fcf_get_hdr_size(abStack_21[0]);
  if ((char)bVar2 < '\0') {
    iVar9 = zmsg_read_bytes(param_2,uVar4,1,&bStack_51);
    if ((bStack_51 & 3) == 1) {
      iVar7 = 1;
    }
    else if ((bStack_51 & 3) == 2) {
      iVar7 = 1;
    }
    else {
      iVar7 = 0;
    }
    uVar4 = (uVar4 + iVar9 & 0xffff) + iVar7 & 0xffff;
  }
  if ((abStack_21[0] & 0x20) == 0) {
    iVar3 = 0;
  }
  else if (iVar3 == 0) {
    iVar3 = 0x13;
  }
  else if (aiStack_64[0] == 0) {
    iVar3 = 0x13;
  }
  else {
    zmsg_read_bytes(param_2,uVar4,0xe,&uStack_30);
    uStack_30 = CONCAT31(uStack_30._1_3_,(byte)uStack_30 | (byte)iVar3 & 7);
    uVar5 = aps_secur_inc_frame_cntr(aiStack_64[0]);
    uStack_30 = CONCAT13((char)((uint)uVar5 >> 0x10),
                         CONCAT12((char)((uint)uVar5 >> 8),
                                  CONCAT11((char)uVar5,(undefined1)uStack_30)));
    uStack_2c = CONCAT31(uStack_2c._1_3_,(char)((uint)uVar5 >> 0x18));
    puVar6 = (undefined4 *)nwk_get_extended_address();
    uVar5 = *puVar6;
    uVar1 = puVar6[1];
    uStack_2c = CONCAT13((char)((uint)uVar5 >> 0x10),
                         CONCAT12((char)((uint)uVar5 >> 8),
                                  CONCAT11((char)*(undefined3 *)puVar6,(undefined1)uStack_2c)));
    uStack_28 = CONCAT13((char)((uint)uVar1 >> 0x10),
                         CONCAT12((char)((uint)uVar1 >> 8),
                                  CONCAT11((char)*(undefined3 *)(puVar6 + 1),
                                           (char)((uint)uVar5 >> 0x18))));
    bStack_24 = (byte)((uint)uVar1 >> 0x18);
    if ((uStack_30 & 0x20) == 0) {
      iVar9 = 5;
    }
    else {
      iVar9 = 0xd;
    }
    if ((uStack_30 & 0x18) == 8) {
      iVar9 = iVar9 + 1;
    }
    zmsg_write_bytes(param_2,uVar4,iVar9,&uStack_30);
    if ((uStack_2c << 0x18 | uStack_30 >> 8) == 0xffffffff) {
      iVar3 = 0x13;
    }
    else {
      aps_secur_key_pair_get_key(aiStack_64[0],acStack_40,uStack_30 & 0x18);
      uVar8 = 0x10;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1 & 0xff;
      } while (acStack_40[uVar8] == '\0');
      if (uVar8 == 0) {
        iVar3 = 0x13;
      }
      else {
        uStack_50 = uStack_28 << 0x18 | uStack_2c >> 8;
        uStack_4c = (uint)bStack_24 << 0x18 | uStack_28 >> 8;
        uStack_48 = uStack_2c << 0x18 | uStack_30 >> 8;
        uStack_44 = (undefined1)uStack_30;
        iVar3 = secur_secure_msg(iVar3,acStack_40,&uStack_50,param_2,iVar9 + uVar4 & 0xffff);
        if (iVar3 == 0) {
          *(ushort *)(param_2 + 0x16) = *(ushort *)(param_2 + 0x16) | 4;
          zmsg_add_footer(param_2,aiStack_64,4);
          bStack_51 = (byte)uStack_30 & 0xf8;
          uStack_30 = uStack_30 & 0xfffffff8;
          zmsg_write_bytes(param_2,uVar4,1,&bStack_51);
        }
      }
    }
  }
  return iVar3;
}


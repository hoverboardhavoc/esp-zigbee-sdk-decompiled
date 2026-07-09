/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_process_transmit_done_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_process_transmit_done_security(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  byte bStack_55;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined1 uStack_48;
  int iStack_44;
  char acStack_40 [16];
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  byte bStack_24;
  byte abStack_21 [13];
  
  uVar4 = nwk_secur_get_seclevel();
  zmsg_read_bytes(param_1,0,1,abStack_21);
  bVar3 = abStack_21[0];
  uVar5 = aps_fcf_get_hdr_size(abStack_21[0]);
  if ((char)bVar3 < '\0') {
    iVar9 = zmsg_read_bytes(param_1,uVar5,1,&bStack_55);
    if ((bStack_55 & 3) == 1) {
      iVar7 = 1;
    }
    else if ((bStack_55 & 3) == 2) {
      iVar7 = 1;
    }
    else {
      iVar7 = 0;
    }
    uVar5 = (uVar5 + iVar9 & 0xffff) + iVar7 & 0xffff;
  }
  zmsg_set_offset(param_1,uVar5);
  if ((abStack_21[0] & 0x20) == 0) {
    uVar4 = 0;
  }
  else {
    *(ushort *)(param_1 + 0x16) = *(ushort *)(param_1 + 0x16) | 4;
    zmsg_read_bytes(param_1,uVar5,0xe,&uStack_30);
    if ((uStack_30 & 0x20) == 0) {
      iVar9 = 5;
    }
    else {
      iVar9 = 0xd;
    }
    if ((uStack_30 & 0x18) == 8) {
      iVar9 = iVar9 + 1;
    }
    if ((uStack_30 & 0x20) == 0) {
      puVar6 = (undefined4 *)nwk_get_extended_address();
      uVar1 = *puVar6;
      uVar2 = puVar6[1];
      uStack_2c = CONCAT13((char)((uint)uVar1 >> 0x10),
                           CONCAT12((char)((uint)uVar1 >> 8),
                                    CONCAT11((char)*(undefined3 *)puVar6,(undefined1)uStack_2c)));
      uStack_28 = CONCAT13((char)((uint)uVar2 >> 0x10),
                           CONCAT12((char)((uint)uVar2 >> 8),
                                    CONCAT11((char)*(undefined3 *)(puVar6 + 1),
                                             (char)((uint)uVar1 >> 0x18))));
      bStack_24 = (byte)((uint)uVar2 >> 0x18);
    }
    bStack_55 = (byte)uStack_30 | (byte)uVar4 & 7;
    uStack_30 = CONCAT31(uStack_30._1_3_,bStack_55);
    zmsg_write_bytes(param_1,uVar5,1,&bStack_55);
    uVar5 = iVar9 + uVar5 & 0xffff;
    zmsg_set_offset(param_1,uVar5);
    zmsg_get_footer(param_1,&iStack_44,4);
    zmsg_remove_footer(param_1,4);
    if (iStack_44 == 0) {
      uVar4 = 0x13;
    }
    else {
      aps_secur_key_pair_get_key(acStack_40,uStack_30 & 0x18);
      uVar8 = 0x10;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1 & 0xff;
      } while (acStack_40[uVar8] == '\0');
      if (uVar8 == 0) {
        uVar4 = 0x13;
      }
      else {
        uStack_54 = uStack_28 << 0x18 | uStack_2c >> 8;
        uStack_50 = (uint)bStack_24 << 0x18 | uStack_28 >> 8;
        uStack_4c = uStack_2c << 0x18 | uStack_30 >> 8;
        uStack_48 = (undefined1)uStack_30;
        uVar4 = secur_unsecure_msg(uVar4,acStack_40,&uStack_54,param_1,uVar5);
      }
    }
  }
  return uVar4;
}


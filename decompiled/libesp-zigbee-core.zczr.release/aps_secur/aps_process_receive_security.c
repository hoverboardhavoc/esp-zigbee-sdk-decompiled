/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_process_receive_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_process_receive_security(undefined4 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  byte bStack_5d;
  int iStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined1 uStack_44;
  uint local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  byte bStack_34;
  byte abStack_30 [20];
  
  iVar2 = nwk_secur_get_seclevel();
  zmsg_read_bytes(param_2,0,1,&bStack_5d);
  bVar1 = bStack_5d;
  uVar3 = aps_fcf_get_hdr_size(bStack_5d);
  if ((char)bVar1 < '\0') {
    iVar4 = zmsg_read_bytes(param_2,uVar3,1,abStack_30);
    uVar3 = ((abStack_30[0] & 3) - 1 < 2) + uVar3 + iVar4 & 0xffff;
  }
  zmsg_set_offset(param_2,uVar3);
  if ((bStack_5d & 0x20) == 0) {
    return 0;
  }
  *(ushort *)(param_2 + 0x16) = *(ushort *)(param_2 + 0x16) | 4;
  if (iVar2 == 0) {
    return 0x13;
  }
  zmsg_read_bytes(param_2,uVar3,0xe,&local_40);
  uVar7 = local_40;
  iVar4 = secur_scf_get_aux_hdr_size(local_40 & 0xff);
  if ((uStack_3c << 0x18 | local_40 >> 8) == 0xffffffff) {
    return 0x13;
  }
  if ((uVar7 & 0x20) == 0) {
    iVar5 = nwk_address_extended_by_short(param_1,&uStack_58);
    if (iVar5 != 0) {
      return iVar5;
    }
    uStack_3c = CONCAT13((char)(uStack_58 >> 0x10),
                         CONCAT12((char)(uStack_58 >> 8),
                                  CONCAT11((char)uStack_58,(undefined1)uStack_3c)));
    uStack_38 = CONCAT13((char)(uStack_54 >> 0x10),
                         CONCAT12((char)(uStack_54 >> 8),
                                  CONCAT11((char)uStack_54,(char)(uStack_58 >> 0x18))));
    bStack_34 = (byte)(uStack_54 >> 0x18);
  }
  else {
    uStack_58 = uStack_38 << 0x18 | uStack_3c >> 8;
    uStack_54 = (uint)bStack_34 << 0x18 | uStack_38 >> 8;
  }
  local_40 = CONCAT31(local_40._1_3_,(byte)local_40 | (byte)iVar2 & 7);
  zmsg_write_bytes(param_2,uVar3,1,&local_40);
  zmsg_set_offset(param_2,iVar4 + uVar3 & 0xffff);
  iVar2 = aps_secur_get_key_pair_by_addr(&uStack_58);
  if (iVar2 == 0) {
    return 0x13;
  }
  uVar7 = uStack_3c << 0x18 | local_40 >> 8;
  iStack_5c = iVar2;
  aps_secur_key_pair_get_key(abStack_30,local_40 & 0x18);
  iVar4 = secur_is_key_valid(abStack_30);
  uVar3 = local_40;
  if (iVar4 != 0) {
    uStack_50 = uStack_38 << 0x18 | uStack_3c >> 8;
    uStack_4c = (uint)bStack_34 << 0x18 | uStack_38 >> 8;
    uStack_44 = (undefined1)local_40;
    uStack_48 = uStack_3c << 0x18 | local_40 >> 8;
    uVar6 = zmsg_get_offset(param_2);
    iVar4 = secur_unsecure_msg(uVar3 & 7,abStack_30,&uStack_50,param_2,uVar6);
    if (iVar4 != 0) goto _L0;
    if (*(uint *)(iVar2 + 0xc) <= uVar7) {
      *(uint *)(iVar2 + 0xc) = uVar7 + 1;
      goto _L0;
    }
  }
  iVar4 = 0x13;
_L0:
  secur_key_clear(abStack_30);
  if (iVar4 == 0) {
    zmsg_add_footer(param_2,&iStack_5c);
    return 0;
  }
  return iVar4;
}


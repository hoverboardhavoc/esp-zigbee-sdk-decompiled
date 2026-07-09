/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_process_receive_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_process_receive_security(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  byte abStack_44 [4];
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined1 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  byte bStack_24;
  char cStack_23;
  ushort auStack_22 [5];
  
  iVar2 = nwk_secur_get_seclevel();
  zmsg_read_bytes(param_1,0,2,auStack_22);
  uVar1 = auStack_22[0];
  uVar3 = nwk_fcf_get_hdr_size(auStack_22[0]);
  if ((uVar1 & 0x400) != 0) {
    iVar5 = zmsg_read_bytes(param_1,uVar3,2,abStack_44);
    uVar3 = (uint)abStack_44[0] * 2 + (uVar3 + iVar5 & 0xffff) & 0xffff;
  }
  if ((auStack_22[0] & 0x200) != 0) {
    *(ushort *)(param_1 + 0x16) = *(ushort *)(param_1 + 0x16) | 2;
    if (iVar2 == 0) {
      return 0x13;
    }
    zmsg_read_bytes(param_1,uVar3,0xe,&uStack_30);
    if ((char)uStack_30 != '(') {
      return 0x13;
    }
    if ((uStack_2c << 0x18 | uStack_30 >> 8) == 0xffffffff) {
      return 0x13;
    }
    uVar4 = nwk_secur_get_key_by_seq(cStack_23);
    iVar5 = secur_is_key_valid();
    if (iVar5 == 0) {
      return 0x2cd;
    }
    iVar5 = nwk_neighbor_table_get_by_extended((int)&uStack_2c + 1);
    if (((iVar5 != 0) && (*(char *)(iVar5 + 7) == cStack_23)) &&
       ((uStack_2c << 0x18 | uStack_30 >> 8) < *(uint *)(iVar5 + 8))) {
      return 0x13;
    }
    uStack_30 = CONCAT31(uStack_30._1_3_,(byte)uStack_30 | (byte)iVar2 & 7);
    zmsg_write_bytes(param_1,uVar3,1,&uStack_30);
    uVar3 = uVar3 + 0xe & 0xffff;
    uStack_40 = uStack_28 << 0x18 | uStack_2c >> 8;
    uStack_3c = (uint)bStack_24 << 0x18 | uStack_28 >> 8;
    uStack_38 = uStack_2c << 0x18 | uStack_30 >> 8;
    uStack_34 = (char)uStack_30;
    iVar2 = secur_unsecure_msg(iVar2,uVar4,&uStack_40,param_1,uVar3);
    if (iVar2 != 0) {
      return 0x2ce;
    }
    if (iVar5 != 0) {
      *(uint *)(iVar5 + 8) = (uStack_2c << 0x18 | uStack_30 >> 8) + 1;
      *(char *)(iVar5 + 7) = cStack_23;
    }
  }
  zmsg_set_offset(param_1,uVar3);
  return 0;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_process_receive_security
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
  int iVar4;
  undefined4 uVar5;
  ushort uStack_42;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined1 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  byte bStack_24;
  char cStack_23;
  
  iVar2 = nwk_secur_get_seclevel();
  zmsg_read_bytes(param_1,0,2,&uStack_42);
  uVar1 = uStack_42;
  uVar3 = nwk_fcf_get_hdr_size(uStack_42);
  if ((uVar1 & 0x400) != 0) {
    iVar4 = zmsg_read_bytes(param_1,uVar3,2,&uStack_30);
    uVar3 = (uStack_30 & 0xff) * 2 + uVar3 + iVar4 & 0xffff;
  }
  if ((uStack_42 & 0x200) == 0) {
_L0:
    zmsg_set_offset(param_1,uVar3);
    uVar5 = 0;
  }
  else {
    *(ushort *)(param_1 + 0x16) = *(ushort *)(param_1 + 0x16) | 2;
    if (iVar2 != 0) {
      zmsg_read_bytes(param_1,uVar3,0xe,&uStack_30);
      if (((char)uStack_30 == '(') && ((uStack_2c << 0x18 | uStack_30 >> 8) != 0xffffffff)) {
        uVar5 = nwk_secur_get_key_by_seq(cStack_23);
        iVar4 = secur_is_key_valid();
        if (iVar4 == 0) {
          return 0x2cd;
        }
        iVar4 = nwk_neighbor_table_get_by_extended((int)&uStack_2c + 1);
        if (((iVar4 == 0) || (*(char *)(iVar4 + 7) != cStack_23)) ||
           (*(uint *)(iVar4 + 8) <= (uStack_2c << 0x18 | uStack_30 >> 8))) {
          uStack_30 = CONCAT31(uStack_30._1_3_,(byte)iVar2 | (byte)uStack_30);
          zmsg_write_bytes(param_1,uVar3,1,&uStack_30);
          uStack_40 = uStack_28 << 0x18 | uStack_2c >> 8;
          uStack_3c = (uint)bStack_24 << 0x18 | uStack_28 >> 8;
          uVar3 = uVar3 + 0xe & 0xffff;
          uStack_38 = uStack_2c << 0x18 | uStack_30 >> 8;
          uStack_34 = (char)uStack_30;
          iVar2 = secur_unsecure_msg(iVar2,uVar5,&uStack_40,param_1,uVar3);
          if (iVar2 != 0) {
            return 0x2ce;
          }
          if (iVar4 != 0) {
            *(uint *)(iVar4 + 8) = (uStack_2c << 0x18 | uStack_30 >> 8) + 1;
            *(char *)(iVar4 + 7) = cStack_23;
          }
          goto _L0;
        }
      }
    }
    uVar5 = 0x13;
  }
  return uVar5;
}


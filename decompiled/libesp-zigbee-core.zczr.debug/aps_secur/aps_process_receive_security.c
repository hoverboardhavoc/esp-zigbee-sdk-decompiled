/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_process_receive_security
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
  byte bStack_3d;
  uint uStack_3c;
  uint uStack_38;
  int iStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  byte bStack_24;
  byte abStack_21 [5];
  
  iVar2 = nwk_secur_get_seclevel();
  zmsg_read_bytes(param_2,0,1,abStack_21);
  bVar1 = abStack_21[0];
  uVar3 = aps_fcf_get_hdr_size(abStack_21[0]);
  if ((char)bVar1 < '\0') {
    iVar5 = zmsg_read_bytes(param_2,uVar3,1,&bStack_3d);
    if ((bStack_3d & 3) == 1) {
      iVar4 = 1;
    }
    else if ((bStack_3d & 3) == 2) {
      iVar4 = 1;
    }
    else {
      iVar4 = 0;
    }
    uVar3 = (uVar3 + iVar5 & 0xffff) + iVar4 & 0xffff;
  }
  zmsg_set_offset(param_2,uVar3);
  if ((abStack_21[0] & 0x20) == 0) {
    iVar2 = 0;
  }
  else {
    *(ushort *)(param_2 + 0x16) = *(ushort *)(param_2 + 0x16) | 4;
    if (iVar2 == 0) {
      iVar2 = 0x13;
    }
    else {
      zmsg_read_bytes(param_2,uVar3,0xe,&uStack_30);
      if ((uStack_30 & 0x20) == 0) {
        iVar5 = 5;
      }
      else {
        iVar5 = 0xd;
      }
      if ((uStack_30 & 0x18) == 8) {
        iVar5 = iVar5 + 1;
      }
      if ((uStack_2c << 0x18 | uStack_30 >> 8) == 0xffffffff) {
        iVar2 = 0x13;
      }
      else {
        if ((uStack_30 & 0x20) == 0) {
          iVar4 = nwk_address_extended_by_short(param_1,&uStack_3c);
          if (iVar4 != 0) {
            return iVar4;
          }
          uStack_2c = CONCAT13((char)(uStack_3c >> 0x10),
                               CONCAT12((char)(uStack_3c >> 8),
                                        CONCAT11((char)uStack_3c,(undefined1)uStack_2c)));
          uStack_28 = CONCAT13((char)(uStack_38 >> 0x10),
                               CONCAT12((char)(uStack_38 >> 8),
                                        CONCAT11((char)uStack_38,(char)(uStack_3c >> 0x18))));
          bStack_24 = (byte)(uStack_38 >> 0x18);
        }
        else {
          uStack_3c = uStack_28 << 0x18 | uStack_2c >> 8;
          uStack_38 = (uint)bStack_24 << 0x18 | uStack_28 >> 8;
        }
        uStack_30 = CONCAT31(uStack_30._1_3_,(byte)uStack_30 | (byte)iVar2 & 7);
        zmsg_write_bytes(param_2,uVar3,1,&uStack_30);
        zmsg_set_offset(param_2,iVar5 + uVar3 & 0xffff);
        iStack_34 = aps_secur_get_key_pair_by_addr(&uStack_3c);
        if (iStack_34 == 0) {
          iVar2 = 0x13;
        }
        else {
          iVar2 = aps_secur_unsecure_msg_by_key_pair(param_2,&uStack_30);
          if (iVar2 == 0) {
            zmsg_add_footer(param_2,&iStack_34,4);
          }
        }
      }
    }
  }
  return iVar2;
}


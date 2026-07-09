/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_process_transmit_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_process_transmit_security(int param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  ushort uStack_46;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  undefined1 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  byte bStack_24;
  undefined1 uStack_23;
  
  iVar3 = nwk_secur_get_seclevel();
  zmsg_read_bytes(param_1,0,2,&uStack_46);
  uVar1 = uStack_46;
  uVar4 = nwk_fcf_get_hdr_size(uStack_46);
  if ((uVar1 & 0x400) != 0) {
    iVar5 = zmsg_read_bytes(param_1,uVar4,2,&uStack_30);
    uVar4 = (uStack_30 & 0xff) * 2 + uVar4 + iVar5 & 0xffff;
  }
  if ((uStack_46 & 0x200) != 0) {
    uVar1 = *(ushort *)(param_1 + 0x16);
    *(ushort *)(param_1 + 0x16) = uVar1 | 2;
    if (iVar3 == 0) {
      return 0x13;
    }
    if ((uVar1 & 8) == 0) {
      iVar5 = core_globals_get();
      uStack_23 = *(undefined1 *)(iVar5 + 0xa22);
    }
    else {
      zmsg_read_bytes(param_1,uVar4,0xe,&uStack_30);
    }
    uStack_30 = CONCAT31(uStack_30._1_3_,(char)iVar3) | 0x28;
    iVar5 = core_globals_get();
    if ((*(uint *)(iVar5 + 0x9fc) & 0x3ff) == 0) {
      iVar6 = core_globals_get();
      uStack_44 = *(int *)(iVar6 + 0x9fc) + 0x400;
      uStack_40 = 0;
      ds_internal_save_entry(8,&uStack_44,&uStack_40,4);
    }
    iVar6 = *(int *)(iVar5 + 0x9fc);
    *(int *)(iVar5 + 0x9fc) = iVar6 + 1;
    uStack_30 = CONCAT13((char)((uint)iVar6 >> 0x10),
                         CONCAT12((char)((uint)iVar6 >> 8),
                                  CONCAT11((char)iVar6,(undefined1)uStack_30)));
    uStack_2c = CONCAT31(uStack_2c._1_3_,(char)((uint)iVar6 >> 0x18));
    iVar5 = core_globals_get();
    uStack_2c = CONCAT13((char)*(undefined4 *)(iVar5 + 0x9e8),
                         CONCAT12((char)((ushort)*(undefined2 *)(iVar5 + 0x9e6) >> 8),
                                  CONCAT11((char)*(undefined2 *)(iVar5 + 0x9e6),
                                           (undefined1)uStack_2c)));
    uStack_28 = CONCAT13((char)*(undefined2 *)(iVar5 + 0x9ec),
                         (int3)((uint)*(undefined4 *)(iVar5 + 0x9e8) >> 8));
    bStack_24 = (byte)((ushort)*(undefined2 *)(iVar5 + 0x9ec) >> 8);
    zmsg_write_bytes(param_1,uVar4,0xe,&uStack_30);
    if ((uStack_2c << 0x18 | uStack_30 >> 8) == 0xffffffff) {
      return 0x2cc;
    }
    uVar7 = nwk_secur_get_key_by_seq(uStack_23);
    iVar5 = secur_is_key_valid();
    if (iVar5 == 0) {
      return 0x2cd;
    }
    uStack_40 = uStack_28 << 0x18 | uStack_2c >> 8;
    uStack_3c = (uint)bStack_24 << 0x18 | uStack_28 >> 8;
    uStack_38 = uStack_2c << 0x18 | uStack_30 >> 8;
    uStack_34 = (undefined1)uStack_30;
    iVar3 = secur_secure_msg(iVar3,uVar7,&uStack_40,param_1,uVar4 + 0xe & 0xffff);
    if (iVar3 != 0) {
      return 0x2ce;
    }
    uVar2 = (undefined1)uStack_30;
    uStack_30 = uStack_30 & 0xfffffff8;
    uStack_44 = CONCAT31(uStack_44._1_3_,uVar2) & 0xfffffff8;
    zmsg_write_bytes(param_1,uVar4,1,&uStack_44);
  }
  return 0;
}


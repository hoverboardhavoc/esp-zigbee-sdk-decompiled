/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_process_transmit_done_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_process_transmit_done_security(int param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  byte bStack_55;
  int iStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined1 uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  byte bStack_34;
  byte abStack_30 [24];
  
  uVar3 = nwk_secur_get_seclevel();
  zmsg_read_bytes(param_1,0,1,&bStack_55);
  bVar2 = bStack_55;
  uVar4 = aps_fcf_get_hdr_size(bStack_55);
  if ((char)bVar2 < '\0') {
    iVar5 = zmsg_read_bytes(param_1,uVar4,1,abStack_30);
    uVar4 = ((abStack_30[0] & 3) - 1 < 2) + uVar4 + iVar5 & 0xffff;
  }
  zmsg_set_offset(param_1,uVar4);
  uVar7 = 0;
  if ((bStack_55 & 0x20) != 0) {
    *(ushort *)(param_1 + 0x16) = *(ushort *)(param_1 + 0x16) | 4;
    zmsg_read_bytes(param_1,uVar4,0xe,&uStack_40);
    uVar8 = uStack_40;
    iVar5 = secur_scf_get_aux_hdr_size(uStack_40 & 0xff);
    if ((uVar8 & 0x20) == 0) {
      puVar6 = (undefined4 *)nwk_get_extended_address();
      uVar7 = *puVar6;
      uVar1 = puVar6[1];
      uStack_3c = CONCAT13((char)((uint)uVar7 >> 0x10),
                           CONCAT12((char)((uint)uVar7 >> 8),
                                    CONCAT11((char)*(undefined3 *)puVar6,(undefined1)uStack_3c)));
      uStack_38 = CONCAT13((char)((uint)uVar1 >> 0x10),
                           CONCAT21(CONCAT11((char)((uint)uVar1 >> 8),
                                             (char)*(undefined3 *)(puVar6 + 1)),
                                    (char)((uint)uVar7 >> 0x18)));
      bStack_34 = (byte)((uint)uVar1 >> 0x18);
    }
    abStack_30[0] = (byte)uStack_40 | (byte)uVar3 & 7;
    uStack_40 = CONCAT31(uStack_40._1_3_,abStack_30[0]);
    uVar8 = iVar5 + uVar4 & 0xffff;
    zmsg_write_bytes(param_1,uVar4,1,abStack_30);
    zmsg_set_offset(param_1,uVar8);
    zmsg_get_footer(param_1,&iStack_54,4);
    zmsg_remove_footer(param_1,4);
    if (iStack_54 != 0) {
      aps_secur_key_pair_get_key(abStack_30,uStack_40 & 0x18);
      iVar5 = secur_is_key_valid(abStack_30);
      if (iVar5 != 0) {
        uStack_50 = uStack_38 << 0x18 | uStack_3c >> 8;
        uStack_4c = (uint)bStack_34 << 0x18 | uStack_38 >> 8;
        uStack_48 = uStack_3c << 0x18 | uStack_40 >> 8;
        uStack_44 = (undefined1)uStack_40;
        uVar7 = secur_unsecure_msg(uVar3,abStack_30,&uStack_50,param_1,uVar8);
        goto _L0;
      }
    }
    uVar7 = 0x13;
  }
_L0:
  secur_key_clear(abStack_30);
  return uVar7;
}


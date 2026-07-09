/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_transport_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_transport_key_request(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  char *pcVar11;
  undefined4 uVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined1 uStack_58;
  char cStack_57;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  undefined1 auStack_31 [13];
  
  if (*(int *)((int)param_1 + 0x22) == 0 && *(int *)((int)param_1 + 0x26) == 0) {
    bVar13 = true;
  }
  else if ((*(int *)((int)param_1 + 0x22) == -1) && (*(int *)((int)param_1 + 0x26) == -1)) {
    bVar13 = true;
  }
  else {
    bVar13 = false;
  }
  uVar2 = *param_1;
  uVar3 = param_1[1];
  if (bVar13) {
    if ((uVar2 == 0xffffffff) && (uVar3 == 0xffffffff)) {
      uVar14 = 0;
    }
    else {
      uVar14 = 1;
    }
    if (param_1 == (uint *)0x0) {
      iVar6 = 2;
      iVar8 = 0;
      goto _L0;
    }
  }
  else {
    uVar14 = 0;
  }
  if (uVar2 == 0 && uVar3 == 0) {
    iVar8 = 0;
    iVar6 = 2;
    goto _L0;
  }
  if ((uVar2 == 0xffffffff) && (uVar3 == 0xffffffff)) {
    iVar8 = 0x27;
    iVar6 = 0;
  }
  else {
    iVar8 = 0x2f;
    iVar6 = 0xd;
  }
  iVar8 = zmsg_alloc(iVar8 + iVar6);
  if (iVar8 == 0) {
    iVar6 = 1;
    goto _L0;
  }
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  bVar1 = (byte)param_1[2];
  uStack_54 = (uint)bVar1;
  if (bVar1 == 3) {
    memcpy((void *)((int)&uStack_54 + 1),(void *)((int)param_1 + 9),0x10);
    uVar7 = *(undefined4 *)((int)param_1 + 0x19);
    uVar12 = *(undefined4 *)((int)param_1 + 0x1d);
    uStack_44._0_2_ = CONCAT11((char)*(undefined2 *)((int)param_1 + 0x19),(undefined1)uStack_44);
    uStack_44._0_3_ = CONCAT12((char)((uint)uVar7 >> 8),(undefined2)uStack_44);
    uStack_44 = CONCAT13((char)((uint)uVar7 >> 0x10),(undefined3)uStack_44);
    uStack_40._0_2_ =
         CONCAT11((char)*(undefined2 *)((int)param_1 + 0x1d),(char)((uint)uVar7 >> 0x18));
    uStack_40._0_3_ = CONCAT12((char)((uint)uVar12 >> 8),(undefined2)uStack_40);
    uStack_40 = CONCAT13((char)((uint)uVar12 >> 0x10),(undefined3)uStack_40);
    uStack_3c._0_2_ = CONCAT11(*(char *)((int)param_1 + 0x21) != '\0',(char)((uint)uVar12 >> 0x18));
    uVar12 = 0x18;
    uVar7 = 0x1a;
  }
  else if (bVar1 == 4) {
    memcpy((void *)((int)&uStack_54 + 1),(void *)((int)param_1 + 9),0x10);
    uVar4 = *param_1;
    uVar5 = param_1[1];
    uStack_44._0_2_ = CONCAT11((char)(short)*param_1,(undefined1)uStack_44);
    uStack_44._0_3_ = CONCAT12((char)(uVar4 >> 8),(undefined2)uStack_44);
    uStack_44 = CONCAT13((char)(uVar4 >> 0x10),(undefined3)uStack_44);
    uStack_40._0_2_ = CONCAT11((char)(short)param_1[1],(char)(uVar4 >> 0x18));
    uStack_40._0_3_ = CONCAT12((char)(uVar5 >> 8),(undefined2)uStack_40);
    uStack_40 = CONCAT13((char)(uVar5 >> 0x10),(undefined3)uStack_40);
    uStack_3c = CONCAT31(uStack_3c._1_3_,(char)(uVar5 >> 0x18));
    puVar9 = (undefined4 *)nwk_get_extended_address();
    uVar7 = *puVar9;
    uVar12 = puVar9[1];
    uStack_3c._0_2_ = CONCAT11((char)*(undefined3 *)puVar9,(undefined1)uStack_3c);
    uStack_3c = CONCAT13((char)((uint)uVar7 >> 0x10),
                         CONCAT12((char)((uint)uVar7 >> 8),(undefined2)uStack_3c));
    uStack_38 = CONCAT13((char)((uint)uVar12 >> 0x10),
                         CONCAT12((char)((uint)uVar12 >> 8),
                                  CONCAT11((char)*(undefined3 *)(puVar9 + 1),
                                           (char)((uint)uVar7 >> 0x18))));
    uStack_34 = CONCAT11(uStack_34._1_1_,(char)((uint)uVar12 >> 0x18));
    uVar12 = 0x18;
    uVar7 = 0x21;
  }
  else {
    if (bVar1 != 1) {
      iVar6 = 2;
      goto _L0;
    }
    memcpy((void *)((int)&uStack_54 + 1),(void *)((int)param_1 + 9),0x10);
    uStack_44._0_2_ = CONCAT11(*(undefined1 *)((int)param_1 + 0x19),(undefined1)uStack_44);
    if ((uVar2 != 0xffffffff) || (uVar3 != 0xffffffff)) {
      uStack_44._2_2_ = (undefined2)*param_1;
      uStack_40 = CONCAT22((short)param_1[1],(short)(*param_1 >> 0x10));
      uStack_3c = CONCAT22(uStack_3c._2_2_,(short)(param_1[1] >> 0x10));
    }
    puVar9 = (undefined4 *)aps_secur_get_tc_address();
    uStack_3c = CONCAT22((short)*(undefined3 *)puVar9,(undefined2)uStack_3c);
    uStack_38 = CONCAT22((short)*(undefined3 *)(puVar9 + 1),(short)((uint)*puVar9 >> 0x10));
    uStack_34 = (undefined2)((uint)puVar9[1] >> 0x10);
    uVar12 = 0x10;
    uVar7 = 0x22;
  }
  aps_frame_append_cmd_hdr
            (iVar8,(uVar2 & uVar3) == 0xffffffff,uVar14,(uVar2 & uVar3) != 0xffffffff,uVar12);
  uStack_58 = 5;
  zmsg_append_bytes(iVar8,1,&uStack_58);
  zmsg_append_bytes(iVar8,uVar7,&uStack_54);
  if (bVar13) {
    if ((char)param_1[2] == '\x01') {
      if ((*(int *)((int)param_1 + 0x1a) != 0 || *(int *)((int)param_1 + 0x1e) != 0) &&
         ((*(int *)((int)param_1 + 0x1a) != -1 || (*(int *)((int)param_1 + 0x1e) != -1)))) {
        param_1 = (uint *)((int)param_1 + 0x1a);
      }
    }
_L0:
    iVar6 = aps_send_cmd(iVar8,param_1);
  }
  else {
    iVar6 = aps_process_transmit_security(param_1,iVar8);
    if (iVar6 != 0) goto _L0;
    piVar10 = (int *)nwk_get_extended_address();
    if ((*(int *)((int)param_1 + 0x22) != *piVar10) || (*(int *)((int)param_1 + 0x26) != piVar10[1])
       ) {
      uStack_58 = 1;
      pcVar11 = (char *)core_globals_get();
      cStack_57 = *pcVar11;
      *pcVar11 = cStack_57 + '\x01';
      zmsg_prepend_bytes(iVar8,8,param_1);
      auStack_31[0] = 0xe;
      zmsg_prepend_bytes(iVar8,1,auStack_31);
      zmsg_prepend_bytes(iVar8,2,&uStack_58);
      param_1 = (uint *)((int)param_1 + 0x22);
      goto _L0;
    }
    iVar6 = aps_relay_cmd(iVar8,param_1);
  }
  if (iVar6 == 0) {
    return 0;
  }
_L0:
  if (iVar8 != 0) {
    zmsg_free(iVar8);
  }
  return iVar6;
}


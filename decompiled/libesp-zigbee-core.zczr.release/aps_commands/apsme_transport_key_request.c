/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_transport_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_transport_key_request(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  char *pcVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  undefined1 uStack_59;
  undefined1 uStack_58;
  char cStack_57;
  char cStack_54;
  undefined1 auStack_53 [16];
  undefined1 uStack_43;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  
  iVar5 = ezb_eui64_is_invalid((uint *)((int)param_1 + 0x22));
  uVar1 = *param_1;
  uVar2 = param_1[1];
  if (iVar5 == 0) {
    if (uVar1 == 0 && uVar2 == 0) {
      return 2;
    }
    iVar12 = 0;
    if ((uVar1 == 0xffffffff) && (uVar2 == 0xffffffff)) goto _L0;
_L0:
    iVar6 = 0x2f;
    iVar11 = 0xd;
  }
  else {
    if ((uVar1 != 0xffffffff) || (uVar2 != 0xffffffff)) {
      iVar12 = iVar5;
      if (uVar1 == 0 && uVar2 == 0) {
        return 2;
      }
      goto _L0;
    }
_L0:
    iVar12 = 0;
    iVar6 = 0x27;
    iVar11 = 0;
  }
  iVar6 = zmsg_alloc(iVar6 + iVar11);
  if (iVar6 == 0) {
    return 1;
  }
  memset(auStack_53,0,0x21);
  cStack_54 = (char)param_1[2];
  if (cStack_54 == '\x03') {
    memcpy(auStack_53,(void *)((int)param_1 + 9),0x10);
    uVar10 = *(undefined4 *)((int)param_1 + 0x19);
    uVar4 = *(undefined4 *)((int)param_1 + 0x1d);
    uStack_43 = (undefined1)*(undefined2 *)((int)param_1 + 0x19);
    uStack_3e = (undefined2)((uint)uVar4 >> 8);
    uStack_42 = (undefined2)((uint)uVar10 >> 8);
    uStack_40 = CONCAT11((char)*(undefined2 *)((int)param_1 + 0x1d),(char)((uint)uVar10 >> 0x18));
    uStack_3c = CONCAT11(*(undefined1 *)((int)param_1 + 0x21),(char)((uint)uVar4 >> 0x18));
    uVar10 = 0x18;
    uVar4 = 0x1a;
  }
  else if (cStack_54 == '\x04') {
    memcpy(auStack_53,(void *)((int)param_1 + 9),0x10);
    uVar3 = param_1[1];
    uStack_43 = (undefined1)(short)*param_1;
    uStack_42 = (undefined2)(*param_1 >> 8);
    uStack_40 = CONCAT11((char)(short)param_1[1],(char)(*param_1 >> 0x18));
    uStack_3e = (undefined2)(uVar3 >> 8);
    uStack_3c = CONCAT11(uStack_3c._1_1_,(char)(uVar3 >> 0x18));
    puVar7 = (undefined4 *)nwk_get_extended_address();
    uVar10 = puVar7[1];
    uStack_3c = CONCAT11((char)*(undefined3 *)puVar7,(undefined1)uStack_3c);
    uStack_36 = (undefined2)((uint)uVar10 >> 8);
    uStack_3a = (undefined2)((uint)*puVar7 >> 8);
    uStack_38 = CONCAT11((char)*(undefined3 *)(puVar7 + 1),(char)((uint)*puVar7 >> 0x18));
    uStack_34 = CONCAT11(uStack_34._1_1_,(char)((uint)uVar10 >> 0x18));
    uVar10 = 0x18;
    uVar4 = 0x21;
  }
  else {
    iVar11 = 2;
    if (cStack_54 != '\x01') goto _L0;
    memcpy(auStack_53,(void *)((int)param_1 + 9),0x10);
    uStack_43 = *(undefined1 *)((int)param_1 + 0x19);
    if ((uVar1 != 0xffffffff) || (uVar2 != 0xffffffff)) {
      uStack_42 = (undefined2)*param_1;
      uStack_3e = (undefined2)param_1[1];
      uStack_40 = (undefined2)(*param_1 >> 0x10);
      uStack_3c = (undefined2)(param_1[1] >> 0x10);
    }
    puVar7 = (undefined4 *)aps_secur_get_tc_address();
    uStack_38 = (undefined2)((uint)*puVar7 >> 0x10);
    uStack_3a = (undefined2)*(undefined3 *)puVar7;
    uStack_36 = (undefined2)*(undefined3 *)(puVar7 + 1);
    uStack_34 = (undefined2)((uint)puVar7[1] >> 0x10);
    uVar10 = 0x10;
    uVar4 = 0x22;
  }
  aps_frame_append_cmd_hdr
            (iVar6,(uVar1 & uVar2) == 0xffffffff,iVar12,(uVar1 & uVar2) != 0xffffffff,uVar10);
  zmsg_append_u8_isra_0(iVar6,5);
  zmsg_append_bytes(iVar6,uVar4,&cStack_54);
  if (iVar5 == 0) {
    iVar11 = aps_process_transmit_security(param_1,iVar6);
    if (iVar11 != 0) goto _L0;
    piVar8 = (int *)nwk_get_extended_address();
    if ((*(int *)((int)param_1 + 0x22) != *piVar8) || (*(int *)((int)param_1 + 0x26) != piVar8[1]))
    {
      uStack_58 = 1;
      pcVar9 = (char *)core_globals_get();
      cStack_57 = *pcVar9;
      *pcVar9 = cStack_57 + '\x01';
      zmsg_prepend_bytes(iVar6,8,param_1);
      uStack_59 = 0xe;
      zmsg_prepend_bytes(iVar6,1,&uStack_59);
      zmsg_prepend_bytes(iVar6,2,&uStack_58);
      param_1 = (uint *)((int)param_1 + 0x22);
      goto _L0;
    }
    iVar11 = aps_relay_cmd(iVar6,param_1);
  }
  else {
    if ((char)param_1[2] == '\x01') {
      iVar5 = ezb_eui64_is_invalid((uint *)((int)param_1 + 0x1a));
      if (iVar5 == 0) {
        param_1 = (uint *)((int)param_1 + 0x1a);
      }
    }
_L0:
    iVar11 = aps_send_cmd(iVar6,param_1);
  }
  if (iVar11 == 0) {
    return 0;
  }
_L0:
  zmsg_free(iVar6);
  return iVar11;
}


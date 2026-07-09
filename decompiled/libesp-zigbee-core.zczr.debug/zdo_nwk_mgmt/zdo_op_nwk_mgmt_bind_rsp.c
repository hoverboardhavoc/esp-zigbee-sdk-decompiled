/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_bind_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_mgmt_bind_rsp(int param_1,char *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  char *pcVar4;
  undefined4 unaff_s2;
  int iVar5;
  uint uVar6;
  uint unaff_s4;
  ushort uStack_22;
  
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    pcVar4 = "zdo_op_nwk_mgmt_bind_rsp";
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x19f,
                  "payload && rsp");
    goto _L0;
  }
  if (param_3 == 0) {
    uStack_22 = 0;
    uVar2 = zmsg_get_length();
    af_read_le8(param_1,&uStack_22,param_2);
    af_read_le8(param_1,&uStack_22,param_2 + 1);
    af_read_le8(param_1,&uStack_22,param_2 + 2);
    af_read_le8(param_1,&uStack_22,param_2 + 3);
    if (uStack_22 <= uVar2) {
      if (*param_2 != '\0') {
        return 0;
      }
      if ((byte)param_2[3] == 0) {
        return 0;
      }
      pvVar3 = calloc((uint)(byte)param_2[3],0x18);
      *(void **)(param_2 + 4) = pvVar3;
      if (pvVar3 != (void *)0x0) {
        uVar6 = 0;
        while( true ) {
          if ((byte)param_2[3] <= uVar6) {
            return 0;
          }
          iVar1 = uVar6 * 0x18;
          af_read_bytes(param_1,&uStack_22,8,*(int *)(param_2 + 4) + iVar1);
          af_read_le8(param_1,&uStack_22,*(int *)(param_2 + 4) + iVar1 + 8);
          af_read_le16(param_1,&uStack_22,*(int *)(param_2 + 4) + iVar1 + 10);
          af_read_le8(param_1,&uStack_22,*(int *)(param_2 + 4) + iVar1 + 0xc);
          if (uVar2 < uStack_22) break;
          iVar5 = *(int *)(param_2 + 4) + iVar1;
          if (*(char *)(iVar5 + 0xc) == '\x01') {
            af_read_le16(param_1,&uStack_22,iVar5 + 0xe);
            *(undefined1 *)(*(int *)(param_2 + 4) + iVar1 + 0x16) = 0;
          }
          else {
            if (*(char *)(iVar5 + 0xc) != '\x03') {
              return 0x80;
            }
            af_read_bytes(param_1,&uStack_22,8,iVar5 + 0xe);
            af_read_le8(param_1,&uStack_22,*(int *)(param_2 + 4) + iVar1 + 0x16);
          }
          if (uVar2 < uStack_22) {
            return 0xfe;
          }
          uVar6 = uVar6 + 1 & 0xff;
        }
      }
    }
    return 0xfe;
  }
  uStack_22._0_1_ = *param_2;
  iVar1 = zmsg_append_bytes(1,&uStack_22);
  if (iVar1 != 0) {
    return 0x8a;
  }
  uStack_22._0_1_ = param_2[1];
  iVar1 = zmsg_append_bytes(param_1,1,&uStack_22);
  if (iVar1 != 0) {
    return 0x8a;
  }
  uStack_22._0_1_ = param_2[2];
  iVar1 = zmsg_append_bytes(param_1,1,&uStack_22);
  if (iVar1 != 0) {
    return 0x8a;
  }
  uStack_22 = CONCAT11(uStack_22._1_1_,param_2[3]);
  iVar1 = zmsg_append_bytes(param_1,1,&uStack_22);
  if (iVar1 != 0) {
    return 0x8a;
  }
  if (*param_2 != '\0') {
    return 0;
  }
  unaff_s2 = 0;
  if (*(int *)(param_2 + 4) == 0) {
    return 0;
  }
  if (param_2[3] == '\0') {
    return 0;
  }
  unaff_s4 = 0;
  while( true ) {
    if ((byte)param_2[3] <= unaff_s4) {
      return unaff_s2;
    }
    iVar5 = unaff_s4 * 0x18;
    iVar1 = zmsg_append_bytes(param_1,8,*(int *)(param_2 + 4) + iVar5);
    if (iVar1 != 0) {
      return 0x8a;
    }
    uStack_22 = CONCAT11(uStack_22._1_1_,*(undefined1 *)(*(int *)(param_2 + 4) + iVar5 + 8));
    iVar1 = zmsg_append_bytes(param_1,1,&uStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    uStack_22 = *(ushort *)(*(int *)(param_2 + 4) + iVar5 + 10);
    iVar1 = zmsg_append_bytes(param_1,2,&uStack_22);
    if (iVar1 != 0) break;
    uStack_22 = CONCAT11(uStack_22._1_1_,*(undefined1 *)(*(int *)(param_2 + 4) + iVar5 + 0xc));
    iVar1 = zmsg_append_bytes(param_1,1,&uStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    pcVar4 = (char *)(*(int *)(param_2 + 4) + iVar5);
    if (pcVar4[0xc] == '\x01') {
_L0:
      uStack_22 = *(ushort *)(pcVar4 + 0xe);
      iVar1 = zmsg_append_bytes(param_1,2,&uStack_22);
      if (iVar1 != 0) {
        return 0x8a;
      }
    }
    else if (pcVar4[0xc] == '\x03') {
      iVar1 = zmsg_append_bytes(param_1,8,pcVar4 + 0xe);
      if (iVar1 != 0) {
        return 0x8a;
      }
      uStack_22 = CONCAT11(uStack_22._1_1_,*(undefined1 *)(*(int *)(param_2 + 4) + iVar5 + 0x16));
      iVar1 = zmsg_append_bytes(param_1,1,&uStack_22);
      if (iVar1 != 0) {
        return 0x8a;
      }
    }
    unaff_s4 = unaff_s4 + 1 & 0xff;
  }
  return 0x8a;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_lqi_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_mgmt_lqi_rsp(int param_1,char *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 unaff_s4;
  uint uVar6;
  uint uVar7;
  byte bStack_24;
  byte bStack_23;
  ushort uStack_22;
  
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x9c,
                  "zdo_op_nwk_mgmt_lqi_rsp","payload && rsp");
    return unaff_s4;
  }
  if (param_3 != 0) {
    uStack_22._0_1_ = *param_2;
    iVar2 = zmsg_append_bytes(1,&uStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    uStack_22._0_1_ = param_2[1];
    iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    uStack_22._0_1_ = param_2[2];
    iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    uStack_22 = CONCAT11(uStack_22._1_1_,param_2[3]);
    iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    if (*param_2 != '\0') {
      return 0;
    }
    if (*(int *)(param_2 + 4) == 0) {
      return 0;
    }
    if (param_2[3] == '\0') {
      return 0;
    }
    uVar7 = 0;
    while( true ) {
      if ((byte)param_2[3] <= uVar7) {
        return 0;
      }
      iVar5 = uVar7 * 0x16;
      uVar1 = *(ushort *)(*(int *)(param_2 + 4) + iVar5 + 0x12);
      iVar2 = zmsg_append_bytes(param_1,8);
      if (iVar2 != 0) {
        return 0x8a;
      }
      iVar2 = zmsg_append_bytes(param_1,8,*(int *)(param_2 + 4) + iVar5 + 8);
      if (iVar2 != 0) {
        return 0x8a;
      }
      uStack_22 = *(ushort *)(*(int *)(param_2 + 4) + iVar5 + 0x10);
      iVar2 = zmsg_append_bytes(param_1,2,&uStack_22);
      if (iVar2 != 0) {
        return 0x8a;
      }
      uStack_22._0_1_ =
           (byte)uVar1 & 3 | (byte)((uVar1 >> 2 & 3) << 2) | (byte)((uVar1 >> 4 & 7) << 4);
      iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
      if (iVar2 != 0) {
        return 0x8a;
      }
      uStack_22._0_1_ = (byte)(uVar1 >> 8) & 3;
      iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
      if (iVar2 != 0) {
        return 0x8a;
      }
      uStack_22._0_1_ = *(undefined1 *)(*(int *)(param_2 + 4) + iVar5 + 0x14);
      iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
      if (iVar2 != 0) {
        return 0x8a;
      }
      uStack_22 = CONCAT11(uStack_22._1_1_,*(undefined1 *)(*(int *)(param_2 + 4) + iVar5 + 0x15));
      iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
      if (iVar2 != 0) break;
      uVar7 = uVar7 + 1 & 0xff;
    }
    return 0x8a;
  }
  uStack_22 = 0;
  uVar7 = zmsg_get_length();
  af_read_le8(param_1,&uStack_22,param_2);
  af_read_le8(param_1,&uStack_22,param_2 + 1);
  af_read_le8(param_1,&uStack_22,param_2 + 2);
  af_read_le8(param_1,&uStack_22,param_2 + 3);
  if (uVar7 < uStack_22) {
_L0:
    uVar3 = 0xfe;
  }
  else {
    if ((*param_2 == '\0') && ((byte)param_2[3] != 0)) {
      pvVar4 = calloc((uint)(byte)param_2[3],0x16);
      *(void **)(param_2 + 4) = pvVar4;
      uVar6 = 0;
      if (pvVar4 == (void *)0x0) goto _L0;
      for (; uVar6 < (byte)param_2[3]; uVar6 = uVar6 + 1 & 0xff) {
        bStack_24 = 0;
        bStack_23 = 0;
        iVar2 = uVar6 * 0x16;
        af_read_bytes(param_1,&uStack_22,8,*(int *)(param_2 + 4) + iVar2);
        af_read_bytes(param_1,&uStack_22,8,*(int *)(param_2 + 4) + iVar2 + 8);
        af_read_le16(param_1,&uStack_22,*(int *)(param_2 + 4) + iVar2 + 0x10);
        af_read_le8(param_1,&uStack_22,&bStack_24);
        af_read_le8(param_1,&uStack_22,&bStack_23);
        af_read_le8(param_1,&uStack_22,*(int *)(param_2 + 4) + iVar2 + 0x14);
        af_read_le8(param_1,&uStack_22,*(int *)(param_2 + 4) + iVar2 + 0x15);
        if (uVar7 < uStack_22) goto _L0;
        *(ushort *)(*(int *)(param_2 + 4) + iVar2 + 0x12) =
             *(ushort *)(*(int *)(param_2 + 4) + iVar2 + 0x12) & 0xfffc | bStack_24 & 3;
        *(ushort *)(*(int *)(param_2 + 4) + iVar2 + 0x12) =
             *(ushort *)(*(int *)(param_2 + 4) + iVar2 + 0x12) & 0xfff3 |
             (ushort)(((int)(uint)bStack_24 >> 2 & 3U) << 2);
        *(ushort *)(*(int *)(param_2 + 4) + iVar2 + 0x12) =
             (ushort)(((int)(uint)bStack_24 >> 4 & 7U) << 4) |
             *(ushort *)(*(int *)(param_2 + 4) + iVar2 + 0x12) & 0xff8f;
        *(ushort *)(*(int *)(param_2 + 4) + iVar2 + 0x12) =
             *(ushort *)(*(int *)(param_2 + 4) + iVar2 + 0x12) & 0xfcff |
             (ushort)((bStack_23 & 3) << 8);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


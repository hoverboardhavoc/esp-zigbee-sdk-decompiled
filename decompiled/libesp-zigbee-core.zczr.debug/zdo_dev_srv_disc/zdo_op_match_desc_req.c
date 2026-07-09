/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_match_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_match_desc_req(int param_1,ushort *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  void *pvVar5;
  ushort auStack_22 [7];
  
  if ((param_1 == 0) || (param_2 == (ushort *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x1f1,
                  "zdo_op_match_desc_req","payload && req");
  }
  else {
    if (param_3 == 0) {
      auStack_22[0] = 0;
      uVar4 = zmsg_get_length();
      af_read_le16(param_1,auStack_22,param_2);
      af_read_le16(param_1,auStack_22,param_2 + 1);
      af_read_le8(param_1,auStack_22,param_2 + 2);
      uVar1 = (uint)(byte)param_2[2];
      pvVar5 = calloc(uVar1,2);
      *(void **)(param_2 + 4) = pvVar5;
      if (pvVar5 == (void *)0x0) {
        if (uVar1 != 0) {
          return 0x8a;
        }
      }
      else {
        uVar1 = 0;
      }
      for (; uVar1 < (byte)param_2[2]; uVar1 = uVar1 + 1 & 0xff) {
        af_read_le16(param_1,auStack_22,*(int *)(param_2 + 4) + uVar1 * 2);
      }
      af_read_le8(param_1,auStack_22,(int)param_2 + 5);
      iVar2 = mm_realloc(*(undefined4 *)(param_2 + 4),
                         (uint)(byte)param_2[2] + (uint)*(byte *)((int)param_2 + 5),2);
      *(int *)(param_2 + 4) = iVar2;
      if ((iVar2 == 0) && ((uint)(byte)param_2[2] + (uint)*(byte *)((int)param_2 + 5) != 0)) {
        return 0x8a;
      }
      for (uVar1 = (uint)(byte)param_2[2];
          uVar1 < (uint)(byte)param_2[2] + (uint)*(byte *)((int)param_2 + 5);
          uVar1 = uVar1 + 1 & 0xff) {
        af_read_le16(param_1,auStack_22,*(int *)(param_2 + 4) + uVar1 * 2);
      }
      if (auStack_22[0] <= uVar4) {
        return 0;
      }
      return 0xfe;
    }
    auStack_22[0] = *param_2;
    iVar2 = zmsg_append_bytes(2,auStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    auStack_22[0] = param_2[1];
    iVar2 = zmsg_append_bytes(param_1,2,auStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,(char)param_2[2]);
    iVar2 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    for (uVar1 = 0; uVar1 < (byte)param_2[2]; uVar1 = uVar1 + 1 & 0xff) {
      auStack_22[0] = *(ushort *)(*(int *)(param_2 + 4) + uVar1 * 2);
      iVar2 = zmsg_append_bytes(param_1,2,auStack_22);
      if (iVar2 != 0) {
        return 0x8a;
      }
    }
  }
  auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*(undefined1 *)((int)param_2 + 5));
  iVar2 = zmsg_append_bytes(param_1,1,auStack_22);
  if (iVar2 == 0) {
    for (uVar1 = 0; uVar1 < *(byte *)((int)param_2 + 5); uVar1 = uVar1 + 1 & 0xff) {
      auStack_22[0] = *(ushort *)(((byte)param_2[2] + uVar1) * 2 + *(int *)(param_2 + 4));
      iVar2 = zmsg_append_bytes(param_1,2,auStack_22);
      if (iVar2 != 0) {
        return 0x8a;
      }
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0x8a;
  }
  return uVar3;
}


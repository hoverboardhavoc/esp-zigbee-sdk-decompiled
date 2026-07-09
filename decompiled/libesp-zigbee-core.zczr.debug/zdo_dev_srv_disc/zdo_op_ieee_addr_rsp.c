/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_ieee_addr_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zdo_op_ieee_addr_rsp(int param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint unaff_s3;
  uint uVar4;
  ushort auStack_22 [5];
  
  if ((param_1 == 0) || (param_3 == (char *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0xb3,
                  "zdo_op_ieee_addr_rsp","payload && rsp");
  }
  else {
    if (param_4 == 0) {
      auStack_22[0] = 0;
      uVar2 = zmsg_get_length();
      af_read_le8(param_1,auStack_22,param_3);
      af_read_bytes(param_1,auStack_22,8,param_3 + 1);
      af_read_le16(param_1,auStack_22,param_3 + 10);
      if ((*param_3 == '\0') && (auStack_22[0] < uVar2)) {
        af_read_le8(param_1,auStack_22,param_3 + 0xc);
        uVar4 = (uint)(byte)param_3[0xc];
        pvVar3 = calloc(uVar4,2);
        *(void **)(param_3 + 0x10) = pvVar3;
        if ((pvVar3 == (void *)0x0) && (uVar4 != 0)) {
          return 0x8a;
        }
        if (uVar4 != 0) {
          af_read_le8(param_1,auStack_22,param_3 + 0xd);
          for (uVar4 = 0; uVar4 < (byte)param_3[0xc]; uVar4 = uVar4 + 1 & 0xff) {
            af_read_le16(param_1,auStack_22,*(int *)(param_3 + 0x10) + uVar4 * 2);
          }
        }
      }
      else {
        param_3[0xc] = '\0';
        param_3[0xd] = '\0';
        param_3[0x10] = '\0';
        param_3[0x11] = '\0';
        param_3[0x12] = '\0';
        param_3[0x13] = '\0';
      }
      if (auStack_22[0] <= uVar2) {
        return 0;
      }
      return 0xfe;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*param_3);
    iVar1 = zmsg_append_bytes(1,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    iVar1 = zmsg_append_bytes(param_1,8,param_3 + 1);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_22[0] = *(ushort *)(param_3 + 10);
    iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    if (*param_3 != '\0') {
      return 0;
    }
    unaff_s3 = 0;
    if (param_2 != 1) {
      return 0;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_3[0xc]);
    iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    if (param_3[0xc] == '\0') {
      return 0;
    }
  }
  auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_3[0xd]);
  iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
  uVar2 = unaff_s3;
  if (iVar1 == 0) {
    for (; uVar2 < (byte)param_3[0xc]; uVar2 = uVar2 + 1 & 0xff) {
      auStack_22[0] = *(ushort *)(*(int *)(param_3 + 0x10) + uVar2 * 2);
      iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
      if (iVar1 != 0) {
        return 0x8a;
      }
    }
  }
  else {
    unaff_s3 = 0x8a;
  }
  return unaff_s3;
}


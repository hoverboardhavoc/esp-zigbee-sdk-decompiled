/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_match_desc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 zdo_op_match_desc_rsp(int param_1,char *param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  uint __nmemb;
  ushort auStack_22 [7];
  
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x21c,
                  "zdo_op_match_desc_rsp","payload && rsp");
  }
  else if (param_3 != 0) {
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*param_2);
    iVar2 = zmsg_append_bytes(1,auStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    auStack_22[0] = *(ushort *)(param_2 + 2);
    iVar2 = zmsg_append_bytes(param_1,2,auStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_2[4]);
    iVar2 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    if (*param_2 == '\0') {
      if (param_2[4] == '\0') {
        return 0;
      }
      iVar2 = zmsg_append_bytes(param_1,param_2[4],*(undefined4 *)(param_2 + 8));
      if (iVar2 == 0) {
        return 0;
      }
      return 0x8a;
    }
    return 0;
  }
  auStack_22[0] = 0;
  uVar3 = zmsg_get_length();
  af_read_le8(param_1,auStack_22,param_2);
  af_read_le16(param_1,auStack_22,param_2 + 2);
  af_read_le8(param_1,auStack_22,param_2 + 4);
  if (uVar3 < auStack_22[0]) {
    uVar1 = 0xfe;
  }
  else {
    if ((*param_2 == '\0') && (__nmemb = (uint)(byte)param_2[4], __nmemb != 0)) {
      pvVar4 = calloc(__nmemb,1);
      *(void **)(param_2 + 8) = pvVar4;
      if (pvVar4 == (void *)0x0) {
        return 0x8a;
      }
      af_read_bytes(param_1,auStack_22,__nmemb,pvVar4);
    }
    else {
      param_2[8] = '\0';
      param_2[9] = '\0';
      param_2[10] = '\0';
      param_2[0xb] = '\0';
    }
    if (uVar3 < auStack_22[0]) {
      uVar1 = 0xfe;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


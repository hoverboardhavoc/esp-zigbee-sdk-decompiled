/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_bind_mgmt.o -> zdo_op_bind_and_unbind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_op_bind_and_unbind_req(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ushort auStack_22 [7];
  
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_bind_mgmt.c",0x3b,
                  "zdo_op_bind_and_unbind_req","payload && req");
  }
  else {
    if (param_3 == 0) {
      auStack_22[0] = 0;
      uVar2 = zmsg_get_length();
      af_read_bytes(param_1,auStack_22,8,param_2);
      af_read_le8(param_1,auStack_22,param_2 + 8);
      af_read_le16(param_1,auStack_22,param_2 + 10);
      af_read_le8(param_1,auStack_22,param_2 + 0xc);
      if (auStack_22[0] <= uVar2) {
        if (*(char *)(param_2 + 0xc) == '\x03') {
          af_read_bytes(param_1,auStack_22,8,param_2 + 0xe);
          af_read_le8(param_1,auStack_22,param_2 + 0x16);
          iVar1 = 0;
        }
        else if (*(char *)(param_2 + 0xc) == '\x01') {
          af_read_le16(param_1,auStack_22,param_2 + 0xe);
          iVar1 = 0;
        }
        else {
          iVar1 = 0x80;
        }
        if (auStack_22[0] <= uVar2) {
          return iVar1;
        }
      }
      return 0xfe;
    }
    iVar1 = zmsg_append_bytes(8,param_2);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*(undefined1 *)(param_2 + 8));
    iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_22[0] = *(ushort *)(param_2 + 10);
    iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*(undefined1 *)(param_2 + 0xc));
    iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    if (*(char *)(param_2 + 0xc) != '\x03') {
      if (*(char *)(param_2 + 0xc) != '\x01') {
        return 0;
      }
      auStack_22[0] = *(ushort *)(param_2 + 0xe);
      iVar1 = zmsg_append_bytes(param_1,2,auStack_22);
      if (iVar1 == 0) {
        return 0;
      }
      return 0x8a;
    }
  }
  iVar1 = zmsg_append_bytes(param_1,8,param_2 + 0xe);
  if (iVar1 == 0) {
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*(undefined1 *)(param_2 + 0x16));
    iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
    }
  }
  else {
    iVar1 = 0x8a;
  }
  return iVar1;
}


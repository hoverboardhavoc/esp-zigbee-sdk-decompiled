/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_leave_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_mgmt_leave_req(int param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  byte bStack_23;
  ushort auStack_22 [7];
  
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x12d,
                  "zdo_op_nwk_mgmt_leave_req","payload && req");
  }
  else if (param_3 != 0) {
    bVar1 = *(byte *)(param_2 + 8);
    cVar2 = *(char *)(param_2 + 9);
    iVar3 = zmsg_append_bytes(8,param_2);
    if (iVar3 != 0) {
      return 0x8a;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,(byte)((bVar1 & 1) << 6) | cVar2 << 7);
    iVar3 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar3 == 0) {
      return 0;
    }
    return 0x8a;
  }
  auStack_22[0] = 0;
  bStack_23 = 0;
  uVar4 = zmsg_get_length();
  af_read_bytes(param_1,auStack_22,8,param_2);
  af_read_le8(param_1,auStack_22,&bStack_23);
  if (uVar4 < auStack_22[0]) {
    uVar5 = 0xfe;
  }
  else {
    *(byte *)(param_2 + 8) = (byte)((int)(uint)bStack_23 >> 6) & 1;
    *(byte *)(param_2 + 9) = bStack_23 >> 7;
    uVar5 = 0;
  }
  return uVar5;
}


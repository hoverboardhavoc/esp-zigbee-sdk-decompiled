/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_ieee_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_ieee_addr_req(int param_1,ushort *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort auStack_22 [7];
  
  if ((param_1 == 0) || (param_2 == (ushort *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x98,
                  "zdo_op_ieee_addr_req","payload && req");
  }
  else if (param_3 != 0) {
    auStack_22[0] = *param_2;
    iVar1 = zmsg_append_bytes(2,auStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_22[0]._0_1_ = (char)param_2[1];
    iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar1 == 0) {
      auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*(undefined1 *)((int)param_2 + 3));
      iVar1 = zmsg_append_bytes(param_1,1,auStack_22);
      if (iVar1 == 0) {
        return 0;
      }
      return 0x8a;
    }
    return 0x8a;
  }
  auStack_22[0] = 0;
  uVar2 = zmsg_get_length();
  af_read_le16(param_1,auStack_22,param_2);
  af_read_le8(param_1,auStack_22,param_2 + 1);
  af_read_le8(param_1,auStack_22,(int)param_2 + 3);
  if (uVar2 < auStack_22[0]) {
    uVar3 = 0xfe;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


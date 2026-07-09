/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_permit_joining_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_mgmt_permit_joining_rsp(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort uStack_12;
  
  if ((param_1 == 0) || (param_2 == (undefined1 *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x177,
                  "zdo_op_nwk_mgmt_permit_joining_rsp","payload && rsp");
  }
  else if (param_3 != 0) {
    uStack_12 = CONCAT11(uStack_12._1_1_,*param_2);
    iVar1 = zmsg_append_bytes(1,&uStack_12);
    if (iVar1 == 0) {
      return 0;
    }
    return 0x8a;
  }
  uStack_12 = 0;
  uVar2 = zmsg_get_length();
  af_read_le8(param_1,&uStack_12,param_2);
  if (uVar2 < uStack_12) {
    uVar3 = 0xfe;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


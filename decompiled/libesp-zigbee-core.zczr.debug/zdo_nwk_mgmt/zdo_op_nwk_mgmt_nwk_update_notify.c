/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_nwk_update_notify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_mgmt_nwk_update_notify(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint auStack_24 [4];
  
  if ((param_1 == 0) || (param_2 == (undefined1 *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x215,
                  "zdo_op_nwk_mgmt_nwk_update_notify","payload && notify");
  }
  else if (param_3 != 0) {
    auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,*param_2);
    iVar1 = zmsg_append_bytes(1,auStack_24);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_24[0] = *(uint *)(param_2 + 4);
    iVar1 = zmsg_append_bytes(param_1,4,auStack_24);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_24[0]._0_2_ = *(undefined2 *)(param_2 + 8);
    iVar1 = zmsg_append_bytes(param_1,2,auStack_24);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_24[0] = CONCAT22(auStack_24[0]._2_2_,*(undefined2 *)(param_2 + 10));
    iVar1 = zmsg_append_bytes(param_1,2,auStack_24);
    if (iVar1 == 0) {
      auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,param_2[0xc]);
      iVar1 = zmsg_append_bytes(param_1,1,auStack_24);
      if (iVar1 != 0) {
        return 0x8a;
      }
      iVar1 = zmsg_append_bytes(param_1,param_2[0xc],param_2 + 0xd);
      if (iVar1 == 0) {
        return 0;
      }
      return 0x8a;
    }
    return 0x8a;
  }
  auStack_24[0] = auStack_24[0] & 0xffff0000;
  uVar2 = zmsg_get_length();
  af_read_le8(param_1,auStack_24,param_2);
  af_read_le32(param_1,auStack_24,param_2 + 4);
  af_read_le16(param_1,auStack_24,param_2 + 8);
  af_read_le16(param_1,auStack_24,param_2 + 10);
  af_read_le8(param_1,auStack_24,param_2 + 0xc);
  af_read_bytes(param_1,auStack_24,param_2[0xc],param_2 + 0xd);
  if (uVar2 < (auStack_24[0] & 0xffff)) {
    uVar3 = 0xfe;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


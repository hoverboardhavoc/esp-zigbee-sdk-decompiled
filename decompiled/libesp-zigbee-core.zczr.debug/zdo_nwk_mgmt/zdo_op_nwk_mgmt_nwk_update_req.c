/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_nwk_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_op_nwk_mgmt_nwk_update_req(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint auStack_24 [4];
  
  if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x1e5,
                  "zdo_op_nwk_mgmt_nwk_update_req","payload && req");
  }
  else {
    if (param_3 == 0) {
      auStack_24[0] = auStack_24[0] & 0xffff0000;
      uVar2 = zmsg_get_length();
      af_read_le32(param_1,auStack_24,param_2);
      af_read_le8(param_1,auStack_24,param_2 + 1);
      if ((byte)param_2[1] < 6) {
        af_read_le8(param_1,auStack_24,(int)param_2 + 5);
      }
      if (0xfd < (byte)param_2[1]) {
        af_read_le8(param_1,auStack_24,(int)param_2 + 6);
      }
      if ((char)param_2[1] == -1) {
        af_read_le16(param_1,auStack_24,param_2 + 2);
      }
      if ((auStack_24[0] & 0xffff) <= uVar2) {
        return 0;
      }
      return 0xfe;
    }
    auStack_24[0] = *param_2;
    iVar1 = zmsg_append_bytes(4,auStack_24);
    if (iVar1 != 0) {
      return 0x8a;
    }
    auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,(char)param_2[1]);
    iVar1 = zmsg_append_bytes(param_1,1,auStack_24);
    if (iVar1 != 0) {
      return 0x8a;
    }
    if (5 < (byte)param_2[1]) goto _L0;
  }
  auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,*(undefined1 *)((int)param_2 + 5));
  iVar1 = zmsg_append_bytes(param_1,1,auStack_24);
  if (iVar1 != 0) {
    return 0x8a;
  }
_L0:
  if (0xfd < (byte)param_2[1]) {
    auStack_24[0] = CONCAT31(auStack_24[0]._1_3_,*(undefined1 *)((int)param_2 + 6));
    iVar1 = zmsg_append_bytes(param_1,1,auStack_24);
    if (iVar1 != 0) {
      return 0x8a;
    }
  }
  if ((char)param_2[1] == -1) {
    auStack_24[0] = CONCAT22(auStack_24[0]._2_2_,(short)param_2[2]);
    iVar1 = zmsg_append_bytes(param_1,2,auStack_24);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


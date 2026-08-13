/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_leave_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_nwk_mgmt_leave_rsp(int param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  ushort uStack_12;
  
  if (param_1 == 0) {
    param_2 = (undefined1 *)__assert_func(0,0,0);
  }
  else if (param_3 == 0) {
    uStack_12 = 0;
    uVar1 = zmsg_get_length();
    af_read_le8_isra_0(param_1,&uStack_12,param_2);
    if (uStack_12 <= uVar1) {
      return 0;
    }
    return 0xfe;
  }
  iVar2 = zmsg_append_u8(*param_2);
  if (iVar2 == 0) {
    return 0;
  }
  return 0x8a;
}


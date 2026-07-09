/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_op_node_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_op_node_desc_req(int param_1,undefined2 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  ushort uStack_12;
  
  if (param_1 == 0) {
    param_2 = (undefined2 *)__assert_func(0,0,0);
  }
  else if (param_3 == 0) {
    uStack_12 = 0;
    uVar1 = zmsg_get_length();
    af_read_le16_isra_0(param_1,&uStack_12,param_2);
    if (uStack_12 <= uVar1) {
      return 0;
    }
    return 0xfe;
  }
  iVar2 = zmsg_append_le16(*param_2);
  if (iVar2 == 0) {
    return 0;
  }
  return 0x8a;
}


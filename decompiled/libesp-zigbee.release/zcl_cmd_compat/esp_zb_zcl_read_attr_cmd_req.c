/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_read_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_read_attr_cmd_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_34 [28];
  undefined1 uStack_18;
  undefined4 uStack_14;
  
  memset(auStack_34,0,0x24);
  if (param_1 != 0) {
    convert_to_ezb_general_cmd_ctrl(auStack_34,param_1);
    uStack_18 = *(undefined1 *)(param_1 + 0x12);
    uStack_14 = *(undefined4 *)(param_1 + 0x14);
    iVar1 = ezb_zcl_read_attr_cmd_req(auStack_34);
    if (iVar1 == 0) {
      uVar2 = zcl_get_current_tsn();
      return uVar2;
    }
  }
  return 0xff;
}


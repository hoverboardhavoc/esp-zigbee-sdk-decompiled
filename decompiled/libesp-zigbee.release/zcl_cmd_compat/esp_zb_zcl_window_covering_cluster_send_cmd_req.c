/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_window_covering_cluster_send_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_window_covering_cluster_send_cmd_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 auStack_30 [24];
  uint uStack_18;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  memset(auStack_30,0,0x20);
  if (param_1 == 0) {
    return 0xff;
  }
  convert_to_ezb_specific_cmd_ctrl(auStack_30,param_1);
  uStack_18 = (uint)*(byte *)(param_1 + 0x10);
  puVar4 = *(undefined1 **)(param_1 + 0xc);
  if (puVar4 == (undefined1 *)0x0) goto _L0;
  if (uStack_18 == 7) {
_L0:
    uStack_14 = *puVar4;
    uStack_13 = puVar4[1];
  }
  else {
    if (uStack_18 < 8) {
      if (uStack_18 == 4) goto _L0;
      uVar3 = 5;
    }
    else {
      uVar3 = 8;
    }
    if (uStack_18 == uVar3) {
      uStack_14 = *puVar4;
    }
  }
_L0:
  iVar1 = ezb_zcl_window_covering_movement_cmd_req(auStack_30);
  if (iVar1 != 0) {
    return 0xff;
  }
  uVar2 = zcl_get_current_tsn();
  return uVar2;
}


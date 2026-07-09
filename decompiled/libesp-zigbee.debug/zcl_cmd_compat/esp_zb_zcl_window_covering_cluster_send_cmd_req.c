/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_window_covering_cluster_send_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_window_covering_cluster_send_cmd_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    esp_log(0x11,"ZCL_CMD_COMPAT","%s(%d): Invalid Argument",
            "esp_zb_zcl_window_covering_cluster_send_cmd_req",0x5fb);
    return 0xff;
  }
  convert_to_ezb_specific_cmd_ctrl(&local_30,param_1);
  uStack_18 = (uint)*(byte *)(param_1 + 0x10);
  puVar3 = *(undefined2 **)(param_1 + 0xc);
  if (puVar3 == (undefined2 *)0x0) goto _L0;
  if (uStack_18 == 7) {
_L0:
    uStack_14 = CONCAT22(uStack_14._2_2_,*puVar3);
  }
  else {
    if (uStack_18 < 8) {
      if (uStack_18 == 4) goto _L0;
      if (uStack_18 != 5) goto _L0;
    }
    else if (uStack_18 != 8) goto _L0;
    uStack_14 = CONCAT31(uStack_14._1_3_,*(undefined1 *)puVar3);
  }
_L0:
  iVar1 = ezb_zcl_window_covering_movement_cmd_req(&local_30);
  if (iVar1 == 0) {
    uVar2 = zcl_get_current_tsn();
  }
  else {
    uVar2 = 0xff;
  }
  return uVar2;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_custom_cluster_cmd_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_custom_cluster_cmd_resp(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    esp_log(0x11,"ZCL_CMD_COMPAT","%s(%d): Invalid Argument","esp_zb_zcl_custom_cluster_cmd_resp",
            0x65c);
    uVar2 = 0xff;
  }
  else {
    convert_esp_custom_cmd_to_ezb(&uStack_34,param_1);
    iVar1 = ezb_zcl_custom_cmd_req(&uStack_34);
    if (iVar1 == 0) {
      uVar2 = zcl_get_current_tsn();
    }
    else {
      uVar2 = 0xff;
    }
  }
  return uVar2;
}


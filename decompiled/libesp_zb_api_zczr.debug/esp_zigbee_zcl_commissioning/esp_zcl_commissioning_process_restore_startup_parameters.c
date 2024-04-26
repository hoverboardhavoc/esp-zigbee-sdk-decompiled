/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_process_restore_startup_parameters
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zcl_commissioning_process_restore_startup_parameters(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_24;
  ushort uStack_20;
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_24 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  _uStack_20 = CONCAT22(*(undefined2 *)(param_2 + 0x18),(ushort)*(byte *)(param_2 + 0x17));
  uStack_14 = 0x81;
  iVar1 = zb_buf_begin_func();
  uStack_18 = CONCAT31(uStack_18._1_3_,*(undefined1 *)(iVar1 + 1));
  uStack_1c = 1;
  esp_zb_core_action_handler_schedule(0x1b,&uStack_24);
  if (uStack_14 == 0x81) {
    uVar2 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_L0,uVar2,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                  *(undefined1 *)(param_2 + 0x1c));
  }
  esp_zcl_commissioning_srv_send_response(param_1,param_2,uStack_14 & 0xff,0);
  return 1;
}


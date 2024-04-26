/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_process_reset_startup_parameters
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zcl_commissioning_process_reset_startup_parameters(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined4 uStack_38;
  ushort uStack_34;
  undefined2 uStack_32;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  byte bStack_24;
  byte bStack_23;
  
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  _uStack_34 = CONCAT22(*(undefined2 *)(param_2 + 0x18),(ushort)*(byte *)(param_2 + 0x17));
  pbVar4 = (byte *)zb_buf_begin_func();
  bVar1 = *pbVar4;
  bVar2 = pbVar4[1];
  bStack_24 = bVar1;
  bStack_23 = bVar2;
  if ((bVar1 & 1) != 0) {
    esp_zcl_commissioning_reset_startup_parameters();
  }
  if ((bVar1 & 2) == 0) {
    if ((bVar1 & 1) == 0) {
      if ((bVar1 & 4) == 0) {
        uStack_30 = 3;
      }
      else {
        uStack_30 = 2;
      }
      uStack_2c = CONCAT31(uStack_2c._1_3_,bVar2);
    }
  }
  else {
    uStack_30 = 4;
  }
  esp_zb_core_action_handler_schedule(0x1b,&uStack_38);
  uVar3 = esp_err_to_zcl_status();
  esp_zcl_commissioning_srv_send_response(param_1,param_2,uVar3,0);
  return 1;
}


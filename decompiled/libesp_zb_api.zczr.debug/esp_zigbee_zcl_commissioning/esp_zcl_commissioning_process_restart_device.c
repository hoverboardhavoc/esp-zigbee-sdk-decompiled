/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_process_restart_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zcl_commissioning_process_restart_device(undefined4 param_1,int param_2)

{
  undefined3 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uStack_1c;
  ushort uStack_18;
  undefined2 uStack_16;
  uint uStack_14;
  
  uStack_1c = 0;
  uStack_14 = 0;
  _uStack_18 = CONCAT22(*(undefined2 *)(param_2 + 0x18),(ushort)*(byte *)(param_2 + 0x17));
  puVar1 = (undefined3 *)zb_buf_begin_func();
  uStack_14 = CONCAT13(uStack_14._3_1_,*puVar1);
  iVar2 = esp_zb_has_core_action_handler();
  if (iVar2 != 0) {
    esp_zb_core_action_handler_schedule(0x1a,&uStack_1c);
  }
  iVar2 = esp_zcl_commissioning_check_startup_parameters();
  if (iVar2 == 0) {
    DAT_00011778 = (uStack_14 >> 8 & 0xff) * 1000;
    DAT_0001177c = 0;
    uVar4 = zb_random_jitter();
    uVar4 = uVar4 / (0xffffffff / ((uStack_14 >> 0x10 & 0xff) * 0x50)) + DAT_00011778;
    DAT_0001177c = (uint)(uVar4 < DAT_00011778) + DAT_0001177c;
    DAT_00011780 = (byte)uStack_14 & 7;
    DAT_00011781 = (byte)(uStack_14 >> 3) & 1;
    DAT_00011778 = uVar4;
    esp_zcl_commissioning_srv_send_response
              (param_1,param_2,0,esp_zcl_commissioning_process_restart_device_continue);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_COMMISSIONING","E (%lu) %s: Invalid Startup Parameter Set\n",uVar3,
            "ESP_ZIGBEE_ZCL_COMMISSIONING");
    esp_zcl_commissioning_srv_send_response(param_1,param_2,1,0);
  }
  return 1;
}


/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_process_restart_device
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
    DAT_000117f8 = (uStack_14 >> 8 & 0xff) * 1000;
    DAT_000117fc = 0;
    uVar4 = zb_random_jitter();
    uVar4 = uVar4 / (0xffffffff / ((uStack_14 >> 0x10 & 0xff) * 0x50)) + DAT_000117f8;
    DAT_000117fc = (uint)(uVar4 < DAT_000117f8) + DAT_000117fc;
    DAT_00011800 = (byte)uStack_14 & 7;
    DAT_00011801 = (byte)(uStack_14 >> 3) & 1;
    DAT_000117f8 = uVar4;
    esp_zcl_commissioning_srv_send_response
              (param_1,param_2,0,esp_zcl_commissioning_process_restart_device_continue);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_L0,uVar3,"ESP_ZIGBEE_ZCL_COMMISSIONING");
    esp_zcl_commissioning_srv_send_response(param_1,param_2,1,0);
  }
  return 1;
}


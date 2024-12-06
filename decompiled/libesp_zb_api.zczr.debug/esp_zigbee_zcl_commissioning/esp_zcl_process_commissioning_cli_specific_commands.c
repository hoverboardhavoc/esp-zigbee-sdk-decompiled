/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_process_commissioning_cli_specific_commands
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zcl_process_commissioning_cli_specific_commands(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [24];
  short sStack_18;
  char cStack_13;
  
  if (param_1 == 0xff) {
    iVar1 = zb_zcl_get_ctx();
    *(undefined1 **)(iVar1 + 0x2e0) = s_commissioning_client_cmd_list;
    uVar2 = 1;
  }
  else {
    iVar1 = zb_zcl_basic_message_create(auStack_30);
    if (iVar1 == 0) {
      if (sStack_18 == 0x15) {
        if (cStack_13 != '\x01') {
          return 0;
        }
      }
      else {
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
                  ,0x2a4);
      }
      uVar2 = esp_zcl_process_commissioning_cli_commands(param_1,auStack_30);
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_L0,uVar2,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                    "esp_zcl_process_commissioning_cli_specific_commands",0x2a2);
      uVar2 = 1;
    }
  }
  return uVar2;
}


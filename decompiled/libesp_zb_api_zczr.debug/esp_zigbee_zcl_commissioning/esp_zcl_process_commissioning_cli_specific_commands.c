/*
 * Last changed at upstream commit f681c92f221e08b8a4008d1df363fb1f9960ae64
 * https://github.com/espressif/esp-zigbee-sdk/commit/f681c92f221e08b8a4008d1df363fb1f9960ae64
 * Upstream date: 2024-04-30 13:18:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.1(ce7ce7c1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_process_commissioning_cli_specific_commands
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
    *(undefined1 **)(iVar1 + 0x240) = s_commissioning_client_cmd_list;
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


/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_process_commissioning_srv_commands
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zcl_process_commissioning_srv_commands(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(param_1 + 0x1c);
  if (bVar1 == 2) {
    uVar2 = esp_zcl_commissioning_process_restore_startup_parameters();
    return uVar2;
  }
  if (bVar1 < 3) {
    if (bVar1 == 0) {
      uVar2 = esp_zcl_commissioning_process_restart_device();
      return uVar2;
    }
    if (bVar1 == 1) {
      uVar2 = esp_zcl_commissioning_process_save_startup_parameters();
      return uVar2;
    }
  }
  else if (bVar1 == 3) {
    uVar2 = esp_zcl_commissioning_process_reset_startup_parameters();
    return uVar2;
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(2,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_L0,uVar2,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                *(undefined1 *)(param_1 + 0x1c));
  return 0;
}


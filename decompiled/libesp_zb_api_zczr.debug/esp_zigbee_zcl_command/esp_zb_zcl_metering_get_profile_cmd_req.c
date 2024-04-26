/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_metering_get_profile_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_metering_get_profile_cmd_req(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar3,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_metering_get_profile_cmd_req",0x6a1,
                  "esp_zb_zcl_metering_get_profile_cmd_req");
    pcVar2 = (char *)zb_zcl_get_ctx();
    *pcVar2 = *pcVar2 + '\x01';
  }
  else {
    uStack_18 = (undefined1)*(undefined4 *)(param_1 + 0x10);
    uVar3 = *(undefined4 *)(param_1 + 0x14);
    uStack_17 = (undefined1)uVar3;
    uStack_16 = (undefined1)((uint)uVar3 >> 8);
    uStack_15 = (undefined1)((uint)uVar3 >> 0x10);
    uStack_14 = (undefined1)((uint)uVar3 >> 0x18);
    uStack_13 = *(undefined1 *)(param_1 + 0x18);
    pcVar4 = zb_zcl_cmd_send_status_cb;
    if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
      pcVar4 = zb_zcl_cmd_send_status_handler;
    }
    zb_zcl_metering_send_cmd_get_profile
              (iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),&uStack_18,pcVar4);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}


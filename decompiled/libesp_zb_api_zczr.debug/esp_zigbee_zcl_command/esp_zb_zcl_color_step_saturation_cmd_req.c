/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_color_step_saturation_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_color_step_saturation_cmd_req(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  code *pcVar5;
  
  iVar1 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar3,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_color_step_saturation_cmd_req",0x2fa,*(undefined1 *)(param_1 + 9));
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar3,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_color_step_saturation_cmd_req",0x2fb,
                    "esp_zb_zcl_color_step_saturation_cmd_req");
      pcVar4 = (char *)zb_zcl_get_ctx();
      *pcVar4 = *pcVar4 + '\x01';
    }
    else {
      pcVar5 = zb_zcl_cmd_send_status_cb;
      if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
        pcVar5 = zb_zcl_cmd_send_status_handler;
      }
      zb_zcl_color_control_send_step_saturation_req
                (iVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar1 + 1),0,pcVar5);
      zb_zcl_frame_get_sequence_number(iVar2);
    }
  }
  return;
}


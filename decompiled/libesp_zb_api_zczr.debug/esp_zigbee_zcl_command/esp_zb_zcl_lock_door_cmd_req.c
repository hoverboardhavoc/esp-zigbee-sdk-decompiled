/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_lock_door_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_lock_door_cmd_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_lock_door_cmd_req",0x41f,*(undefined1 *)(param_1 + 9));
    pcVar3 = (char *)zb_zcl_get_ctx();
    *pcVar3 = *pcVar3 + '\x01';
  }
  else {
    iVar1 = zb_buf_get_out_func();
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar2,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_lock_door_cmd_req",0x420,"esp_zb_zcl_lock_door_cmd_req");
      pcVar3 = (char *)zb_zcl_get_ctx();
      *pcVar3 = *pcVar3 + '\x01';
    }
    else {
      uVar2 = zb_zcl_start_command_header(1,0,0,0);
      zb_zcl_finish_and_send_packet
                (iVar1,uVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),0x104,0x101);
      zb_zcl_frame_get_sequence_number(iVar1);
    }
  }
  return;
}


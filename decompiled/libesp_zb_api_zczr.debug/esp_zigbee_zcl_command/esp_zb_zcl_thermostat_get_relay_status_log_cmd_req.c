/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_thermostat_get_relay_status_log_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_thermostat_get_relay_status_log_cmd_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined2 uVar4;
  
  iVar1 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar1 == 0) {
    uVar4 = 0x104;
  }
  else {
    uVar4 = *(undefined2 *)(iVar1 + 1);
  }
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_thermostat_get_relay_status_log_cmd_req",0x7c0,
                  "esp_zb_zcl_thermostat_get_relay_status_log_cmd_req");
    pcVar3 = (char *)zb_zcl_get_ctx();
    *pcVar3 = *pcVar3 + '\x01';
  }
  else {
    uVar2 = zb_zcl_start_command_header(0x11,0,4,0);
    zb_zcl_finish_and_send_packet
              (iVar1,uVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar4,0x201);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}


/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_thermostat_setpoint_raise_lower_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_thermostat_setpoint_raise_lower_cmd_req(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined2 uVar5;
  
  iVar1 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar1 == 0) {
    uVar5 = 0x104;
  }
  else {
    uVar5 = *(undefined2 *)(iVar1 + 1);
  }
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar3,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_thermostat_setpoint_raise_lower_cmd_req",0x710,
                  "esp_zb_zcl_thermostat_setpoint_raise_lower_cmd_req");
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    puVar2 = (undefined1 *)zb_zcl_start_command_header(1,0,0,0);
    *puVar2 = *(undefined1 *)(param_1 + 0x10);
    puVar2[1] = *(undefined1 *)(param_1 + 0x11);
    zb_zcl_finish_and_send_packet
              (iVar1,puVar2 + 2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar5,0x201);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}


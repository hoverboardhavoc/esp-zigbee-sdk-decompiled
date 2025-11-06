/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_alarms_get_alarm_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_alarms_get_alarm_cmd_req(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined2 uVar5;
  
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): Invalid argument\n",uVar3,
            "ESP_ZIGBEE_COMMAND","esp_zb_zcl_alarms_get_alarm_cmd_req",0x8e5);
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    iVar1 = zb_buf_get_out_func();
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No I/O buffer for %s\n",uVar3,
              "ESP_ZIGBEE_COMMAND","esp_zb_zcl_alarms_get_alarm_cmd_req",0x8e6,
              "esp_zb_zcl_alarms_get_alarm_cmd_req");
      pcVar4 = (char *)zb_zcl_get_ctx();
      *pcVar4 = *pcVar4 + '\x01';
    }
    else {
      iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
      if (iVar2 == 0) {
        uVar5 = 0x104;
      }
      else {
        uVar5 = *(undefined2 *)(iVar2 + 1);
      }
      uVar3 = zb_zcl_start_command_header(iVar1,1,0,2,0);
      zb_zcl_finish_and_send_packet
                (iVar1,uVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),uVar5,9);
      zb_zcl_frame_get_sequence_number(iVar1);
    }
  }
  return;
}


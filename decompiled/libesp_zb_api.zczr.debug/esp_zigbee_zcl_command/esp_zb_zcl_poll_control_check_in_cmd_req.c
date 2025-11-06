/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_poll_control_check_in_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_poll_control_check_in_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  
  if (param_1 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): Invalid argument\n",uVar6,
            "ESP_ZIGBEE_COMMAND","esp_zb_zcl_poll_control_check_in_cmd_req",0x876);
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar6 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No I/O buffer for %s\n",uVar6,
              "ESP_ZIGBEE_COMMAND","esp_zb_zcl_poll_control_check_in_cmd_req",0x877,
              "esp_zb_zcl_poll_control_check_in_cmd_req");
      pcVar5 = (char *)zb_zcl_get_ctx();
      *pcVar5 = *pcVar5 + '\x01';
    }
    else {
      iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
      if (iVar3 == 0) {
        uVar7 = 0x104;
      }
      else {
        uVar7 = *(undefined2 *)(iVar3 + 1);
      }
      puVar4 = (undefined1 *)zb_buf_reuse_func(iVar2);
      *puVar4 = 0x19;
      pcVar5 = (char *)zb_zcl_get_ctx();
      cVar1 = *pcVar5;
      *pcVar5 = cVar1 + '\x01';
      puVar4[1] = cVar1;
      puVar4[2] = 0;
      zb_zcl_finish_and_send_packet
                (iVar2,puVar4 + 3,param_1,*(undefined1 *)(param_1 + 0xc),
                 *(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9),uVar7,0x20);
      zb_zcl_frame_get_sequence_number(iVar2);
    }
  }
  return;
}


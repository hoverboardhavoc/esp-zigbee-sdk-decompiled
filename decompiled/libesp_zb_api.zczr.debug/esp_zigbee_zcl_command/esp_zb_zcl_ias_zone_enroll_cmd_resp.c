/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_ias_zone_enroll_cmd_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_ias_zone_enroll_cmd_resp(int param_1)

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
    esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No I/O buffer for %s\n",uVar3,
            "ESP_ZIGBEE_COMMAND","esp_zb_zcl_ias_zone_enroll_cmd_resp",0x571,
            "esp_zb_zcl_ias_zone_enroll_cmd_resp");
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    puVar2 = (undefined1 *)zb_zcl_start_command_header(1,0,0,0);
    *puVar2 = *(undefined1 *)(param_1 + 0x10);
    puVar2[1] = *(undefined1 *)(param_1 + 0x11);
    zb_zcl_finish_and_send_packet
              (iVar1,puVar2 + 2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar5,0x500);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}


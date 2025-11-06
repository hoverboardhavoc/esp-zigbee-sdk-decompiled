/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_window_covering_cluster_send_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_window_covering_cluster_send_cmd_req(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar7 = 0x104;
  }
  else {
    uVar7 = *(undefined2 *)(iVar2 + 1);
  }
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_COMMAND","E (%lu) %s: %s(%d): No I/O buffer for %s\n",uVar4,
            "ESP_ZIGBEE_COMMAND","esp_zb_zcl_window_covering_cluster_send_cmd_req",0x6c1,
            "esp_zb_zcl_window_covering_cluster_send_cmd_req");
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    puVar3 = (undefined1 *)zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x14),0);
    bVar1 = *(byte *)(param_1 + 0x14);
    if ((bVar1 == 4) || (bVar1 == 7)) {
      puVar6 = *(undefined1 **)(param_1 + 0x10);
      *puVar3 = *puVar6;
      puVar3[1] = puVar6[1];
      puVar3 = puVar3 + 2;
    }
    else if ((bVar1 == 5) || (bVar1 == 8)) {
      *puVar3 = **(undefined1 **)(param_1 + 0x10);
      puVar3 = puVar3 + 1;
    }
    else if (2 < bVar1) {
      uVar4 = esp_log_timestamp();
      esp_log(3,"ESP_ZIGBEE_COMMAND","I (%lu) %s: Invalid command id: %d\n",uVar4,
              "ESP_ZIGBEE_COMMAND",*(undefined1 *)(param_1 + 0x14));
    }
    zb_zcl_finish_and_send_packet
              (iVar2,puVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar7,0x102);
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}


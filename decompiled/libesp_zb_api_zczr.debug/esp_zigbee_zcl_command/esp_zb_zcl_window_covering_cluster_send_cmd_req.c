/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_window_covering_cluster_send_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_window_covering_cluster_send_cmd_req(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_window_covering_cluster_send_cmd_req",0x572,
                  *(undefined1 *)(param_1 + 9));
    pcVar6 = (char *)zb_zcl_get_ctx();
    *pcVar6 = *pcVar6 + '\x01';
  }
  else {
    iVar3 = zb_buf_get_out_func();
    if (iVar3 == 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar5,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_window_covering_cluster_send_cmd_req",0x573,
                    "esp_zb_zcl_window_covering_cluster_send_cmd_req");
      pcVar6 = (char *)zb_zcl_get_ctx();
      *pcVar6 = *pcVar6 + '\x01';
    }
    else {
      puVar4 = (undefined1 *)zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x16),0);
      bVar1 = *(byte *)(param_1 + 0x16);
      if ((bVar1 == 4) || (bVar1 == 7)) {
        puVar7 = *(undefined1 **)(param_1 + 0x10);
        *puVar4 = *puVar7;
        puVar4[1] = puVar7[1];
        puVar4 = puVar4 + 2;
      }
      else if ((bVar1 == 5) || (bVar1 == 8)) {
        *puVar4 = **(undefined1 **)(param_1 + 0x10);
        puVar4 = puVar4 + 1;
      }
      else if (2 < bVar1) {
        uVar5 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_COMMAND",&_L0,uVar5,"ESP_ZIGBEE_COMMAND",
                      *(undefined1 *)(param_1 + 0x16));
      }
      zb_zcl_finish_and_send_packet
                (iVar3,puVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar2 + 1),
                 *(undefined2 *)(param_1 + 0x14));
      zb_zcl_frame_get_sequence_number(iVar3);
    }
  }
  return;
}


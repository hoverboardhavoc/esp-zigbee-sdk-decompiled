/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
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
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar4,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_window_covering_cluster_send_cmd_req",0x6c2,
                  "esp_zb_zcl_window_covering_cluster_send_cmd_req");
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    puVar3 = (undefined1 *)zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x16),0);
    bVar1 = *(byte *)(param_1 + 0x16);
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
      esp_log_write(3,"ESP_ZIGBEE_COMMAND",&_L0,uVar4,"ESP_ZIGBEE_COMMAND",
                    *(undefined1 *)(param_1 + 0x16));
    }
    zb_zcl_finish_and_send_packet
              (iVar2,puVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar7,*(undefined2 *)(param_1 + 0x14));
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}


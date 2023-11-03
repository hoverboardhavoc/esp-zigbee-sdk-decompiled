/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_window_covering_cluster_send_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_window_covering_cluster_send_cmd_req(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC4,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_window_covering_cluster_send_cmd_req",0x3e3);
  }
  else {
    uVar2 = zb_buf_get_out_func();
    puVar3 = (undefined1 *)zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x16),0);
    bVar1 = *(byte *)(param_1 + 0x16);
    if ((bVar1 == 4) || (bVar1 == 7)) {
      puVar5 = *(undefined1 **)(param_1 + 0x10);
      *puVar3 = *puVar5;
      puVar3[1] = puVar5[1];
      puVar3 = puVar3 + 2;
    }
    else if ((bVar1 == 5) || (bVar1 == 8)) {
      *puVar3 = **(undefined1 **)(param_1 + 0x10);
      puVar3 = puVar3 + 1;
    }
    else if (2 < bVar1) {
      uVar4 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_COMMAND",&_LC5,uVar4,"ESP_ZIGBEE_COMMAND",
                    *(undefined1 *)(param_1 + 0x16));
    }
    zb_zcl_finish_and_send_packet
              (uVar2,puVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x14));
  }
  return;
}


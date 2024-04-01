/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_touchlink.o -> esp_zb_touchlink_send_get_endpoint_list_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_touchlink_send_get_endpoint_list_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_TOUCHLINK",&_LC1,uVar5,"ESP_ZIGBEE_TOUCHLINK",
                  "esp_zb_touchlink_send_get_endpoint_list_cmd_req",0x72);
  }
  else {
    puVar3 = (undefined1 *)zb_buf_reuse_func();
    *puVar3 = 0x11;
    pcVar4 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar4;
    *pcVar4 = cVar1 + '\x01';
    puVar3[1] = cVar1;
    puVar3[2] = 0x42;
    puVar3[3] = *(undefined1 *)(param_1 + 10);
    zb_zcl_finish_and_send_packet
              (iVar2,puVar3 + 4,param_1,2,*(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9),
               0xc05e,0x1000);
  }
  return;
}


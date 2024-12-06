/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_price_get_scheduled_prices_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_price_get_scheduled_prices_cmd_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  code *pcVar4;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_price_get_scheduled_prices_cmd_req",0x820,
                  "esp_zb_zcl_price_get_scheduled_prices_cmd_req");
    pcVar3 = (char *)zb_zcl_get_ctx();
    *pcVar3 = *pcVar3 + '\x01';
  }
  else {
    uStack_18 = *(undefined4 *)(param_1 + 0x10);
    uStack_14 = *(undefined1 *)(param_1 + 0x14);
    pcVar4 = zb_zcl_cmd_send_status_cb;
    if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
      pcVar4 = zb_zcl_cmd_send_status_handler;
    }
    zb_zcl_price_send_cmd_get_scheduled_prices
              (iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),&uStack_18,pcVar4);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}


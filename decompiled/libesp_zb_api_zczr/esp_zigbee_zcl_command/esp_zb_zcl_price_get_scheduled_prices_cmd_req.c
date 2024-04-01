/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_price_get_scheduled_prices_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_price_get_scheduled_prices_cmd_req(int param_1)

{
  int iVar1;
  char *pcVar2;
  code *pcVar3;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    pcVar2 = (char *)zb_zcl_get_ctx();
    *pcVar2 = *pcVar2 + '\x01';
  }
  else {
    uStack_18 = *(undefined4 *)(param_1 + 0x10);
    uStack_14 = *(undefined1 *)(param_1 + 0x14);
    pcVar3 = zb_zcl_cmd_send_status_cb;
    if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
      pcVar3 = zb_zcl_cmd_send_status_handler;
    }
    zb_zcl_price_send_cmd_get_scheduled_prices
              (*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),&uStack_18,pcVar3);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}


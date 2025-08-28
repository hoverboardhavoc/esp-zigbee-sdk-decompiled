/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_drlc_cancel_all_load_control_events_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_drlc_cancel_all_load_control_events_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC5,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_drlc_cancel_all_load_control_events_req",0x82c,
                  "esp_zb_zcl_drlc_cancel_all_load_control_events_req");
    pcVar3 = (char *)zb_zcl_get_ctx();
    *pcVar3 = *pcVar3 + '\x01';
  }
  else {
    zb_zcl_send_cmd(iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),1,
                    *(undefined1 *)(param_1 + 9),param_1 + 0x10,1);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}


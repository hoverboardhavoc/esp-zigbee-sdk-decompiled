/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_metering_request_fast_poll_mode_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_metering_request_fast_poll_mode_cmd_req(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  uVar1 = zb_buf_get_out_func();
  uStack_14 = *(undefined1 *)(param_1 + 0x10);
  uStack_13 = *(undefined1 *)(param_1 + 0x11);
  pcVar2 = zb_zcl_cmd_send_status_cb;
  if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
    pcVar2 = zb_zcl_cmd_send_status_handler;
  }
  zb_zcl_metering_send_cmd_request_fast_poll_mode
            (uVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),&uStack_14,pcVar2);
  zb_zcl_frame_get_sequence_number(uVar1);
  return;
}


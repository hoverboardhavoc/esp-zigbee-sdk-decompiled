/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_metering_request_fast_poll_mode_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_metering_request_fast_poll_mode_cmd_req(int param_1)

{
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  zb_buf_get_out_func();
  uStack_14 = *(undefined1 *)(param_1 + 0x10);
  uStack_13 = *(undefined1 *)(param_1 + 0x11);
  zb_zcl_metering_send_cmd_request_fast_poll_mode
            (param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),&uStack_14,0);
  return;
}


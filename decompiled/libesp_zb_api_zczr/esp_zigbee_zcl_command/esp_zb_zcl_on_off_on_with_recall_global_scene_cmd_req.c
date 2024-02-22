/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_on_off_on_with_recall_global_scene_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_on_off_on_with_recall_global_scene_cmd_req(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = zb_buf_get_out_func();
  uVar2 = zb_zcl_start_command_header(1,0,0x41,0);
  zb_zcl_finish_and_send_packet
            (uVar1,uVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,6);
  zb_zcl_frame_get_sequence_number(uVar1);
  return;
}


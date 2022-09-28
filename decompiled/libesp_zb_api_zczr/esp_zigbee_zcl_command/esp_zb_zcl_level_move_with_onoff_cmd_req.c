/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_level_move_with_onoff_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_level_move_with_onoff_cmd_req(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = zb_buf_get_out_func();
  puVar2 = (undefined1 *)zb_zcl_start_command_header(1,0,5,0);
  *puVar2 = *(undefined1 *)(param_1 + 0x10);
  puVar2[1] = *(undefined1 *)(param_1 + 0x11);
  zb_zcl_finish_and_send_packet
            (uVar1,puVar2 + 2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,8);
  return;
}


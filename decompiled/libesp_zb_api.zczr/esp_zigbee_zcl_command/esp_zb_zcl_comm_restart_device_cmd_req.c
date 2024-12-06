/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_comm_restart_device_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_comm_restart_device_cmd_req(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    pcVar2 = (char *)zb_zcl_get_ctx();
    *pcVar2 = *pcVar2 + '\x01';
  }
  else {
    uStack_14 = *(undefined1 *)(param_1 + 0x10);
    uStack_13 = *(undefined1 *)(param_1 + 0x11);
    uStack_12 = *(undefined1 *)(param_1 + 0x12);
    zb_zcl_send_cmd(*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),0,
                    *(undefined1 *)(param_1 + 9),&uStack_14,3);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}


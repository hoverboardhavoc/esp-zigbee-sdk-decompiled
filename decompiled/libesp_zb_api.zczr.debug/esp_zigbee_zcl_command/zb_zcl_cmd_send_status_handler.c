/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> zb_zcl_cmd_send_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_cmd_send_status_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar2 = (undefined4 *)zb_buf_get_tail_func(0x10);
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_20 = zb_ret_to_esp_err(*puVar2);
  uVar1 = zb_zcl_frame_get_sequence_number(param_1);
  uStack_18 = *(undefined4 *)((int)puVar2 + 6);
  uStack_14 = *(undefined4 *)((int)puVar2 + 10);
  uStack_1c = CONCAT13(*(undefined1 *)((int)puVar2 + 5),
                       CONCAT12(*(undefined1 *)((int)puVar2 + 0xe),
                                CONCAT11(*(undefined1 *)(puVar2 + 1),uVar1)));
  if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
    local_30 = uStack_20;
    uStack_2c = uStack_1c;
    uStack_28 = uStack_18;
    uStack_24 = uStack_14;
    (*zb_zcl_cmd_send_status_cb)(&local_30);
  }
  zb_buf_free_func(param_1);
  return;
}


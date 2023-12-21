/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> zb_zcl_cmd_send_status_handler
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
  uStack_28 = *(undefined4 *)((int)puVar2 + 6);
  uStack_24 = *(undefined4 *)((int)puVar2 + 10);
  uStack_1c = CONCAT13(*(undefined1 *)((int)puVar2 + 5),
                       CONCAT12(*(undefined1 *)((int)puVar2 + 0xe),
                                CONCAT11(*(undefined1 *)(puVar2 + 1),uVar1)));
  if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
    local_30 = uStack_20;
    uStack_2c = uStack_1c;
    uStack_18 = uStack_28;
    uStack_14 = uStack_24;
    (*zb_zcl_cmd_send_status_cb)(&local_30);
  }
  return;
}


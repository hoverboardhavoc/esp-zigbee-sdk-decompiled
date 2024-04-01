/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> zb_zcl_cmd_send_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_cmd_send_status_handler(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined1 auStack_30 [16];
  undefined4 uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 auStack_19 [13];
  
  puVar2 = (undefined4 *)zb_buf_get_tail_func(0x10);
  uStack_20 = zb_ret_to_esp_err(*puVar2);
  uStack_1c = zb_zcl_frame_get_sequence_number(param_1);
  uStack_1b = *(undefined1 *)(puVar2 + 1);
  uStack_1a = *(undefined1 *)((int)puVar2 + 0xe);
  memcpy(auStack_19,(void *)((int)puVar2 + 5),9);
  pcVar1 = zb_zcl_cmd_send_status_cb;
  if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
    memcpy(auStack_30,&uStack_20,0x10);
    (*pcVar1)(auStack_30);
  }
  zb_buf_free_func(param_1);
  return;
}


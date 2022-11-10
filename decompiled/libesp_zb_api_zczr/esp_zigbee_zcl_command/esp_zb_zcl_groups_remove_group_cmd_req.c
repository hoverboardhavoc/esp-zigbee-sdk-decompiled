/*
 * Last changed at upstream commit 6f86421a4970072ce8039b9d5be911c385f38303
 * https://github.com/espressif/esp-zigbee-sdk/commit/6f86421a4970072ce8039b9d5be911c385f38303
 * Upstream date: 2022-11-10 11:13:02 +0800
 * Upstream subject: examples: apply new signal handler API function
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_groups_remove_group_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_groups_remove_group_cmd_req(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = zb_buf_get_out_func();
  zb_zcl_start_command_header(1,0,3,0);
  uVar2 = zb_put_next_htole16(*(undefined2 *)(param_1 + 0x10));
  zb_zcl_finish_and_send_packet
            (uVar1,uVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,4);
  return;
}


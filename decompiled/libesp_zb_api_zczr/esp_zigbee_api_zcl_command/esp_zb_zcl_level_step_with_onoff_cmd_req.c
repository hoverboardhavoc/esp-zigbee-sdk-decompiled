/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_zcl_command.o -> esp_zb_zcl_level_step_with_onoff_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_level_step_with_onoff_cmd_req(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  uVar1 = zb_buf_get_out_func();
  puVar2 = (undefined1 *)zb_zcl_start_command_header(1,0,6,0);
  *puVar2 = *(undefined1 *)(param_1 + 0x10);
  puVar2[1] = *(undefined1 *)(param_1 + 0x11);
  uVar3 = zb_put_next_htole16(puVar2 + 2,*(undefined2 *)(param_1 + 0x12));
  zb_zcl_finish_and_send_packet
            (uVar1,uVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,8);
  return;
}


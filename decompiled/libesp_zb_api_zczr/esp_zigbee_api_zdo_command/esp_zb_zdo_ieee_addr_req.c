/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_zdo_command.o -> esp_zb_zdo_ieee_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_ieee_addr_req(undefined2 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  int iVar3;
  
  uVar1 = zb_buf_get_out_func();
  puVar2 = (undefined2 *)zb_buf_get_tail_func(6);
  *puVar2 = *param_1;
  puVar2[1] = param_1[1];
  *(undefined1 *)(puVar2 + 2) = *(undefined1 *)(param_1 + 2);
  *(undefined1 *)((int)puVar2 + 5) = *(undefined1 *)((int)param_1 + 5);
  iVar3 = zb_zdo_ieee_addr_req(uVar1,device_ieee_addr_req_cb);
  *(undefined4 *)(ieee_user_cb + iVar3 * 4) = param_2;
  return;
}


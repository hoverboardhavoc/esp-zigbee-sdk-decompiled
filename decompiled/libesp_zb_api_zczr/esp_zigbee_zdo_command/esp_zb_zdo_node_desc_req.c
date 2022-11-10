/*
 * Last changed at upstream commit 6f86421a4970072ce8039b9d5be911c385f38303
 * https://github.com/espressif/esp-zigbee-sdk/commit/6f86421a4970072ce8039b9d5be911c385f38303
 * Upstream date: 2022-11-10 11:13:02 +0800
 * Upstream subject: examples: apply new signal handler API function
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_node_desc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_node_desc_req(undefined2 *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_buf_initial_alloc_func(2);
  uVar1 = *param_1;
  *puVar3 = (char)uVar1;
  puVar3[1] = (char)((ushort)uVar1 >> 8);
  iVar4 = zb_zdo_node_desc_req(uVar2,zb_zdo_node_desc_req_cb);
  *(undefined4 *)(node_desc_user_cb + iVar4 * 4) = param_2;
  return;
}


/*
 * Last changed at upstream commit 6f86421a4970072ce8039b9d5be911c385f38303
 * https://github.com/espressif/esp-zigbee-sdk/commit/6f86421a4970072ce8039b9d5be911c385f38303
 * Upstream date: 2022-11-10 11:13:02 +0800
 * Upstream subject: examples: apply new signal handler API function
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_groups_get_view_group_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_groups_get_view_group_res(undefined4 param_1)

{
  uint uVar1;
  undefined1 *puVar2;
  
  uVar1 = zb_buf_len_func();
  if ((3 < uVar1) &&
     (puVar2 = (undefined1 *)zb_buf_begin_func(param_1), puVar2 != (undefined1 *)0x0)) {
    (*zcl_view_group_resp_user_cb)(*puVar2,*(undefined2 *)(puVar2 + 1),zcl_view_group_resp_user_cb);
  }
  return;
}


/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
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
  if ((uVar1 < 4) ||
     (puVar2 = (undefined1 *)zb_buf_begin_func(param_1), puVar2 == (undefined1 *)0x0)) {
    (*zcl_view_group_resp_user_cb)(1,0,zcl_view_group_resp_user_cb);
  }
  else {
    (*zcl_view_group_resp_user_cb)(*puVar2,*(undefined2 *)(puVar2 + 1),zcl_view_group_resp_user_cb);
  }
  return;
}


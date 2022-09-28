/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_custom_cluster_get_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_custom_cluster_get_cmd_req(undefined4 param_1,void *param_2,undefined1 *param_3)

{
  uint uVar1;
  void *__src;
  
  uVar1 = zb_buf_len_func();
  if (uVar1 < 0x1c) {
    *param_3 = 1;
  }
  else {
    __src = (void *)zb_buf_begin_func(param_1);
    *param_3 = 1;
    if (__src != (void *)0x0) {
      memcpy(param_2,__src,0x1c);
      *param_3 = 0;
    }
  }
  return;
}


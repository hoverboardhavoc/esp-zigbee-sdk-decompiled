/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> data_model_adapter.o -> esp_zb_finish_attr_lists
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_finish_attr_lists(int param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)malloc(0x10);
  puVar1[5] = *(undefined2 *)(param_1 + 10);
  puVar1[2] = 0xffff;
  *(undefined1 *)((int)puVar1 + 3) = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  *puVar1 = 0xffff;
  *(undefined1 *)(puVar1 + 1) = 0;
  *(undefined4 *)(puVar1 + 6) = 0;
  *(undefined2 **)(param_1 + 0xc) = puVar1;
  return;
}


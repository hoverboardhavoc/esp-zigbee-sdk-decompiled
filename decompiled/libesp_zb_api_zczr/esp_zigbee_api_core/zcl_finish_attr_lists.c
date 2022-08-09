/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> zcl_finish_attr_lists
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_finish_attr_lists(int param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)malloc(0x10);
  puVar1[4] = *(undefined2 *)(param_1 + 8);
  *(undefined1 *)((int)puVar1 + 3) = 0;
  *(undefined4 *)(puVar1 + 2) = 0;
  *puVar1 = 0xffff;
  *(undefined1 *)(puVar1 + 1) = 0;
  *(undefined4 *)(puVar1 + 6) = 0;
  *(undefined2 **)(param_1 + 0xc) = puVar1;
  return;
}


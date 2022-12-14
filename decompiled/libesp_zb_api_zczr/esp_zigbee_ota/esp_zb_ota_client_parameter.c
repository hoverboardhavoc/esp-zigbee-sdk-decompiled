/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> esp_zb_ota_client_parameter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_ota_client_parameter(undefined2 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)malloc(0x10);
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 1) = *param_1;
  *(undefined2 *)((int)puVar1 + 6) = 1;
  *(undefined2 *)(puVar1 + 2) = param_1[1];
  *(undefined1 *)((int)puVar1 + 10) = *(undefined1 *)(param_1 + 2);
  *(undefined1 *)((int)puVar1 + 0xb) = 0;
  *(undefined1 *)(puVar1 + 3) = 0;
  return;
}


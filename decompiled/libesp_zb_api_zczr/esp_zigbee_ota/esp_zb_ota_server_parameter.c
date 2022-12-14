/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> esp_zb_ota_server_parameter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int * esp_zb_ota_server_parameter(int param_1)

{
  int *piVar1;
  void *pvVar2;
  
  piVar1 = (int *)malloc(0x10);
  pvVar2 = malloc(8);
  *piVar1 = param_1;
  piVar1[1] = param_1 + 4;
  *(undefined1 *)(piVar1 + 2) = 1;
  piVar1[3] = (int)pvVar2;
  return piVar1;
}


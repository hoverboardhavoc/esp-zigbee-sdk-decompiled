/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_zcl_attr_list_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * esp_zb_zcl_attr_list_create(undefined2 param_1)

{
  void *pvVar1;
  undefined2 *puVar2;
  
  pvVar1 = malloc(0x10);
  puVar2 = (undefined2 *)malloc(0x10);
  puVar2[5] = param_1;
  *puVar2 = 0xfffd;
  *(undefined1 *)((int)puVar2 + 3) = 1;
  *(undefined1 *)(puVar2 + 1) = 0x21;
  puVar2[2] = 0xffff;
  *(undefined2 **)(puVar2 + 3) = &cluster_revision_0;
  *(undefined4 *)(puVar2 + 6) = 0;
  *(undefined2 **)((int)pvVar1 + 0xc) = puVar2;
  return pvVar1;
}


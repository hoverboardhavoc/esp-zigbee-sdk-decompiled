/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_zcl_get_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_get_cluster(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = zb_af_get_endpoint_desc();
  if (iVar1 != 0) {
    get_cluster_desc(param_1,param_2);
    return;
  }
  zb_assert("/home/xiaqilin/esp/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_cluster.c",0x34);
  pvVar2 = malloc(0x14);
  *(undefined4 *)((int)pvVar2 + 0x10) = 0;
  return;
}


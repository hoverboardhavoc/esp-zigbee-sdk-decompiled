/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_zcl_get_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * esp_zb_zcl_get_cluster(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = zb_af_get_endpoint_desc();
  if (iVar1 != 0) {
    pvVar2 = (void *)get_cluster_desc(param_1,param_2);
    return pvVar2;
  }
  zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_cluster.c",0xe0);
  pvVar2 = malloc(0x14);
  memset(pvVar2,0,0x14);
  return pvVar2;
}


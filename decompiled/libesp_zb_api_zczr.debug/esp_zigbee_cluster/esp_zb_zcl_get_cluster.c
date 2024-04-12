/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_zcl_get_cluster
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
  zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_cluster.c",0x7b);
  pvVar2 = malloc(0x14);
  memset(pvVar2,0,0x14);
  esp_zb_internal_zcl_add_cluster_list_to_set(pvVar2);
  return pvVar2;
}


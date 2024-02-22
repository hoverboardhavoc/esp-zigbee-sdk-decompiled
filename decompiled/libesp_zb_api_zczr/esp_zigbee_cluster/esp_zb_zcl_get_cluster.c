/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
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
  zb_assert("/home/xieqinan/ESP/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_cluster.c",0x34);
  pvVar2 = malloc(0x14);
  *(undefined4 *)((int)pvVar2 + 0x10) = 0;
  return;
}


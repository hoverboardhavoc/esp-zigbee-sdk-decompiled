/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> find_device_endpoint_cluster_attribute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * find_device_endpoint_cluster_attribute(uint param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar1 = (ushort *)find_device_endpoint_cluster();
  if (puVar1 != (ushort *)0x0) {
    for (iVar3 = 0; iVar3 < (int)(uint)puVar1[1]; iVar3 = iVar3 + 1) {
      puVar2 = (ushort *)(*(int *)(puVar1 + 2) + iVar3 * 10);
      if (*puVar2 == param_1) {
        return puVar2;
      }
    }
    puVar1 = (ushort *)0x0;
  }
  return puVar1;
}


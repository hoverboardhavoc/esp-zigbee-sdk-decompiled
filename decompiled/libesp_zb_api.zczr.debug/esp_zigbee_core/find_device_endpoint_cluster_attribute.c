/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> find_device_endpoint_cluster_attribute
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


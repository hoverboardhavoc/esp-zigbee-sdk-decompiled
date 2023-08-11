/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> find_device_endpoint_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * find_device_endpoint_cluster(uint param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar1 = (ushort *)find_device_endpoint();
  if (puVar1 != (ushort *)0x0) {
    for (iVar3 = 0; iVar3 < (int)(uint)(byte)puVar1[8]; iVar3 = iVar3 + 1) {
      puVar2 = (ushort *)(*(int *)((int)puVar1 + 0x11) + iVar3 * 0xf);
      if (*puVar2 == param_1) {
        return puVar2;
      }
    }
    puVar1 = (ushort *)0x0;
  }
  return puVar1;
}


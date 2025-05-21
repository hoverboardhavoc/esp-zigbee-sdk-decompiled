/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_core.o -> find_device_endpoint_cluster
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
  
  puVar1 = (ushort *)zb_af_get_endpoint_desc();
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


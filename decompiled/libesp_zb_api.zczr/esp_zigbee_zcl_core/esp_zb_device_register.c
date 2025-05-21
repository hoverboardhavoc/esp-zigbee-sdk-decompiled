/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_core.o -> esp_zb_device_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_device_register(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  pbVar1 = (byte *)esp_zb_internal_ep_list_to_device_ctx();
  if (pbVar1 == (byte *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    zb_af_register_device_ctx();
    iVar2 = zb_zcl_get_ctx();
    *(code **)(iVar2 + 0x9c) = zb_zcl_device_callback;
    iVar2 = zb_zcl_get_ctx();
    *(code **)(iVar2 + 0x94) = zb_zcl_report_attr_callback;
    for (iVar2 = 0; iVar2 < (int)(uint)*pbVar1; iVar2 = iVar2 + 1) {
      if (((byte)(**(char **)(*(int *)(pbVar1 + 1) + iVar2 * 4) - 1U) < 0xef) &&
         (iVar4 = zb_af_get_endpoint_desc(), *(int *)(iVar4 + 3) == 0)) {
        iVar4 = zb_af_get_endpoint_desc(**(undefined1 **)(*(int *)(pbVar1 + 1) + iVar2 * 4));
        *(undefined1 *)(iVar4 + 3) = 0xa6;
        *(undefined1 *)(iVar4 + 4) = 2;
        *(undefined1 *)(iVar4 + 5) = 1;
        *(undefined1 *)(iVar4 + 6) = 0;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


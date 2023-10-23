/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_device_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_device_register(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  esp_zb_device_ctx = (byte *)zcl_get_ep_lists();
  zb_af_register_device_ctx();
  iVar2 = zb_zcl_get_ctx();
  *(code **)(iVar2 + 0x9c) = zb_zcl_device_callback;
  iVar2 = zb_zcl_get_ctx();
  *(code **)(iVar2 + 0x94) = zb_zcl_report_attr_callback;
  pbVar1 = esp_zb_device_ctx;
  for (iVar2 = 0; iVar2 < (int)(uint)*pbVar1; iVar2 = iVar2 + 1) {
    if (((byte)(**(char **)(*(int *)(pbVar1 + 1) + iVar2 * 4) - 1U) < 0xef) &&
       (iVar3 = zb_af_get_endpoint_desc(), *(int *)(iVar3 + 3) == 0)) {
      iVar3 = zb_af_get_endpoint_desc(**(undefined1 **)(*(int *)(pbVar1 + 1) + iVar2 * 4));
      *(undefined1 *)(iVar3 + 3) = 10;
      *(undefined1 *)(iVar3 + 4) = 0x2f;
      *(undefined1 *)(iVar3 + 5) = 1;
      *(undefined1 *)(iVar3 + 6) = 0;
    }
  }
  return 0;
}


/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
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
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  pbVar1 = (byte *)zcl_get_ep_lists();
  zb_af_register_device_ctx();
  iVar2 = zb_zcl_get_ctx();
  *(code **)(iVar2 + 0x9c) = zb_zcl_device_callback;
  iVar2 = zb_zcl_get_ctx();
  *(code **)(iVar2 + 0x94) = zb_zcl_report_attr_callback;
  for (iVar2 = 0; iVar2 < (int)(uint)*pbVar1; iVar2 = iVar2 + 1) {
    iVar5 = iVar2 * 4;
    if ((byte)(**(char **)(*(int *)(pbVar1 + 1) + iVar5) - 1U) < 0xef) {
      iVar4 = zb_af_get_endpoint_desc();
      if (*(int *)(iVar4 + 3) == 0) {
        iVar5 = zb_af_get_endpoint_desc(**(undefined1 **)(*(int *)(pbVar1 + 1) + iVar5));
        *(undefined1 *)(iVar5 + 3) = 0x32;
        *(undefined1 *)(iVar5 + 4) = 0x38;
        *(undefined1 *)(iVar5 + 5) = 1;
        *(undefined1 *)(iVar5 + 6) = 0;
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC83,uVar3,"ESP_ZIGBEE_CORE",
                    **(undefined1 **)(*(int *)(pbVar1 + 1) + iVar5));
    }
  }
  return 0;
}


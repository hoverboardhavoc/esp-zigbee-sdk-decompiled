/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_device_register
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
  
  pbVar1 = (byte *)esp_zb_internal_ep_list_to_device_ctx();
  if (pbVar1 == (byte *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC16,uVar3,"ESP_ZIGBEE_CORE","esp_zb_device_register",0x326)
    ;
    uVar3 = 0xffffffff;
  }
  else {
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
          *(undefined1 *)(iVar5 + 3) = 0x6a;
          *(undefined1 *)(iVar5 + 4) = 0x1a;
          *(undefined1 *)(iVar5 + 5) = 1;
          *(undefined1 *)(iVar5 + 6) = 0;
        }
      }
      else {
        uVar3 = esp_log_timestamp();
        esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC17,uVar3,"ESP_ZIGBEE_CORE",
                      **(undefined1 **)(*(int *)(pbVar1 + 1) + iVar5));
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


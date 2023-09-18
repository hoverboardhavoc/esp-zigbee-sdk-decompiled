/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> match_desc_req_device_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void match_desc_req_device_timeout(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_LC4,uVar1,0x10000);
  iVar2 = esp_zb_zdo_callback_find(param_1);
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    (**(code **)(iVar2 + 4))
              (0x85,ZDO_INVALID_SHORT_ADDR,ZDO_INVALID_ENDPOINT,*(undefined4 *)(iVar2 + 8));
  }
  esp_zb_zdo_callback_remove(param_1);
  return;
}


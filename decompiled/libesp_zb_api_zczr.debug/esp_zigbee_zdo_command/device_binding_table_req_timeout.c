/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> device_binding_table_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_binding_table_req_timeout(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_LC12,uVar1,0x10000);
  iVar2 = esp_zb_zdo_callback_find(param_1);
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    (**(code **)(iVar2 + 4))(0,*(undefined4 *)(iVar2 + 8));
  }
  esp_zb_zdo_callback_remove(param_1);
  return;
}


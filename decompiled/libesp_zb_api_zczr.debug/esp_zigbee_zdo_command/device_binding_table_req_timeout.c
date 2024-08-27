/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
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
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_L0,uVar1,0x10000);
  iVar2 = esp_zb_zdo_callback_find(param_1);
  if ((iVar2 != 0) && (*(code **)(iVar2 + 4) != (code *)0x0)) {
    uStack_14 = 0;
    uStack_18 = 0x85;
    (**(code **)(iVar2 + 4))(&uStack_18,*(undefined4 *)(iVar2 + 8));
  }
  esp_zb_zdo_callback_remove(param_1);
  return;
}


/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> nwk_update_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_update_req_timeout(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_38 [48];
  
  memset(auStack_38,0,0x28);
  iVar1 = esp_zb_zdo_callback_find(param_1);
  auStack_38[0] = 0x85;
  if ((iVar1 != 0) && (*(code **)(iVar1 + 4) != (code *)0x0)) {
    (**(code **)(iVar1 + 4))(auStack_38,*(undefined4 *)(iVar1 + 8));
  }
  esp_zb_zdo_callback_remove(param_1);
  return;
}


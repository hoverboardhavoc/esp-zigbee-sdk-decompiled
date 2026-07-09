/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> esp_zb_zcl_reset_all_endpoints_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_reset_all_endpoints_to_factory_default(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  puVar1 = (undefined1 *)0x0;
  s_reset_default_attr_cb = param_1;
  do {
    puVar1 = (undefined1 *)ezb_af_get_next_simple_desc(puVar1);
    if (puVar1 == (undefined1 *)0x0) {
      iVar2 = 0;
      break;
    }
    iVar2 = ezb_af_endpoint_reset(*puVar1,0x10000);
  } while (iVar2 == 0);
  s_reset_default_attr_cb = 0;
  uVar3 = esp_zigbee_err_to_esp(iVar2);
  return uVar3;
}


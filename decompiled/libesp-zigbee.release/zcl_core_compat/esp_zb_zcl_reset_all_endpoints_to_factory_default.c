/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> esp_zb_zcl_reset_all_endpoints_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zcl_reset_all_endpoints_to_factory_default
                    (_Bool reset_report,esp_zb_zcl_reset_default_attr_callback_t cb)

{
  undefined1 *puVar1;
  int iVar2;
  esp_err_t eVar3;
  
  if (cb == (esp_zb_zcl_reset_default_attr_callback_t)0x0) {
    return 0;
  }
  puVar1 = (undefined1 *)0x0;
  s_reset_default_attr_cb = cb;
  do {
    puVar1 = (undefined1 *)ezb_af_get_next_simple_desc(puVar1);
    if (puVar1 == (undefined1 *)0x0) {
      iVar2 = 0;
      break;
    }
    iVar2 = ezb_af_endpoint_reset(*puVar1,0x10000);
  } while (iVar2 == 0);
  s_reset_default_attr_cb = (esp_zb_zcl_reset_default_attr_callback_t)0x0;
  eVar3 = esp_zigbee_err_to_esp(iVar2);
  return eVar3;
}


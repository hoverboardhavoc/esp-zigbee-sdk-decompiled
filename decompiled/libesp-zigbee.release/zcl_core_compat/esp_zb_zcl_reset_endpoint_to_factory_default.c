/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> esp_zb_zcl_reset_endpoint_to_factory_default
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zcl_reset_endpoint_to_factory_default
                    (uint8_t endpoint,_Bool reset_report,esp_zb_zcl_reset_default_attr_callback_t cb
                    )

{
  undefined3 in_register_00002029;
  esp_err_t eVar1;
  
  if (cb != (esp_zb_zcl_reset_default_attr_callback_t)0x0) {
    s_reset_default_attr_cb = cb;
    ezb_af_endpoint_reset(CONCAT31(in_register_00002029,endpoint),0x10000);
    eVar1 = esp_zigbee_err_to_esp();
    s_reset_default_attr_cb = (esp_zb_zcl_reset_default_attr_callback_t)0x0;
    return eVar1;
  }
  return 0;
}


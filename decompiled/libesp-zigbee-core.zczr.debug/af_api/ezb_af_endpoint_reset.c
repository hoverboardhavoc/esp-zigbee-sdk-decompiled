/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_api.o -> ezb_af_endpoint_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_af_endpoint_reset
                    (uint8_t ep_id,
                    ezb_af_endpoint_get_default_attr_value_callback_t get_default_value)

{
  undefined3 in_register_00002029;
  ezb_err_t eVar1;
  
  eVar1 = af_endpoint_reset(CONCAT31(in_register_00002029,ep_id));
  return eVar1;
}


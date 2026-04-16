/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_api.o -> ezb_mac_set_csma_ca_params
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_mac_set_csma_ca_params(ezb_mac_csma_ca_params_t *params)

{
  ezb_err_t eVar1;
  
  if (params == (ezb_mac_csma_ca_params_t *)0x0) {
    eVar1 = 2;
  }
  else {
    eVar1 = nwk_mm_set_pib_attr(0,0x4f,params);
    if ((eVar1 == 0) && (eVar1 = nwk_mm_set_pib_attr(0x57,&params->max_be), eVar1 == 0)) {
      eVar1 = nwk_mm_set_pib_attr(0x4e,&params->max_backoffs);
    }
  }
  return eVar1;
}


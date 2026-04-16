/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_pal_transmit(void)

{
  ezb_err_t eVar1;
  
  if (s_mac_pal_ctx.state == '\0') {
    eVar1 = 3;
  }
  else if (s_mac_pal_ctx.state == '\x05') {
    eVar1 = 3;
  }
  else {
    s_mac_pal_ctx.csma_nb = '\0';
    s_mac_pal_ctx.tx_retries = '\0';
    start_csma();
    eVar1 = 0;
  }
  return eVar1;
}


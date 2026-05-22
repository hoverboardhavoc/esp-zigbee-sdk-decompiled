/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_pal_transmit(void)

{
  if ((s_mac_pal_ctx.state != '\0') && (s_mac_pal_ctx.state != '\x05')) {
    s_mac_pal_ctx.csma_nb = '\0';
    s_mac_pal_ctx.tx_retries = '\0';
    start_csma();
    return 0;
  }
  return 3;
}


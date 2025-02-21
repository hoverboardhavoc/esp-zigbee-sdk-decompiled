/*
 * Last changed at upstream commit 2472f337c160837a43a3b2545ff1f91e67f9b446
 * https://github.com/espressif/esp-zigbee-sdk/commit/2472f337c160837a43a3b2545ff1f91e67f9b446
 * Upstream date: 2025-02-21 02:56:04 +0000
 * Upstream subject: esp-zigbee-sdk: (fd3e0871)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_get_default_long_poll_interval
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_get_default_long_poll_interval(void)

{
  return g_esp_zb_default_long_poll_interval;
}


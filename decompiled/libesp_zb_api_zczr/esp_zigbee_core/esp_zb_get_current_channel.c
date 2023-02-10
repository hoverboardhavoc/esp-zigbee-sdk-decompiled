/*
 * Last changed at upstream commit baa2c0427a754013932b7b4a3bc21cee014ddd24
 * https://github.com/espressif/esp-zigbee-sdk/commit/baa2c0427a754013932b7b4a3bc21cee014ddd24
 * Upstream date: 2023-02-10 16:01:53 +0800
 * Upstream subject: examples: provide new API for channel set(5818e5d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_get_current_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_get_current_channel(void)

{
  zb_get_current_channel();
  return;
}


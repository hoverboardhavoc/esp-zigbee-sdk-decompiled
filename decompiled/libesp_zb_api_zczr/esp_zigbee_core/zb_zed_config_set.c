/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zed_config_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zed_config_set(undefined1 *param_1)

{
  zb_set_ed_timeout(*param_1);
  zb_set_keepalive_timeout((*(int *)(param_1 + 4) * 1000 + 0x3bffU) / 0x3c00);
  if (*(int *)(param_1 + 4) != 0) {
    esp_zb_set_default_long_poll_interval();
  }
  zb_set_nvram_erase_at_start(0);
  return;
}


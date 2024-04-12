/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zed_config_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zed_config_set(undefined1 *param_1)

{
  zb_set_ed_timeout(*param_1);
  zb_set_keepalive_timeout(*(int *)(param_1 + 4) * 1000);
  if (*(int *)(param_1 + 4) != 0) {
    esp_zb_set_default_long_poll_interval();
  }
  zb_set_nvram_erase_at_start(0);
  return;
}


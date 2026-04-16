/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_platform_config
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

esp_err_t esp_zb_platform_config(esp_zb_platform_config_t *config)

{
  if (ESP_ZIGBEE_RADIO_MODE_UART_RCP < (config->radio_config).radio_mode) {
    return 0x102;
  }
  if ((config->host_config).host_connection_mode == ZB_HOST_CONNECTION_MODE_NONE) {
    memcpy(&s_platform_config,config,0x60);
    return 0;
  }
  return 0x102;
}


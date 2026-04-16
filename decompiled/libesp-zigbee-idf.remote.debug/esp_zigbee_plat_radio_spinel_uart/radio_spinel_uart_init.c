/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel_uart.o -> radio_spinel_uart_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

esp_err_t radio_spinel_uart_init
                    (esp_radio_spinel_uart_config_t *config,esp_line_endings_t tx_mode,
                    esp_line_endings_t rx_mode)

{
  esp_err_t eVar1;
  
  eVar1 = radio_spinel_uart_init_port(config);
  if (eVar1 == 0) {
    uart_vfs_dev_port_set_rx_line_endings(config->port,rx_mode);
    uart_vfs_dev_port_set_tx_line_endings(config->port,tx_mode);
  }
  else {
    esp_log(0x11,"ESP_ZIGBEE_RADIO_SPINEL_UART","%s(%d): Failed to initialize uart port",
            "radio_spinel_uart_init",0x2e);
    radio_spinel_uart_deinit(config);
  }
  return eVar1;
}


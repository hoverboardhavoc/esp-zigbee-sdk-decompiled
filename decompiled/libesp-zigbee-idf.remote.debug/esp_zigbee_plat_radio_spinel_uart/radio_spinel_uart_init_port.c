/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel_uart.o -> radio_spinel_uart_init_port
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

esp_err_t radio_spinel_uart_init_port(esp_radio_spinel_uart_config_t *config)

{
  int iVar1;
  
  iVar1 = uart_param_config(config->port,&config->uart_config);
  if (iVar1 == 0) {
    iVar1 = uart_set_pin(config->port,config->tx_pin,config->rx_pin,0xffffffff);
    if (iVar1 == 0) {
      iVar1 = uart_driver_install(config->port,0x400,0,0,0,0);
      if (iVar1 == 0) {
        uart_vfs_dev_use_driver(config->port);
      }
      else {
        esp_log(0x11,"ESP_ZIGBEE_RADIO_SPINEL_UART","%s(%d): Failed to install uart driver",
                "radio_spinel_uart_init_port",0x20);
      }
    }
    else {
      esp_log(0x11,"ESP_ZIGBEE_RADIO_SPINEL_UART","%s(%d): uart_set_pin failed",
              "radio_spinel_uart_init_port",0x1d);
    }
  }
  else {
    esp_log(0x11,"ESP_ZIGBEE_RADIO_SPINEL_UART","%s(%d): Failed to config uart parameters",
            "radio_spinel_uart_init_port",0x1b);
  }
  return iVar1;
}


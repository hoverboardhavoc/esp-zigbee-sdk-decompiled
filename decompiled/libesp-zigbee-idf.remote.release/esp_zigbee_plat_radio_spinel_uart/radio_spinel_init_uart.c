/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel_uart.o -> radio_spinel_init_uart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: uart_path */
/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

esp_err_t radio_spinel_init_uart(esp_radio_spinel_uart_config_t *uart_config,int *uart_fd)

{
  int iVar1;
  char acStack_20 [4];
  char uart_path [16];
  
  iVar1 = uart_param_config(uart_config->port,&uart_config->uart_config);
  if ((iVar1 == 0) &&
     (iVar1 = uart_set_pin(uart_config->port,uart_config->tx_pin,uart_config->rx_pin,0xffffffff),
     iVar1 == 0)) {
    iVar1 = uart_driver_install(uart_config->port,0x400,0,0,0,0);
    if (iVar1 == 0) {
      uart_vfs_dev_use_driver(uart_config->port);
      uart_vfs_dev_port_set_rx_line_endings(uart_config->port,2);
      uart_vfs_dev_port_set_tx_line_endings(uart_config->port,2);
      snprintf(acStack_20,0x10,"/dev/uart/%d");
      iVar1 = open(acStack_20,0x4002);
      *uart_fd = iVar1;
      return iVar1 >> 0x1f;
    }
  }
  uart_driver_delete(uart_config->port);
  return iVar1;
}


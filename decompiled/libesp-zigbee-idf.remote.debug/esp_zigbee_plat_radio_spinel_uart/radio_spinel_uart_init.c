/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel_uart.o -> radio_spinel_uart_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int radio_spinel_uart_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = radio_spinel_uart_init_port();
  if (iVar1 == 0) {
    uart_vfs_dev_port_set_rx_line_endings(*param_1,param_3);
    uart_vfs_dev_port_set_tx_line_endings(*param_1,param_2);
  }
  else {
    esp_log(0x11,"ESP_ZIGBEE_RADIO_SPINEL_UART","%s(%d): Failed to initialize uart port",
            "radio_spinel_uart_init",0x2e);
    radio_spinel_uart_deinit(param_1);
  }
  return iVar1;
}


/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_osif_serial.o -> zb_esp_uart_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_esp_uart_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = zb_esp_uart_init_port();
  uart_vfs_dev_port_set_rx_line_endings(*param_1,param_3);
  uart_vfs_dev_port_set_tx_line_endings(*param_1,param_2);
  if (iVar1 != 0) {
    zb_esp_uart_deinit(param_1);
  }
  return iVar1;
}


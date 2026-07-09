/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel_uart.o -> radio_spinel_init_uart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int radio_spinel_init_uart(undefined4 *param_1,int *param_2)

{
  int iVar1;
  char acStack_20 [16];
  
  iVar1 = uart_param_config(*param_1,param_1 + 1);
  if ((iVar1 == 0) && (iVar1 = uart_set_pin(*param_1,param_1[10],param_1[9],0xffffffff), iVar1 == 0)
     ) {
    iVar1 = uart_driver_install(*param_1,0x400,0,0,0,0);
    if (iVar1 == 0) {
      uart_vfs_dev_use_driver(*param_1);
      uart_vfs_dev_port_set_rx_line_endings(*param_1,2);
      uart_vfs_dev_port_set_tx_line_endings(*param_1,2);
      snprintf(acStack_20,0x10,"/dev/uart/%d");
      iVar1 = open(acStack_20,0x4002);
      *param_2 = iVar1;
      return iVar1 >> 0x1f;
    }
  }
  uart_driver_delete(*param_1);
  return iVar1;
}


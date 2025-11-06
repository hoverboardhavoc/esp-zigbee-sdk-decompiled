/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_osif_serial.o -> zb_esp_uart_init_port
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_esp_uart_init_port(undefined4 *param_1)

{
  uart_param_config(*param_1,param_1 + 3);
  uart_set_pin(*param_1,param_1[2],param_1[1],0xffffffff);
  uart_driver_install(*param_1,0x400,0,0,0,0);
  uart_vfs_dev_use_driver(*param_1);
  return 0;
}


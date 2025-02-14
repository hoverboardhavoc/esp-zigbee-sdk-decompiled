/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_osif_serial.o -> zb_esp_uart_init_port
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_esp_uart_init_port(undefined4 *param_1)

{
  uart_param_config(*param_1,param_1 + 3);
  uart_set_pin(*param_1,param_1[2],param_1[1],0xffffffff,0xffffffff);
  uart_driver_install(*param_1,0x400,0,0,0,0);
  uart_vfs_dev_use_driver(*param_1);
  return 0;
}


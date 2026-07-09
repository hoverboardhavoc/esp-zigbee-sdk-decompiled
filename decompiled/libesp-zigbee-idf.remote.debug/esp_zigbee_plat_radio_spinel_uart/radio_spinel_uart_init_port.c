/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel_uart.o -> radio_spinel_uart_init_port
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int radio_spinel_uart_init_port(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = uart_param_config(*param_1,param_1 + 1);
  if (iVar1 == 0) {
    iVar1 = uart_set_pin(*param_1,param_1[10],param_1[9],0xffffffff);
    if (iVar1 == 0) {
      iVar1 = uart_driver_install(*param_1,0x400,0,0,0,0);
      if (iVar1 == 0) {
        uart_vfs_dev_use_driver(*param_1);
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


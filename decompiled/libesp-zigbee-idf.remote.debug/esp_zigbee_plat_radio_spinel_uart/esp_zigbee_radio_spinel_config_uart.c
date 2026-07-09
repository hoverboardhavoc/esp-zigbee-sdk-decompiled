/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel_uart.o -> esp_zigbee_radio_spinel_config_uart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zigbee_radio_spinel_config_uart(void)

{
  int iVar1;
  
  iVar1 = esp_radio_spinel_uart_interface_enable(radio_spinel_init_uart,radio_spinel_deinit_uart,0);
  if (iVar1 == 0) {
    esp_log(0x13,"ESP_ZIGBEE_RADIO_SPINEL_UART","Spinel UART interface enable successfully");
  }
  else {
    esp_log(0x11,"ESP_ZIGBEE_RADIO_SPINEL_UART","Spinel UART interface enable failed");
  }
  return 0;
}


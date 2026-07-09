/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel_uart.o -> radio_spinel_init_uart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int radio_spinel_init_uart(int *param_1)

{
  int iVar1;
  int iVar2;
  char acStack_30 [28];
  
  iVar1 = radio_spinel_uart_init(2);
  if (iVar1 == 0) {
    snprintf(acStack_30,0x10,"/dev/uart/%d");
    iVar2 = open(acStack_30,0x4002);
    *param_1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = -1;
    }
  }
  else {
    esp_log(0x11,"ESP_ZIGBEE_RADIO_SPINEL_UART","%s(%d): Failed to initialize uart",
            "radio_spinel_init_uart",0x40);
  }
  return iVar1;
}


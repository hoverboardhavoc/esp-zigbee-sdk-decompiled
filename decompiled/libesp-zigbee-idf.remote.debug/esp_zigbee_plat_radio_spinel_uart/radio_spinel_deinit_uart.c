/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel_uart.o -> radio_spinel_deinit_uart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 radio_spinel_deinit_uart(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*param_2 == -1) {
    uVar1 = 0x103;
  }
  else {
    close(*param_2);
    *param_2 = -1;
    uVar1 = radio_spinel_uart_deinit(param_1);
  }
  return uVar1;
}


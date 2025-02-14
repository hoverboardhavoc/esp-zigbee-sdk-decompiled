/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_osif_serial.o -> zb_esp_console_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_console_process(void)

{
  ssize_t sVar1;
  undefined1 auStack_11 [5];
  
  while ((-1 < s_uart_fd && (sVar1 = read(s_uart_fd,auStack_11,1), 0 < sVar1))) {
    if (s_uart_rx_callback != (code *)0x0) {
      (*s_uart_rx_callback)(auStack_11[0]);
    }
  }
  return;
}


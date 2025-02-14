/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_osif_serial.o -> zb_esp_console_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_console_update(int param_1)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = s_uart_fd;
  if (s_uart_fd < 0x40) {
    puVar2 = (uint *)(((int)(((int)s_uart_fd >> 0x1f & 0x1fU) + s_uart_fd) >> 5) * 4 + param_1);
    *puVar2 = *puVar2 | 1 << (s_uart_fd & 0x1f);
  }
  if (*(int *)(param_1 + 0x18) < (int)uVar1) {
    *(uint *)(param_1 + 0x18) = uVar1;
  }
  return;
}


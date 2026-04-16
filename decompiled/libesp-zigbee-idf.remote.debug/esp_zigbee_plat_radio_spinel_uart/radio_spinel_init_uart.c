/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel_uart.o -> radio_spinel_init_uart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

esp_err_t radio_spinel_init_uart(esp_radio_spinel_uart_config_t *uart_config,int *uart_fd)

{
  esp_err_t eVar1;
  int iVar2;
  char acStack_30 [4];
  char uart_path [16];
  
  eVar1 = radio_spinel_uart_init(uart_config,ESP_LINE_ENDINGS_LF,ESP_LINE_ENDINGS_LF);
  if (eVar1 == 0) {
    snprintf(acStack_30,0x10,"/dev/uart/%d");
    iVar2 = open(acStack_30,0x4002);
    *uart_fd = iVar2;
    if (iVar2 < 0) {
      eVar1 = -1;
    }
  }
  else {
    esp_log(0x11,"ESP_ZIGBEE_RADIO_SPINEL_UART","%s(%d): Failed to initialize uart",
            "radio_spinel_init_uart",0x40);
  }
  return eVar1;
}


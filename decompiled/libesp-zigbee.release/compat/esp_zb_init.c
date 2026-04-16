/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

void esp_zb_init(esp_zb_cfg_t *nwk_cfg)

{
  undefined1 auStack_54 [4];
  esp_zigbee_config_t config;
  
  config.device_config.field_2.zed_config.keep_alive = (uint32_t)_LC0;
  memcpy(auStack_54,nwk_cfg,0x10);
  memcpy(&config.platform_config,&s_platform_config,0x30);
  esp_zigbee_init(auStack_54);
  return;
}


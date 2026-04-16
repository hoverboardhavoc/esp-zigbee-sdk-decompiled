/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_init
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
  
  memset(auStack_54,0,0x44);
  config.device_config.field_2.zed_config.keep_alive = (uint32_t)_L0;
  memcpy(auStack_54,nwk_cfg,0x10);
  config.platform_config.storage_partition_name = (char *)s_platform_config.radio_config.radio_mode;
  config.platform_config.radio_config.radio_mode =
       s_platform_config.radio_config.field_1.radio_uart_config.port;
  config.platform_config.radio_config.field_1.radio_uart_config.port =
       s_platform_config.radio_config.field_1.radio_uart_config.uart_config.baud_rate;
  config.platform_config.radio_config.field_1.radio_uart_config.uart_config.baud_rate =
       s_platform_config.radio_config.field_1.radio_uart_config.uart_config.data_bits;
  config.platform_config.radio_config.field_1.radio_uart_config.uart_config.data_bits =
       s_platform_config.radio_config.field_1.radio_uart_config.uart_config.parity;
  config.platform_config.radio_config.field_1.radio_uart_config.uart_config.parity =
       s_platform_config.radio_config.field_1.radio_uart_config.uart_config.stop_bits;
  config.platform_config.radio_config.field_1.radio_uart_config.uart_config.stop_bits =
       s_platform_config.radio_config.field_1.radio_uart_config.uart_config.flow_ctrl;
  config.platform_config.radio_config.field_1.radio_uart_config.uart_config.flow_ctrl =
       s_platform_config.radio_config.field_1._24_4_;
  config.platform_config.radio_config.field_1._24_4_ =
       s_platform_config.radio_config.field_1.radio_uart_config.uart_config.field_6;
  config.platform_config.radio_config.field_1.radio_uart_config.uart_config.field_6 =
       (anon_union_4_1_5b3ddcbc_for_uart_config_t_6)
       s_platform_config.radio_config.field_1.radio_uart_config.uart_config.flags;
  config.platform_config.radio_config.field_1.radio_uart_config.uart_config.flags =
       (anon_struct_4_2_0e332f8d_for_flags)
       s_platform_config.radio_config.field_1.radio_uart_config.rx_pin;
  config.platform_config.radio_config.field_1.radio_uart_config.rx_pin =
       s_platform_config.radio_config.field_1.radio_uart_config.tx_pin;
  esp_zigbee_init(auStack_54);
  return;
}


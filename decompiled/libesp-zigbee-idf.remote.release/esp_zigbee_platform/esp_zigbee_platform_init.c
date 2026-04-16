/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_platform.o -> esp_zigbee_platform_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

esp_err_t esp_zigbee_platform_init(esp_zigbee_platform_config_t *config)

{
  int iVar1;
  undefined4 uStack_14;
  esp_vfs_eventfd_config_t eventfd_config;
  
  uStack_14 = 2;
  iVar1 = esp_vfs_eventfd_register(&uStack_14);
  if ((((iVar1 == 0x103) || (iVar1 == 0)) && (iVar1 = esp_zigbee_platform_alarm_init(), iVar1 == 0))
     && ((iVar1 = esp_zigbee_task_queue_init(), iVar1 == 0 &&
         (iVar1 = esp_zigbee_platform_radio_init(&config->radio_config), iVar1 == 0)))) {
    esp_zigbee_set_storage_name(config->storage_partition_name);
  }
  else {
    esp_zigbee_platform_deinit();
  }
  return iVar1;
}


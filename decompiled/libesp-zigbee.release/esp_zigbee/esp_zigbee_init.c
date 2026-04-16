/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> esp_zigbee.o -> esp_zigbee_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

esp_err_t esp_zigbee_init(esp_zigbee_config_t *config)

{
  int iVar1;
  ezb_nwk_device_type_t eVar2;
  
  iVar1 = esp_zigbee_sleep_init();
  if ((((iVar1 == 0) && (iVar1 = esp_zigbee_lock_init(), iVar1 == 0)) &&
      (iVar1 = esp_zigbee_platform_init(&config->platform_config), iVar1 == 0)) &&
     (iVar1 = ezb_core_init(), iVar1 == 0)) {
    zdo_compat_init();
    ezb_secur_set_ic_required((config->device_config).install_code_policy);
    ezb_nwk_set_device_type((config->device_config).device_type);
    eVar2 = (config->device_config).device_type;
    if (eVar2 < EZB_NWK_DEVICE_TYPE_END_DEVICE) {
      ezb_nwk_set_max_children((config->device_config).field_2.zed_config.ed_timeout);
    }
    else if (eVar2 == EZB_NWK_DEVICE_TYPE_END_DEVICE) {
      ezb_nwk_set_ed_timeout((config->device_config).field_2.zed_config.ed_timeout);
      ezb_nwk_set_keepalive_interval((config->device_config).field_2.zed_config.keep_alive);
    }
    else {
      iVar1 = 0x102;
    }
  }
  return iVar1;
}


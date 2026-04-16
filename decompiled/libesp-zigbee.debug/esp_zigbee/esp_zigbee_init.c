/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> esp_zigbee.o -> esp_zigbee_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

esp_err_t esp_zigbee_init(esp_zigbee_config_t *config)

{
  undefined4 uVar1;
  int iVar2;
  ezb_nwk_device_type_t eVar3;
  
  uVar1 = esp_zigbee_get_version_string();
  esp_log(0x13,"ESP-ZIGBEE","SDK Version: %s",uVar1);
  iVar2 = esp_zigbee_sleep_init();
  if (iVar2 == 0) {
    iVar2 = esp_zigbee_lock_init();
    if (iVar2 == 0) {
      iVar2 = esp_zigbee_platform_init(&config->platform_config);
      if (iVar2 == 0) {
        iVar2 = ezb_core_init();
        if (iVar2 == 0) {
          zdo_compat_init();
          ezb_secur_set_ic_required((config->device_config).install_code_policy);
          ezb_nwk_set_device_type((config->device_config).device_type);
          eVar3 = (config->device_config).device_type;
          if (eVar3 < EZB_NWK_DEVICE_TYPE_END_DEVICE) {
            ezb_nwk_set_max_children((config->device_config).field_2.zed_config.ed_timeout);
          }
          else if (eVar3 == EZB_NWK_DEVICE_TYPE_END_DEVICE) {
            ezb_nwk_set_ed_timeout((config->device_config).field_2.zed_config.ed_timeout);
            ezb_nwk_set_keepalive_interval((config->device_config).field_2.zed_config.keep_alive);
          }
          else {
            iVar2 = 0x102;
          }
        }
        else {
          esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize ESP-Zigbee core","esp_zigbee_init",
                  0x41);
        }
      }
      else {
        esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize platform driver","esp_zigbee_init",
                0x3f);
      }
    }
    else {
      esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize task lock","esp_zigbee_init",0x3e);
    }
  }
  else {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Fail to initialize sleep procedure","esp_zigbee_init",0x3d);
  }
  return iVar2;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> esp_zigbee_platform_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Enum "soc_periph_uart_clk_src_legacy_t": Some values do not have unique names */

esp_err_t esp_zigbee_platform_radio_init(esp_zigbee_radio_config_t *config)

{
  esp_err_t eVar1;
  code *local_50;
  code *pcStack_4c;
  code *pcStack_48;
  code *pcStack_44;
  code *pcStack_40;
  undefined4 uStack_3c;
  code *pcStack_28;
  esp_radio_spinel_callbacks_t callbacks;
  
  if (config->radio_mode == ESP_ZIGBEE_RADIO_MODE_UART_RCP) {
    if ((s_radio_ctx._176_4_ & 1) == 0) {
      radio_ctx_init();
      callbacks.transmit_started = (_func_void_uint8_t_ptr *)0x0;
      pcStack_28 = radio_spinel_receive_done;
      callbacks.receive_done = radio_spinel_transmit_done;
      callbacks.transmit_done = radio_spinel_transmit_failed;
      callbacks.transmit_failed = radio_spinel_energy_detect_done;
      callbacks.energy_scan_done = radio_spinel_transmit_started;
      local_50 = radio_spinel_receive_done;
      pcStack_4c = radio_spinel_transmit_done;
      pcStack_48 = radio_spinel_transmit_failed;
      pcStack_44 = radio_spinel_energy_detect_done;
      pcStack_40 = radio_spinel_transmit_started;
      uStack_3c = 0;
      esp_radio_spinel_set_callbacks(&local_50,0);
      esp_zigbee_radio_spinel_config_uart(&config->field_1);
      esp_radio_spinel_init(0);
      esp_radio_spinel_enable(0);
      s_radio_ctx._176_4_ = s_radio_ctx._176_4_ & 0xfffffffd;
      esp_radio_spinel_set_promiscuous_mode(0,0);
      esp_radio_spinel_set_pending_mode(0,0);
      esp_radio_spinel_sleep(0);
      eVar1 = esp_zigbee_platform_workflow_register
                        ("radio",esp_zigbee_platform_radio_update,esp_zigbee_platform_radio_process)
      ;
      return eVar1;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
                  ,0x141,"esp_zigbee_platform_radio_init",
                  "config->radio_mode == ESP_ZIGBEE_RADIO_MODE_UART_RCP");
  }
  esp_log(0x11,"ESP-ZIGBEE","%s(%d): Radio was initialized already!",
          "esp_zigbee_platform_radio_init",0x143);
  return 0x103;
}


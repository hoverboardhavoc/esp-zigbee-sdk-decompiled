/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> esp_zigbee_platform_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zigbee_platform_radio_init(int *param_1)

{
  undefined4 uVar1;
  code *local_50;
  code *pcStack_4c;
  code *pcStack_48;
  code *pcStack_44;
  code *pcStack_40;
  undefined4 uStack_3c;
  code *pcStack_28;
  code *pcStack_24;
  code *pcStack_20;
  code *pcStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (*param_1 == 1) {
    if ((s_radio_ctx._176_4_ & 1) == 0) {
      radio_ctx_init();
      uStack_14 = 0;
      pcStack_28 = radio_spinel_receive_done;
      pcStack_24 = radio_spinel_transmit_done;
      pcStack_20 = radio_spinel_transmit_failed;
      pcStack_1c = radio_spinel_energy_detect_done;
      pcStack_18 = radio_spinel_transmit_started;
      local_50 = radio_spinel_receive_done;
      pcStack_4c = radio_spinel_transmit_done;
      pcStack_48 = radio_spinel_transmit_failed;
      pcStack_44 = radio_spinel_energy_detect_done;
      pcStack_40 = radio_spinel_transmit_started;
      uStack_3c = 0;
      esp_radio_spinel_set_callbacks(&local_50,0);
      esp_zigbee_radio_spinel_config_uart(param_1 + 1);
      esp_radio_spinel_init(0);
      esp_radio_spinel_enable(0);
      s_radio_ctx._176_4_ = s_radio_ctx._176_4_ & 0xfffffffd;
      esp_radio_spinel_set_promiscuous_mode(0,0);
      esp_radio_spinel_set_pending_mode(0,0);
      esp_radio_spinel_sleep(0);
      uVar1 = esp_zigbee_platform_workflow_register
                        ("radio",esp_zigbee_platform_radio_update,esp_zigbee_platform_radio_process)
      ;
      return uVar1;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
                  ,0x14a,"esp_zigbee_platform_radio_init",
                  "config->radio_mode == ESP_ZIGBEE_RADIO_MODE_UART_RCP");
  }
  esp_log(0x11,"ESP-ZIGBEE","%s(%d): Radio was initialized already!",
          "esp_zigbee_platform_radio_init",0x14c);
  return 0x103;
}


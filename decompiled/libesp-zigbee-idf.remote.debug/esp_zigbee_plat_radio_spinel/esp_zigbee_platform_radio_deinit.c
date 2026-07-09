/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> esp_zigbee_platform_radio_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zigbee_platform_radio_deinit(void)

{
  if ((s_radio_ctx._176_4_ & 1) == 0) {
    esp_log(0x11,"ESP-ZIGBEE","%s(%d): Radio was not initialized!",
            "esp_zigbee_platform_radio_deinit",0x16f);
  }
  else {
    esp_radio_spinel_sleep(0);
    esp_radio_spinel_rcp_deinit(0);
    radio_ctx_deinit();
    esp_zigbee_platform_workflow_unregister("radio");
  }
  return;
}


/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> esp_zigbee_platform_radio_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

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


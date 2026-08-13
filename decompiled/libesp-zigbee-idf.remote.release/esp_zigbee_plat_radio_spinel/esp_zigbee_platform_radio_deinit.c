/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> esp_zigbee_platform_radio_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zigbee_platform_radio_deinit(void)

{
  if ((_DAT_00010640 & 1) != 0) {
    esp_radio_spinel_sleep(0);
    esp_radio_spinel_rcp_deinit(0);
    _DAT_00010640 = _DAT_00010640 & 0xfffffffe;
    esp_zigbee_platform_workflow_unregister("radio");
    return;
  }
  return;
}


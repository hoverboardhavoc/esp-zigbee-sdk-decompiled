/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_set_src_match
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool ezb_plat_radio_set_src_match(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int extraout_a1;
  undefined4 extraout_a1_00;
  undefined4 uStack_28;
  undefined4 uStack_24;
  code *pcStack_14;
  
  iVar2 = esp_radio_spinel_set_pending_mode(0);
  if (iVar2 == 0) {
    return false;
  }
  pcVar1 = ezb_plat_radio_add_src_match_entry;
  puVar3 = (undefined4 *)
           _esp_error_check_failed
                     ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
                      ,0xca,"ezb_plat_radio_set_src_match",
                      "esp_radio_spinel_set_pending_mode(mode, ESP_RADIO_SPINEL_ZIGBEE)");
  pcStack_14 = pcVar1;
  if (extraout_a1 == 0) {
    uStack_24 = puVar3[1];
    uStack_28 = *puVar3;
    uStack_28 = __bswapdi2();
    uStack_24 = extraout_a1_00;
    iVar2 = esp_radio_spinel_add_extended_entry(&uStack_28,0);
  }
  else {
    iVar2 = esp_radio_spinel_add_short_entry(*(undefined2 *)puVar3,0);
  }
  return iVar2 != 0;
}


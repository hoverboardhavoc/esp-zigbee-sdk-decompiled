/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_radio_transmit(ezb_radio_frame_t *frame)

{
  int iVar1;
  uint8_t *puVar2;
  
  puVar2 = frame->psdu;
  puVar2[-1] = frame->length;
  iVar1 = esp_radio_spinel_transmit(puVar2 + -1,frame->channel,1,0);
  if (iVar1 == 0) {
    return 0;
  }
  _esp_error_check_failed
            ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,0xa6,"ezb_plat_radio_transmit",
             "esp_radio_spinel_transmit((uint8_t *)tx_psdu, frame->channel, true, ESP_RADIO_SPINEL_ZIGBEE)"
            );
  return 0x7f;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_transmit_failed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void radio_spinel_transmit_failed(esp_ieee802154_tx_error_t error)

{
  uint8_t *data;
  undefined4 uVar1;
  char *frame_info;
  
  if (error < ESP_IEEE802154_TX_ERR_COEXIST) {
    if (error < ESP_IEEE802154_TX_ERR_NO_ACK) {
      if (1 < error - ESP_IEEE802154_TX_ERR_CCA_BUSY) goto _L0;
      uVar1 = 0x1e1;
    }
    else {
      uVar1 = 0x1e9;
    }
  }
  else {
    if (error != ESP_IEEE802154_TX_ERR_COEXIST) {
_L0:
      frame_info = "radio_spinel_transmit_failed";
      data = (uint8_t *)
             __assert_func("//build/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
                           ,0x115,"radio_spinel_transmit_failed",&_L0);
      if (data == (uint8_t *)0x0) {
        ezb_plat_radio_transmit_done(&s_radio_ctx,0,0);
      }
      else {
        convert_to_radio_frame
                  (data,(esp_ieee802154_frame_info_t *)frame_info,(ezb_radio_frame_t *)&s_radio_ctx)
        ;
        ezb_plat_radio_transmit_done(&s_radio_ctx,&s_radio_ctx,0);
      }
      return;
    }
    uVar1 = 0x1e1;
  }
  ezb_plat_radio_transmit_done(&s_radio_ctx,0,uVar1);
  return;
}


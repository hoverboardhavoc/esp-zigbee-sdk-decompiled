/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_receive_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void radio_spinel_receive_done(uint8_t *data,esp_ieee802154_frame_info_t *frame_info)

{
  undefined1 auStack_28 [4];
  ezb_radio_frame_t rx_frame;
  
  auStack_28 = (undefined1  [4])0x0;
  rx_frame.psdu = (uint8_t *)0x0;
  rx_frame.length = '\0';
  rx_frame.channel = '\0';
  rx_frame._6_2_ = 0;
  rx_frame.info.tx.timestamp._0_4_ = 0;
  rx_frame.info.tx.timestamp._4_4_ = 0;
  rx_frame.info._8_4_ = 0;
  convert_to_radio_frame(data,frame_info,(ezb_radio_frame_t *)auStack_28);
  ezb_plat_radio_receive_done((ezb_radio_frame_t *)auStack_28,0);
  return;
}


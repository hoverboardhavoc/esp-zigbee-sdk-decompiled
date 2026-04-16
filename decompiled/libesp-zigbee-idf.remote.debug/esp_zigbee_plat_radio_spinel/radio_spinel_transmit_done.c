/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_transmit_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void radio_spinel_transmit_done
               (uint8_t *frame,uint8_t *ack,esp_ieee802154_frame_info_t *ack_frame_info)

{
  if (ack == (uint8_t *)0x0) {
    ezb_plat_radio_transmit_done(&s_radio_ctx,0,0);
  }
  else {
    convert_to_radio_frame(ack,ack_frame_info,(ezb_radio_frame_t *)&s_radio_ctx);
    ezb_plat_radio_transmit_done(&s_radio_ctx,&s_radio_ctx,0);
  }
  return;
}


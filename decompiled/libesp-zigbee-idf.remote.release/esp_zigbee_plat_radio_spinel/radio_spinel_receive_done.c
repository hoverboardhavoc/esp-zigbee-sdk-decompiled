/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_receive_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void radio_spinel_receive_done(uint8_t *data,esp_ieee802154_frame_info_t *frame_info)

{
  uint8_t *puStack_28;
  ezb_radio_frame_t rx_frame;
  
  memset((void *)((int)&rx_frame.psdu + 2),0,0x12);
  puStack_28 = data + 1;
  rx_frame.psdu._0_1_ = *data;
  rx_frame._4_4_ = *(undefined4 *)&frame_info->timestamp;
  rx_frame.psdu._1_1_ = frame_info->channel;
  rx_frame.info.tx.timestamp._4_1_ = frame_info->rssi;
  rx_frame.info.tx.timestamp._5_1_ = frame_info->lqi;
  rx_frame.info.tx.timestamp._6_1_ = frame_info->pending & 1;
  rx_frame.info.tx.timestamp._0_4_ = *(undefined4 *)((int)&frame_info->timestamp + 4);
  ezb_plat_radio_receive_done(&puStack_28,0);
  return;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> convert_to_radio_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_to_radio_frame
               (uint8_t *data,esp_ieee802154_frame_info_t *frame_info,ezb_radio_frame_t *radio_frame
               )

{
  undefined4 uVar1;
  
  radio_frame->psdu = data + 1;
  radio_frame->length = *data;
  radio_frame->channel = frame_info->channel;
  (radio_frame->info).tx.max_frame_retries = frame_info->rssi;
  (radio_frame->info).tx.max_csma_backoffs = frame_info->lqi;
  (radio_frame->info).tx.max_csma_be =
       (radio_frame->info).tx.max_csma_be & 0xfe | frame_info->pending & 1U;
  uVar1 = *(undefined4 *)((int)&frame_info->timestamp + 4);
  *(int *)&radio_frame->info = (int)frame_info->timestamp;
  *(undefined4 *)((int)&radio_frame->info + 4) = uVar1;
  return;
}


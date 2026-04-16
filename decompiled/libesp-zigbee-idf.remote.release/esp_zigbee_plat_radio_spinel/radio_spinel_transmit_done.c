/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_transmit_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void radio_spinel_transmit_done
               (uint8_t *frame,uint8_t *ack,esp_ieee802154_frame_info_t *ack_frame_info)

{
  radio_context *prVar1;
  
  if (ack == (uint8_t *)0x0) {
    prVar1 = (radio_context *)0x0;
  }
  else {
    s_radio_ctx.tx.ack_frame.psdu = ack + 1;
    s_radio_ctx.tx.ack_frame.length = *ack;
    prVar1 = &s_radio_ctx;
    s_radio_ctx.tx.ack_frame.channel = ack_frame_info->channel;
    s_radio_ctx.tx.ack_frame.info.tx.max_frame_retries = ack_frame_info->rssi;
    s_radio_ctx.tx.ack_frame.info.tx.max_csma_backoffs = ack_frame_info->lqi;
    s_radio_ctx.tx.ack_frame.info.tx.max_csma_be =
         s_radio_ctx.tx.ack_frame.info.tx.max_csma_be & 0xfe | ack_frame_info->pending & 1U;
    s_radio_ctx.tx.ack_frame.info.tx.timestamp._4_4_ =
         *(undefined4 *)((int)&ack_frame_info->timestamp + 4);
    s_radio_ctx.tx.ack_frame.info.tx.timestamp._0_4_ = (undefined4)ack_frame_info->timestamp;
  }
  ezb_plat_radio_transmit_done(&s_radio_ctx,prVar1,0);
  return;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_parse_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_frame_parse_payload(ezb_radio_frame_t *radio_frame,uint8_t mhr_len,mac_payload_t *mpl)

{
  undefined3 in_register_0000202d;
  
  if (radio_frame == (ezb_radio_frame_t *)0x0) {
    return 2;
  }
  if (mpl != (mac_payload_t *)0x0) {
    if ((CONCAT31(in_register_0000202d,mhr_len) - 3U & 0xff) < 0x7c) {
      mpl->buf = radio_frame->psdu + CONCAT31(in_register_0000202d,mhr_len);
      mpl->len = (radio_frame->length - mhr_len) + 0xfe;
      return 0;
    }
    return 0x10;
  }
  return 2;
}


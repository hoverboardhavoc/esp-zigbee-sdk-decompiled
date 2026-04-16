/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_formation_reset_tmp_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_formation_reset_tmp_ctx(form_tmp_s *form)

{
  (form->scan_channels).u32 = (form->scan_channels).u32 & 0x7ffffff;
  (form->scan_channels).u32 = 0;
  (form->min_result).max_rssi = '\x7f';
  (form->min_result).iface_id = 0xff;
  (form->min_result).channel_page = 0xff;
  (form->min_result).channel_number = 0xff;
  return;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_ctx_free_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_packet_ctx_free_entry(zdo_packet_ctx_entry_t *entry)

{
  if (entry == (zdo_packet_ctx_entry_t *)0x0) {
    return;
  }
  if ((*(uint *)&entry->field_0x14 & 3) == 3) {
    milli_timer_stop(&entry->timer);
    mm_free(entry);
    return;
  }
  return;
}


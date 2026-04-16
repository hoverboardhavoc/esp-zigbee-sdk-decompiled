/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_cnf_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_packet_cnf_handler(zdo_cmd_cnf_t *cnf,zdo_packet_ctx_entry_t *entry)

{
  uint error;
  
  if (cnf == (zdo_cmd_cnf_t *)0x0) {
    return;
  }
  if ((entry != (zdo_packet_ctx_entry_t *)0x0) &&
     ((entry->field_0x14 = entry->field_0x14 | 2, (entry->ctx).mode == '\0' ||
      (((entry->node).next != &entry->node && (cnf->status != '\0')))))) {
    error = 0;
    if (cnf->status != 0) {
      error = cnf->status | 0x400;
    }
    zdo_packet_notify_result(&entry->ctx,error,(void *)0x0);
    entry->field_0x14 = entry->field_0x14 | 1;
    zdo_packet_ctx_list_remove_entry(entry);
    if (entry == (zdo_packet_ctx_entry_t *)0x0) {
      return;
    }
    if ((*(uint *)&entry->field_0x14 & 3) != 3) {
      return;
    }
    milli_timer_stop(&entry->timer);
    mm_free(entry);
    return;
  }
  return;
}


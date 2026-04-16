/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_ctx_list_add_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_packet_ctx_list_add_entry(zdo_packet_ctx_entry_t *entry)

{
  zdp_status_t zVar1;
  int iVar2;
  uint uVar3;
  
  if (entry == (zdo_packet_ctx_entry_t *)0x0) {
    zVar1 = 0x80;
  }
  else {
    if ((entry->ctx).mode != '\0') {
      uVar3 = nwk_pim_get_fast_poll_interval();
      nwk_pim_start_fast_poll(5000 / uVar3);
    }
    iVar2 = core_globals_get();
    (entry->node).next = *(list_node_s **)(iVar2 + 0xd10);
    *(list_node_t **)(iVar2 + 0xd10) = &entry->node;
    milli_timer_init(&entry->timer,zdo_packet_ctx_entry_timeout,entry);
    milli_timer_start(&entry->timer,5000);
    zVar1 = '\0';
  }
  return zVar1;
}


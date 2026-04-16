/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_ent_handle_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_reasm_ent_handle_timeout(aps_reasm_ent_t *ent)

{
  int iVar1;
  
  if (ent->retry_cntr < 3) {
    ent->retry_cntr = ent->retry_cntr + 1;
    milli_timer_start(&ent->tm,0x640);
  }
  else {
    aps_reasm_ent_deinit(ent);
    iVar1 = core_globals_get();
    aps_reasm_ent_delete((aps_rx_context_t *)(iVar1 + 0x458),ent);
  }
  return;
}


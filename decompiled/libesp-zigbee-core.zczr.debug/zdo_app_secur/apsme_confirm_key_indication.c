/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> apsme_confirm_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void apsme_confirm_key_indication(apsme_confirm_key_ind_t *ind)

{
  int iVar1;
  uint error;
  
  if (ind->key_type == '\x04') {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xd5c) == '\x03') {
      nwk_pim_stop_fast_poll();
      if (ind->status == 0) {
        error = 0;
      }
      else {
        error = ind->status | 0x300;
      }
      zdo_secur_finish_state(error);
    }
  }
  return;
}


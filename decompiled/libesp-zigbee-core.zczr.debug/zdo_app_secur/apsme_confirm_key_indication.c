/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    if (*(char *)(iVar1 + 0xcf8) == '\x03') {
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


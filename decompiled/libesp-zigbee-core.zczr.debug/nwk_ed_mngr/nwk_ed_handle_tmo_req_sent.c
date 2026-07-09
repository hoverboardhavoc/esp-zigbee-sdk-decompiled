/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_handle_tmo_req_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ed_handle_tmo_req_sent(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0x9ee) == '\0') {
      nwk_pim_start_fast_poll(0);
    }
  }
  else {
    nwk_ed_process_keepalive_result(0);
  }
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}


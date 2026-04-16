/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_handle_network_comm_req_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_comm_req_sent(zmsg_t *msg,ezb_err_t error)

{
  int iVar1;
  
  if (error == 0) {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0x9ee) == '\0') {
      nwk_pim_start_poll();
      nwk_pim_start_fast_poll(0);
    }
    iVar1 = core_globals_get();
    milli_timer_start(iVar1 + 0xad4,500);
  }
  else {
    nwk_do_attach_done(error,0xfffe);
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}


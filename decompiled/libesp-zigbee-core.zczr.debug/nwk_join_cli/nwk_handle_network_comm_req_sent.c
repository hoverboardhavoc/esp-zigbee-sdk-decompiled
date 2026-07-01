/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
      nwk_pim_start_fast_poll(1);
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


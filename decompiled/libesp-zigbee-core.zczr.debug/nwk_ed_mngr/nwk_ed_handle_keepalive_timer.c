/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_handle_keepalive_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ed_handle_keepalive_timer(void *ctx)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  if ((*(uint *)(iVar1 + 0xaf8) >> 7 & 1) != 0) {
    iVar1 = core_globals_get();
    uVar2 = *(uint *)(iVar1 + 0xaf8) & 0x3f;
    if (uVar2 == 0) {
      iVar1 = core_globals_get();
      if (((*(uint *)(iVar1 + 0xaf8) >> 6 & 1) != 0) &&
         (iVar1 = nwk_get_keepalive_mode(), iVar1 != 2)) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_ed_mngr.c",0x1e4,
                      "nwk_ed_handle_keepalive_timer",&_L0);
        goto _L0;
      }
      nwk_ed_send_tmo_req();
      iVar1 = core_globals_get();
      *(byte *)(iVar1 + 0xaf8) = *(byte *)(iVar1 + 0xaf8) & 0xc0 | 1;
      iVar1 = core_globals_get();
      milli_timer_start(iVar1 + 0xae4,500);
    }
    else {
      if (uVar2 != 1) {
_L0:
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_ed_mngr.c",0x1ed,
                      "nwk_ed_handle_keepalive_timer",&_L0);
        nwk_ed_get_timeout();
        return;
      }
      nwk_ed_process_keepalive_result(false);
    }
  }
  return;
}


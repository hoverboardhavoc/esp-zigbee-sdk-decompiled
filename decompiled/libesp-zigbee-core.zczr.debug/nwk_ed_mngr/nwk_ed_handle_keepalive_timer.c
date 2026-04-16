/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
        __assert_func("//build/esp-zigbee/src/core/nwk/nwk_ed_mngr.c",0x1e4,
                      "nwk_ed_handle_keepalive_timer",&_LC5);
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
        __assert_func("//build/esp-zigbee/src/core/nwk/nwk_ed_mngr.c",0x1ed,
                      "nwk_ed_handle_keepalive_timer",&_LC5);
        nwk_ed_get_timeout();
        return;
      }
      nwk_ed_process_keepalive_result(false);
    }
  }
  return;
}


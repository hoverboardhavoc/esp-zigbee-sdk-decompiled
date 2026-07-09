/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_handle_keepalive_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_ed_handle_keepalive_timer(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  uVar2 = iVar1 + 0x1000;
  if ((*(uint *)(iVar1 + 0xaf8) >> 7 & 1) != 0) {
    iVar1 = core_globals_get();
    uVar2 = *(uint *)(iVar1 + 0xaf8) & 0x3f;
    if (uVar2 == 0) {
      iVar1 = core_globals_get();
      if ((*(uint *)(iVar1 + 0xaf8) >> 6 & 1) != 0) {
        iVar1 = nwk_get_keepalive_mode();
        if (iVar1 != 2) {
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_ed_mngr.c",0x1e5,
                        "nwk_ed_handle_keepalive_timer",&_L0);
          goto _L0;
        }
      }
      nwk_ed_send_tmo_req();
      iVar1 = core_globals_get();
      *(byte *)(iVar1 + 0xaf8) = *(byte *)(iVar1 + 0xaf8) & 0xc0 | 1;
      iVar1 = core_globals_get();
      uVar2 = milli_timer_start(iVar1 + 0xae4,500);
    }
    else {
      if (uVar2 != 1) {
_L0:
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_ed_mngr.c",0x1ee,
                      "nwk_ed_handle_keepalive_timer",&_L0);
        uVar2 = nwk_ed_get_timeout();
        if (uVar2 == 0) {
          iVar1 = 10;
        }
        else {
          iVar1 = 0x3c << (uVar2 & 0x1f);
        }
        return (uint)(iVar1 * 1000) >> 2;
      }
      uVar2 = nwk_ed_process_keepalive_result(0);
    }
  }
  return uVar2;
}


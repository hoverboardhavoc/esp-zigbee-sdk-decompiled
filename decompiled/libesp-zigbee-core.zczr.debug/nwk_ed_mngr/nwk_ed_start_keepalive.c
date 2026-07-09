/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_start_keepalive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ed_start_keepalive(void)

{
  int iVar1;
  
  iVar1 = nwk_is_device_zed();
  if (iVar1 != 0) {
    iVar1 = core_globals_get();
    if (-1 < *(char *)(iVar1 + 0xaf8)) {
      iVar1 = core_globals_get();
      *(byte *)(iVar1 + 0xaf8) = *(byte *)(iVar1 + 0xaf8) | 0x80;
      iVar1 = core_globals_get();
      milli_timer_start(iVar1 + 0xae4,500);
    }
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_ed_mngr.c",0x277,
                "nwk_ed_start_keepalive","nwk_is_device_zed()");
  iVar1 = core_globals_get();
  milli_timer_stop(iVar1 + 0xae4);
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xaf8) = *(byte *)(iVar1 + 0xaf8) & 0x7f;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xaf8) = *(byte *)(iVar1 + 0xaf8) & 0xbf;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xaf8) = *(byte *)(iVar1 + 0xaf8) & 0xc0;
  return;
}


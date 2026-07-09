/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_start_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_pim_start_poll(void)

{
  int iVar1;
  
  iVar1 = nwk_is_device_zed();
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_ed_mngr.c",0x15b,
                  "nwk_pim_start_poll","nwk_is_device_zed()");
  }
  else {
    iVar1 = core_globals_get();
    if ((*(byte *)(iVar1 + 0xb16) & 0x20) != 0) {
      return;
    }
  }
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xb16) = *(byte *)(iVar1 + 0xb16) | 0x20;
  nwk_pim_schedule_next_poll(1);
  return;
}


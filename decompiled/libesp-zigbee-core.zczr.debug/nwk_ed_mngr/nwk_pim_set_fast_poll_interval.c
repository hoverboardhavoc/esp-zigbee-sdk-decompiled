/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_set_fast_poll_interval
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_pim_set_fast_poll_interval(int param_1)

{
  int iVar1;
  
  iVar1 = nwk_is_device_zed();
  if (iVar1 != 0) {
    iVar1 = core_globals_get();
    if (*(int *)(iVar1 + 0xb10) != param_1) {
      iVar1 = core_globals_get();
      *(int *)(iVar1 + 0xb10) = param_1;
      iVar1 = core_globals_get();
      if ((*(uint *)(iVar1 + 0xb14) >> 0x15 & 1) != 0) {
        nwk_pim_schedule_next_poll(1);
      }
    }
  }
  return;
}


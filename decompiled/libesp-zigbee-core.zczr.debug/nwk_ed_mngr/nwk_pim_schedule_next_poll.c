/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_schedule_next_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_pim_schedule_next_poll(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0xb0c);
  if (param_1 != 0) {
    iVar2 = core_globals_get();
    uVar4 = nwk_pim_calculate_poll_interval();
    *(undefined4 *)(iVar2 + 0xb0c) = uVar4;
  }
  iVar2 = core_globals_get();
  iVar2 = milli_timer_is_running(iVar2 + 0xafc);
  if (iVar2 == 0) {
    iVar1 = core_globals_get();
    iVar2 = core_globals_get();
    milli_timer_start(iVar1 + 0xafc,*(undefined4 *)(iVar2 + 0xb0c));
  }
  else {
    iVar2 = core_globals_get();
    if (*(int *)(iVar2 + 0xb0c) != iVar1) {
      iVar2 = core_globals_get();
      iVar2 = milli_timer_get_fire_time(iVar2 + 0xafc);
      iVar3 = core_globals_get();
      iVar5 = *(int *)(iVar3 + 0xb0c);
      iVar3 = core_globals_get();
      milli_timer_fire_at(iVar3 + 0xafc,iVar2 + (iVar5 - iVar1));
    }
  }
  return;
}


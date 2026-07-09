/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_pim_schedule_next_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_pim_schedule_next_poll(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0xb0c);
  if (param_1 != 0) {
    iVar2 = core_globals_get();
    uVar3 = nwk_ed_get_keepalive_interval();
    iVar4 = core_globals_get();
    if (((*(byte *)(iVar4 + 0xb16) & 0x10) != 0) && (1000 < uVar3)) {
      uVar3 = 1000;
    }
    iVar4 = core_globals_get();
    if (*(short *)(iVar4 + 0xb14) != 0) {
      iVar4 = core_globals_get();
      if (*(uint *)(iVar4 + 0xb10) <= uVar3) {
        iVar4 = core_globals_get();
        uVar3 = *(uint *)(iVar4 + 0xb10);
      }
    }
    if (uVar3 == 0) {
      uVar3 = 10;
    }
    *(uint *)(iVar2 + 0xb0c) = uVar3;
  }
  iVar2 = core_globals_get();
  iVar2 = milli_timer_is_running(iVar2 + 0xafc);
  if (iVar2 != 0) {
    iVar2 = core_globals_get();
    if (*(int *)(iVar2 + 0xb0c) != iVar1) {
      iVar2 = core_globals_get();
      iVar2 = milli_timer_get_fire_time(iVar2 + 0xafc);
      iVar4 = core_globals_get();
      iVar5 = *(int *)(iVar4 + 0xb0c);
      iVar4 = core_globals_get();
      milli_timer_fire_at(iVar4 + 0xafc,(iVar2 - iVar1) + iVar5);
      return;
    }
    return;
  }
  iVar1 = core_globals_get();
  iVar2 = core_globals_get();
  milli_timer_start(iVar1 + 0xafc,*(undefined4 *)(iVar2 + 0xb0c));
  return;
}


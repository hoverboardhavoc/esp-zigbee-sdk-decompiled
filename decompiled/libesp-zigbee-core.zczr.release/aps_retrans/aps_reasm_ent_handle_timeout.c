/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_reasm_ent_handle_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_reasm_ent_handle_timeout(int param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_a1;
  
  if (*(byte *)(param_1 + 0x20) < 3) {
    *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) + 1;
    milli_timer_start(0x640);
    return;
  }
  milli_timer_stop(param_1 + 0x10);
  zmsg_queue_deinit(param_1);
  nwk_pim_stop_fast_poll();
  iVar1 = core_globals_get();
  iVar1 = iVar1 + 0x458;
  uVar2 = (param_1 - iVar1 >> 3) * -0x33333333;
  if ((uVar2 & 0xff) < 0x20) goto _L0;
  do {
    uVar2 = __assert_func(0,0,0,0);
    iVar1 = extraout_a1;
_L0:
    iVar1 = test_and_clr_bitmap(uVar2 & 0xff,iVar1 + 0x500);
  } while (iVar1 == 0);
  return;
}


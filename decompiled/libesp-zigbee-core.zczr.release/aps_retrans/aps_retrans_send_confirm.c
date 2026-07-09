/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_send_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_send_confirm(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  *param_1 = 0;
  iVar2 = core_globals_get();
  milli_timer_stop(param_1 + 2);
  uVar1 = (int)param_1 - (iVar2 + 0x54);
  if (*param_1 == 0) goto _L6;
  do {
    __assert_func(0,0,0,0);
_L6:
    uVar1 = (int)uVar1 >> 5;
  } while ((0x1f < (uVar1 & 0xff)) ||
          (iVar3 = test_and_clr_bitmap(uVar1 & 0xff,iVar2 + 0x454), iVar3 == 0));
  nwk_pim_stop_fast_poll();
  aps_send_frame_confirm(iVar4,param_2);
  iVar2 = core_globals_get();
  tasklet_post(iVar2 + 0x38);
  return;
}


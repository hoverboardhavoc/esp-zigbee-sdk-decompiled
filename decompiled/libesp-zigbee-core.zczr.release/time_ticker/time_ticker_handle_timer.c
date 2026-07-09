/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time_ticker.o -> time_ticker_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void time_ticker_handle_timer(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = random_add_jitter(0x3e3,10);
  iVar2 = milli_timer_get_fire_time(s_tmtk);
  milli_timer_fire_at(s_tmtk,iVar2 + iVar1);
  iVar1 = test_bit_constprop_0(0);
  if (iVar1 != 0) {
    nwk_fwd_handle_tick();
  }
  iVar1 = test_bit_constprop_0(1);
  if (iVar1 != 0) {
    nwk_router_handle_tick();
  }
  iVar1 = test_bit_constprop_0(2);
  if (iVar1 != 0) {
    nwk_concentrator_handle_tick();
  }
  iVar1 = test_bit_constprop_0(3);
  if (iVar1 != 0) {
    aps_secur_handle_tick();
  }
  iVar1 = test_bit_constprop_0(4);
  if (iVar1 != 0) {
    aps_dup_table_handle_tick();
    return;
  }
  return;
}


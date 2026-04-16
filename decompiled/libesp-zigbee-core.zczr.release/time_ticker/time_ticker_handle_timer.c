/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> time_ticker.o -> time_ticker_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void time_ticker_handle_timer(void)

{
  _Bool _Var1;
  int iVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  bitfield_t *pbVar4;
  bitfield_t *extraout_a1;
  bitfield_t *extraout_a1_00;
  bitfield_t *extraout_a1_01;
  bitfield_t *extraout_a1_02;
  
  iVar2 = random_add_jitter(0x3e3,10);
  iVar3 = milli_timer_get_fire_time(&s_tmtk);
  pbVar4 = (bitfield_t *)milli_timer_fire_at(&s_tmtk,iVar3 + iVar2);
  _Var1 = test_bit(0,pbVar4);
  pbVar4 = extraout_a1;
  if (CONCAT31(extraout_var,_Var1) != 0) {
    pbVar4 = (bitfield_t *)nwk_fwd_handle_tick();
  }
  _Var1 = test_bit(1,pbVar4);
  pbVar4 = extraout_a1_00;
  if (CONCAT31(extraout_var_00,_Var1) != 0) {
    pbVar4 = (bitfield_t *)nwk_router_handle_tick();
  }
  _Var1 = test_bit(2,pbVar4);
  pbVar4 = extraout_a1_01;
  if (CONCAT31(extraout_var_01,_Var1) != 0) {
    pbVar4 = (bitfield_t *)nwk_concentrator_handle_tick();
  }
  _Var1 = test_bit(3,pbVar4);
  pbVar4 = extraout_a1_02;
  if (CONCAT31(extraout_var_02,_Var1) != 0) {
    pbVar4 = (bitfield_t *)aps_secur_handle_tick();
  }
  _Var1 = test_bit(4,pbVar4);
  if (CONCAT31(extraout_var_03,_Var1) != 0) {
    aps_dup_table_handle_tick();
    return;
  }
  return;
}


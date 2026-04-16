/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_reasm_ent_handle_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_reasm_ent_handle_timeout(aps_reasm_ent_t *ent)

{
  _Bool _Var1;
  int iVar2;
  uint uVar3;
  undefined3 extraout_var;
  int extraout_a1;
  
  if (ent->retry_cntr < 3) {
    ent->retry_cntr = ent->retry_cntr + 1;
    milli_timer_start(0x640);
    return;
  }
  milli_timer_stop(&ent->tm);
  zmsg_queue_deinit(ent);
  nwk_pim_stop_fast_poll();
  iVar2 = core_globals_get();
  iVar2 = iVar2 + 0x458;
  uVar3 = ((int)ent - iVar2 >> 3) * -0x33333333;
  if ((uVar3 & 0xff) < 0x20) goto _L0;
  do {
    uVar3 = __assert_func(0,0,0,0);
    iVar2 = extraout_a1;
_L0:
    _Var1 = test_and_clr_bitmap(uVar3 & 0xff,(bitmap_t *)(iVar2 + 0x500));
  } while (CONCAT31(extraout_var,_Var1) == 0);
  return;
}


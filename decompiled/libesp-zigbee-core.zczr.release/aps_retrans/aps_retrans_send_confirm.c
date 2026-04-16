/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_send_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_retrans_send_confirm(aps_retrans_ent_t *retrans,ezb_err_t error)

{
  uint uVar1;
  _Bool _Var2;
  int iVar3;
  undefined3 extraout_var;
  zmsg_t *pzVar4;
  
  pzVar4 = retrans->tx_msg;
  retrans->tx_msg = (zmsg_t *)0x0;
  iVar3 = core_globals_get();
  milli_timer_stop(&retrans->tm);
  uVar1 = (int)retrans - (iVar3 + 0x54);
  if (retrans->tx_msg == (zmsg_t *)0x0) goto _L6;
  do {
    do {
      __assert_func(0,0,0,0);
_L6:
      uVar1 = (int)uVar1 >> 5;
    } while (0x1f < (uVar1 & 0xff));
    _Var2 = test_and_clr_bitmap(uVar1 & 0xff,(bitmap_t *)(iVar3 + 0x454));
  } while (CONCAT31(extraout_var,_Var2) == 0);
  nwk_pim_stop_fast_poll();
  aps_send_confirm(pzVar4,error);
  iVar3 = core_globals_get();
  tasklet_post(iVar3 + 0x38);
  return;
}


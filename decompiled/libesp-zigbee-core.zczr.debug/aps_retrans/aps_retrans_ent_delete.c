/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_ent_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_retrans_ent_delete(aps_tx_context_t *ctx,aps_retrans_ent_t *ent)

{
  uint uVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  aps_retrans_ent_t *ent_00;
  int iVar3;
  undefined4 extraout_a1;
  zmsg_t *pzVar4;
  
  uVar1 = (int)ent - (int)ctx->ents >> 5;
  milli_timer_stop(&ent->tm);
  if (ent->tx_msg == (zmsg_t *)0x0) {
    if ((uVar1 & 0xff) < 0x20) {
      _Var2 = test_and_clr_bitmap(uVar1 & 0xff,ctx->ent_in_use);
      if (CONCAT31(extraout_var,_Var2) != 0) {
        aps_retrans_stop_fast_poll();
        return;
      }
      goto _L0;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_retrans.c",0x9e,"aps_retrans_ent_delete",
                  "ent->tx_msg == ((void *)0)");
  }
  __assert_func("//build/esp-zigbee/src/core/aps/aps_retrans.c",0x9f,"aps_retrans_ent_delete",
                "idx < 32");
_L0:
  ent_00 = (aps_retrans_ent_t *)
           __assert_func("//build/esp-zigbee/src/core/aps/aps_retrans.c",0xa0,
                         "aps_retrans_ent_delete","test_and_clr_bitmap(idx, ctx->ent_in_use)");
  pzVar4 = ent_00->tx_msg;
  ent_00->tx_msg = (zmsg_t *)0x0;
  iVar3 = core_globals_get();
  aps_retrans_ent_delete((aps_tx_context_t *)(iVar3 + 0x38),ent_00);
  aps_send_confirm(pzVar4,extraout_a1);
  iVar3 = core_globals_get();
  tasklet_post(iVar3 + 0x38);
  return;
}


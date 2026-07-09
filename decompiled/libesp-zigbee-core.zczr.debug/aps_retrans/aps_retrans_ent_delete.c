/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_ent_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_ent_delete(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 extraout_a1;
  undefined4 uVar4;
  
  uVar1 = (int)param_2 - (param_1 + 0x1c) >> 5;
  milli_timer_stop(param_2 + 2);
  if (*param_2 == 0) {
    if ((uVar1 & 0xff) < 0x20) {
      iVar2 = test_and_clr_bitmap(uVar1 & 0xff,param_1 + 0x41c);
      if (iVar2 != 0) {
        aps_retrans_stop_fast_poll();
        return;
      }
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x9e,
                  "aps_retrans_ent_delete","ent->tx_msg == ((void *)0)");
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x9f,
                "aps_retrans_ent_delete","idx < 32");
_L0:
  puVar3 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0xa0,
                         "aps_retrans_ent_delete","test_and_clr_bitmap(idx, ctx->ent_in_use)");
  uVar4 = *puVar3;
  *puVar3 = 0;
  iVar2 = core_globals_get();
  aps_retrans_ent_delete(iVar2 + 0x38,puVar3);
  aps_send_frame_confirm(uVar4,extraout_a1);
  iVar2 = core_globals_get();
  tasklet_post(iVar2 + 0x38);
  return;
}


/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_btt_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_btt_deinit(void)

{
  nwk_bt_record_t *pnVar1;
  nwk_fwd_s *pnVar2;
  
  pnVar2 = &s_nwk_fwd;
  do {
    pnVar1 = pnVar2->btt;
    pnVar2 = (nwk_fwd_s *)&(pnVar2->send_queue).length;
    mm_free(pnVar1->passive_ack);
  } while (pnVar2 != (nwk_fwd_s *)0x116b8);
  return;
}


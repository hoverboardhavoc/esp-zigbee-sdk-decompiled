/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  } while (pnVar2 != (nwk_fwd_s *)0x116f0);
  return;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_fwd_handle_tick(void)

{
  bool bVar1;
  nwk_fwd_s *pnVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  
  pnVar2 = &s_nwk_fwd;
  bVar1 = true;
  do {
    uVar4 = pnVar2->btt[0].expire_time;
    if (uVar4 != '\0') {
      uVar3 = uVar4 + 0xff;
      uVar4 = uVar4 + 0xff;
      pnVar2->btt[0].expire_time = uVar3;
    }
    pnVar2 = (nwk_fwd_s *)&(pnVar2->send_queue).length;
    bVar1 = (bool)(bVar1 & uVar4 == '\0');
  } while (pnVar2 != (nwk_fwd_s *)0x116f0);
  if (bVar1) {
    time_ticker_unregister_receiver(0);
    return;
  }
  return;
}


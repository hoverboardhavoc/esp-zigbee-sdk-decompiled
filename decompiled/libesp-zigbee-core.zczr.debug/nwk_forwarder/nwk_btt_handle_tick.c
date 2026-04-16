/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btt_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_btt_handle_tick(void)

{
  uint8_t uVar1;
  bool bVar2;
  uint uVar3;
  
  bVar2 = true;
  for (uVar3 = 0; uVar3 < 0x5a; uVar3 = uVar3 + 1 & 0xff) {
    uVar1 = s_nwk_fwd.btt[uVar3].expire_time;
    if (uVar1 != '\0') {
      s_nwk_fwd.btt[uVar3].expire_time = uVar1 + 0xff;
    }
    if (s_nwk_fwd.btt[uVar3].expire_time != '\0') {
      bVar2 = false;
    }
  }
  if (bVar2) {
    time_ticker_unregister_receiver(0);
  }
  return;
}


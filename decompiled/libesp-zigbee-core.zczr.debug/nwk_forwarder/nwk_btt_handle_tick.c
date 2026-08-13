/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btt_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_btt_handle_tick(void)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  
  bVar2 = true;
  for (uVar3 = 0; uVar3 < 0x5a; uVar3 = uVar3 + 1 & 0xff) {
    cVar1 = *(char *)((int)&DAT_00011a5c + (uVar3 + 6) * 8 + 3);
    if (cVar1 != '\0') {
      *(char *)((int)&DAT_00011a5c + (uVar3 + 6) * 8 + 3) = cVar1 + -1;
    }
    if (*(char *)((int)&DAT_00011a5c + (uVar3 + 6) * 8 + 3) != '\0') {
      bVar2 = false;
    }
  }
  if (bVar2) {
    time_ticker_unregister_receiver(0);
  }
  return;
}


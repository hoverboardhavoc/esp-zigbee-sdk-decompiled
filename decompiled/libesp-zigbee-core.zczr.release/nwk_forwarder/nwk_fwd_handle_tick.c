/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_tick(void)

{
  bool bVar1;
  undefined4 *puVar2;
  char cVar3;
  char cVar4;
  
  puVar2 = &s_nwk_fwd;
  bVar1 = true;
  do {
    cVar4 = *(char *)((int)puVar2 + 0x3f);
    if (cVar4 != '\0') {
      cVar3 = cVar4 + -1;
      cVar4 = cVar4 + -1;
      *(char *)((int)puVar2 + 0x3f) = cVar3;
    }
    puVar2 = puVar2 + 2;
    bVar1 = (bool)(bVar1 & cVar4 == '\0');
  } while (puVar2 != (undefined4 *)&DAT_000116c4);
  if (bVar1) {
    time_ticker_unregister_receiver(0);
    return;
  }
  return;
}


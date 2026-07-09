/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> start_csma
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void start_csma(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  
  bVar2 = *(byte *)(DAT_00010918 + 0x12);
  cVar1 = *(char *)(DAT_00010918 + 0x11);
  bVar4 = DAT_00010915 + *(char *)(DAT_00010918 + 0x13);
  set_state(3);
  iVar3 = should_handle_csma_backoff();
  if ((iVar3 == 0) || (cVar1 == '\0')) {
    start_transmit();
  }
  else {
    if (bVar4 < bVar2) {
      bVar2 = bVar4;
    }
    start_timer_for_csma(bVar2);
  }
  return;
}


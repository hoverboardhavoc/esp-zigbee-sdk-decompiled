/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> start_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void start_transmit(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00010630;
  if (s_mac_pal_ctx == '\x03') {
    iVar2 = ezb_plat_radio_receive(*(undefined1 *)(DAT_00010630 + 5));
    if (iVar2 == 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      set_state(4);
      iVar2 = ezb_plat_radio_transmit(iVar1);
    } while (iVar2 != 0);
    return;
  }
  return;
}


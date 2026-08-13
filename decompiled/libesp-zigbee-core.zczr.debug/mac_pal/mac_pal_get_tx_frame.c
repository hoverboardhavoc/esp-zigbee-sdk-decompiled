/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_get_tx_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mac_pal_get_tx_frame(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_00010a08 != 0) {
    return;
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x1a9,
                        "mac_pal_get_tx_frame","s_mac_pal_ctx.tx_frame != ((void *)0)");
  if ((_DAT_00010a1c >> 0x11 & 1) != uVar2) {
    uVar1 = _DAT_00010a1c >> 0x10;
    _DAT_00010a1c = CONCAT12((byte)uVar1 & 0xfd | (byte)((uVar2 & 1) << 1),DAT_00010a1c);
    ezb_plat_radio_set_src_match();
  }
  return;
}


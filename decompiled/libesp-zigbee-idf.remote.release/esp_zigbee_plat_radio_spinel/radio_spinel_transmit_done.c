/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_transmit_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void radio_spinel_transmit_done(undefined1 *param_1,byte *param_2)

{
  undefined4 *puVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    DAT_00010628 = param_1 + 1;
    DAT_0001062c = *param_1;
    puVar1 = &s_radio_ctx;
    DAT_0001062d = param_2[2];
    DAT_00010638 = param_2[3];
    DAT_00010639 = param_2[4];
    DAT_0001063a = DAT_0001063a & 0xfe | *param_2 & 1;
    DAT_00010634 = *(undefined4 *)(param_2 + 0xc);
    DAT_00010630 = *(undefined4 *)(param_2 + 8);
  }
  ezb_plat_radio_transmit_done(&s_radio_ctx,puVar1,0);
  return;
}


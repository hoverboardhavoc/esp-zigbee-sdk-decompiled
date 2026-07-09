/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
    DAT_000105f0 = param_1 + 1;
    DAT_000105f4 = *param_1;
    puVar1 = &s_radio_ctx;
    DAT_000105f5 = param_2[2];
    DAT_00010600 = param_2[3];
    DAT_00010601 = param_2[4];
    DAT_00010602 = DAT_00010602 & 0xfe | *param_2 & 1;
    DAT_000105fc = *(undefined4 *)(param_2 + 0xc);
    DAT_000105f8 = *(undefined4 *)(param_2 + 8);
  }
  ezb_plat_radio_transmit_done(&s_radio_ctx,puVar1,0);
  return;
}


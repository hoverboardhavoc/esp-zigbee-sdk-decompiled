/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_set_promiscuous
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_plat_radio_set_promiscuous(uint param_1)

{
  int iVar1;
  
  iVar1 = esp_radio_spinel_set_promiscuous_mode(0);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  DAT_00010608 = DAT_00010608 & 0xfd | (byte)((param_1 & 1) << 1);
  return;
}


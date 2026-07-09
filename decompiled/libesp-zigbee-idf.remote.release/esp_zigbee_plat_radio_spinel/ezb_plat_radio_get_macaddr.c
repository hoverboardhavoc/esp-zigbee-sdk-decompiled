/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_get_macaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_plat_radio_get_macaddr(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_a1;
  
  iVar1 = esp_radio_spinel_get_eui64(0);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar2 = __bswapdi2(*param_1,param_1[1]);
  *param_1 = uVar2;
  param_1[1] = extraout_a1;
  return;
}


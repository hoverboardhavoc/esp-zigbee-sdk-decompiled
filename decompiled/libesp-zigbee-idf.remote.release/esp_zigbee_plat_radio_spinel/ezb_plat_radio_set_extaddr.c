/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_set_extaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_plat_radio_set_extaddr(void *param_1)

{
  int iVar1;
  undefined4 extraout_a1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  memcpy(&uStack_18,param_1,8);
  uStack_18 = __bswapdi2(uStack_18,uStack_14);
  uStack_14 = extraout_a1;
  iVar1 = esp_radio_spinel_set_extended_address(&uStack_18,0);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_transmit_failed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void radio_spinel_transmit_failed(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 < 5) {
    if (param_1 < 3) {
      if (1 < param_1 - 1) goto _L0;
      uVar2 = 0x1e1;
    }
    else {
      uVar2 = 0x1e9;
    }
  }
  else {
    if (param_1 != 5) {
_L0:
      pcVar3 = "radio_spinel_transmit_failed";
      iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
                            ,0x11e,"radio_spinel_transmit_failed",&_L0);
      if (iVar1 == 0) {
        ezb_plat_radio_transmit_done(s_radio_ctx,0,0);
      }
      else {
        convert_to_radio_frame(pcVar3,s_radio_ctx);
        ezb_plat_radio_transmit_done(s_radio_ctx,s_radio_ctx,0);
      }
      return;
    }
    uVar2 = 0x1e1;
  }
  ezb_plat_radio_transmit_done(s_radio_ctx,0,uVar2);
  return;
}


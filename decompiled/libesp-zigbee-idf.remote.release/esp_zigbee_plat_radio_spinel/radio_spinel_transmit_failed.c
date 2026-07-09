/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_transmit_failed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void radio_spinel_transmit_failed(uint param_1)

{
  undefined4 unaff_retaddr;
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if (4 < param_1) goto _L0;
  uVar2 = 0x1e9;
  if (param_1 < 3) {
    uVar2 = 0x1e1;
    puVar1 = (undefined1 *)register0x00002008;
    if (1 < param_1 - 1) {
      do {
        register0x00002008 = (BADSPACEBASE *)(puVar1 + -0x10);
        *(undefined4 *)(puVar1 + -4) = unaff_retaddr;
        unaff_retaddr = 0x10068;
        param_1 = __assert_func(0,0,0,0);
_L0:
        uVar2 = 0x1e1;
        puVar1 = (undefined1 *)register0x00002008;
      } while (param_1 != 5);
    }
  }
  ezb_plat_radio_transmit_done(&s_radio_ctx,0,uVar2);
  return;
}


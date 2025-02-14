/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> zb_transceiver_set_ext_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_transceiver_set_ext_addr(int param_1)

{
  uint uVar1;
  undefined1 auStack_18 [20];
  
  for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1) {
    auStack_18[uVar1] = *(undefined1 *)((7 - uVar1) + param_1);
  }
  esp_radio_spinel_set_extended_address(auStack_18,0);
  return;
}


/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_radio_spinel.o -> zb_transceiver_set_ext_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_transceiver_set_ext_addr(undefined1 *param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 auStack_18 [20];
  
  puVar2 = param_1 + 7;
  puVar3 = auStack_18;
  do {
    *puVar3 = *puVar2;
    bVar1 = param_1 != puVar2;
    puVar2 = puVar2 + -1;
    puVar3 = puVar3 + 1;
  } while (bVar1);
  esp_radio_spinel_set_extended_address(auStack_18,0);
  return;
}


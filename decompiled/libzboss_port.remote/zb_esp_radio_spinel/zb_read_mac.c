/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_radio_spinel.o -> zb_read_mac
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_read_mac(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_1 == (undefined1 *)0x0) {
    param_1 = (undefined1 *)zb_read_mac_part_0();
  }
  esp_radio_spinel_get_eui64(0);
  puVar2 = param_1 + 3;
  puVar3 = param_1 + 7;
  do {
    uVar1 = *param_1;
    puVar4 = puVar3 + -1;
    *param_1 = *puVar3;
    *puVar3 = uVar1;
    param_1 = param_1 + 1;
    puVar3 = puVar4;
  } while (puVar4 != puVar2);
  return;
}


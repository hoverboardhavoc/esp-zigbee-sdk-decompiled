/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_radio_spinel.o -> zb_transceiver_set_pending_bit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zb_transceiver_set_pending_bit(undefined2 *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_18 [20];
  
  if (param_3 == 0) {
    if (param_2 == 0) {
      puVar3 = (undefined2 *)((int)param_1 + 7);
      puVar4 = auStack_18;
      do {
        *puVar4 = *(undefined1 *)puVar3;
        bVar1 = param_1 != puVar3;
        puVar3 = (undefined2 *)((int)puVar3 + -1);
        puVar4 = puVar4 + 1;
      } while (bVar1);
      iVar2 = esp_radio_spinel_add_extended_entry(auStack_18,0);
      goto _L0;
    }
    esp_radio_spinel_clear_extended_entries(0);
  }
  else {
    if (param_2 == 0) {
      iVar2 = esp_radio_spinel_add_short_entry(*param_1);
_L0:
      return iVar2 == 0;
    }
    esp_radio_spinel_clear_short_entries(0);
  }
  return true;
}


/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> zb_transceiver_set_pending_bit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zb_transceiver_set_pending_bit(undefined2 *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_18 [16];
  
  if (param_3 == 0) {
    if (param_2 == 0) {
      for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
        auStack_18[uVar2] = *(undefined1 *)((7 - uVar2) + (int)param_1);
      }
      iVar1 = esp_radio_spinel_add_extended_entry(auStack_18,0);
      param_2 = (uint)(iVar1 == 0);
    }
    else {
      esp_radio_spinel_clear_extended_entries(0);
    }
  }
  else if (param_2 == 0) {
    iVar1 = esp_radio_spinel_add_short_entry(*param_1,0);
    param_2 = (uint)(iVar1 == 0);
  }
  else {
    esp_radio_spinel_clear_short_entries(0);
  }
  return param_2;
}


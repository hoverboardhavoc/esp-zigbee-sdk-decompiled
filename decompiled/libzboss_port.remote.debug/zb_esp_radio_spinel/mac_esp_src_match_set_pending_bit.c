/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> mac_esp_src_match_set_pending_bit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_esp_src_match_set_pending_bit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_transceiver_set_pending_bit();
  if (iVar1 == 0) {
    uVar2 = 0xe7;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


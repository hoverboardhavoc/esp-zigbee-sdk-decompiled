/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_radio_spinel.o -> zb_read_mac.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zb_read_mac_part_0(void)

{
  int iVar1;
  int extraout_a1;
  int extraout_a1_00;
  int iVar2;
  
  iVar1 = __assert_func(0,0,0,0);
  iVar2 = extraout_a1;
  if (iVar1 == 0) {
    iVar1 = zb_read_mac_part_0();
    iVar2 = extraout_a1_00;
  }
  DAT_00011001 = 1;
  _zb_buf_begin_func = 0;
  if (((*(byte *)(iVar1 + 1) & 0x20) != 0) && (iVar2 != 0)) {
    if ((*(byte *)(iVar2 + 1) & 0x10) != 0) {
      _esp_radio_spinel_radio_process = 3;
      return;
    }
    _esp_radio_spinel_radio_process = 1;
  }
  return;
}


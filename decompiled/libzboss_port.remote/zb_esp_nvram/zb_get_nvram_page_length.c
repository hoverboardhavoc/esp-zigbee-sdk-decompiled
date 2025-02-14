/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_nvram.o -> zb_get_nvram_page_length
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zb_get_nvram_page_length(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((zb_partition != 0) && (uVar1 = *(uint *)(zb_partition + 0x10), uVar1 != 0)) {
    uVar1 = uVar1 >> 1 & 0xfffffff0;
  }
  return uVar1;
}


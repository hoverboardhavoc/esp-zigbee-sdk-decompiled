/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_nvram.o -> zb_osif_prod_cfg_check_presence
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zb_osif_prod_cfg_check_presence(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uStack_18;
  undefined1 auStack_14 [16];
  
  uStack_18 = 0xf6dd37e7;
  iVar2 = zb_osif_addr_read_part_0(0,auStack_14,4);
  bVar1 = false;
  if (iVar2 == 0) {
    iVar2 = memcmp(auStack_14,&uStack_18,4);
    bVar1 = iVar2 == 0;
  }
  return bVar1;
}


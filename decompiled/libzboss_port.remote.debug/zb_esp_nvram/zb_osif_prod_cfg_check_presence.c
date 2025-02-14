/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_nvram.o -> zb_osif_prod_cfg_check_presence
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zb_osif_prod_cfg_check_presence(void)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_18 [4];
  undefined4 auStack_14 [4];
  
  auStack_14[0] = 0xf6dd37e7;
  iVar2 = zb_osif_addr_read(0,auStack_18,4);
  if (iVar2 == 0) {
    iVar2 = memcmp(auStack_18,auStack_14,4);
    bVar1 = iVar2 == 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


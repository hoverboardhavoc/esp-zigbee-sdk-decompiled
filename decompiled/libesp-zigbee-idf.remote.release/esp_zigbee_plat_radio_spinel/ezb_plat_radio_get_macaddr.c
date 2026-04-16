/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_get_macaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_radio_get_macaddr(uint8_t *macaddr)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_a1;
  
  iVar1 = esp_radio_spinel_get_eui64(0);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar2 = __bswapdi2(*(undefined4 *)macaddr,*(undefined4 *)(macaddr + 4));
  *(undefined4 *)macaddr = uVar2;
  *(undefined4 *)(macaddr + 4) = extraout_a1;
  return;
}


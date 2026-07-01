/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_set_extaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_plat_radio_set_extaddr(ezb_extaddr_t *extaddr)

{
  int iVar1;
  undefined4 extraout_a1;
  undefined4 uStack_18;
  ezb_extaddr_t addr;
  
  memcpy(&uStack_18,extaddr,8);
  uStack_18 = __bswapdi2(uStack_18,addr.field_0.u64._0_4_);
  addr.field_0.u64._0_4_ = extraout_a1;
  iVar1 = esp_radio_spinel_set_extended_address(&uStack_18,0);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return;
}


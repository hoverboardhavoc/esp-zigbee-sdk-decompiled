/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_energy_detect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_pal_energy_detect(uint8_t page,uint8_t channel,uint16_t duration)

{
  undefined3 in_register_00002029;
  ezb_err_t eVar1;
  undefined3 in_register_0000202d;
  undefined4 uVar2;
  undefined2 in_register_00002032;
  undefined4 uVar3;
  
  uVar3 = CONCAT22(in_register_00002032,duration);
  uVar2 = CONCAT31(in_register_0000202d,channel);
  if ((s_mac_pal_ctx.state != '\0') && (2 < (byte)(s_mac_pal_ctx.state - 3))) {
    if (CONCAT31(in_register_00002029,page) != 0) {
      uVar3 = 0;
      uVar2 = __assert_func(0,0,0,0);
    }
    eVar1 = ezb_plat_radio_energy_detect(uVar2,uVar3);
    return eVar1;
  }
  return 3;
}


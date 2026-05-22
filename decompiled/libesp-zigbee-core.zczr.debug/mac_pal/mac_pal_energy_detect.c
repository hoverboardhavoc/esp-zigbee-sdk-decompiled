/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_energy_detect
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
  undefined2 in_register_00002032;
  
  if (s_mac_pal_ctx.state != '\0') {
    if ((byte)(s_mac_pal_ctx.state - 3) < 3) {
      return 3;
    }
    if (CONCAT31(in_register_00002029,page) == 0) {
      eVar1 = ezb_plat_radio_energy_detect
                        (CONCAT31(in_register_0000202d,channel),
                         CONCAT22(in_register_00002032,duration));
      return eVar1;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x197,
                  "mac_pal_energy_detect","page == 0");
  }
  return 3;
}


/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_get_wellknown_secret
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t * aps_secur_get_wellknown_secret(uint8_t index)

{
  uint uVar1;
  undefined3 in_register_00002029;
  uint uVar2;
  int extraout_a1;
  
  if (CONCAT31(in_register_00002029,index) < 4) {
    return aps_secur_get_wellknown_secret::s_secur_wellknown_secret
           [CONCAT31(in_register_00002029,index)];
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0xa5,
                        "aps_secur_get_wellknown_secret","index < SECUR_WELLKNOWN_SECRET_MAX_NR");
  uVar1 = 1 << (uVar2 & 7) & 0xff;
  uVar2 = __atomic_fetch_and_1((uVar2 >> 3) + extraout_a1,~uVar1 & 0xff,5);
  return (uint8_t *)(uint)((uVar2 & uVar1) != 0);
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  uVar2 = __assert_func("//build/esp-zigbee/src/core/aps/aps_secur.c",0x8f,
                        "aps_secur_get_wellknown_secret","index < SECUR_WELLKNOWN_SECRET_MAX_NR");
  uVar1 = 1 << (uVar2 & 7) & 0xff;
  uVar2 = __atomic_fetch_and_1((uVar2 >> 3) + extraout_a1,~uVar1 & 0xff,5);
  return (uint8_t *)(uint)((uVar2 & uVar1) != 0);
}


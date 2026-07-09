/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_get_wellknown_secret
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * aps_secur_get_wellknown_secret(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int extraout_a1;
  
  if (param_1 < 4) {
    return s_secur_wellknown_secret_2 + param_1 * 0x10;
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0xa5,__func___3
                        ,"index < SECUR_WELLKNOWN_SECRET_MAX_NR");
  uVar1 = 1 << (uVar2 & 7) & 0xff;
  uVar2 = __atomic_fetch_and_1((uVar2 >> 3) + extraout_a1,~uVar1 & 0xff,5);
  return (undefined1 *)(uint)((uVar2 & uVar1) != 0);
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_verified
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void aps_secur_key_pair_set_verified(int param_1)

{
  if ((param_1 != 0) && ((*(ushort *)(param_1 + 0x34) & 6) == 2)) {
    *(ushort *)(param_1 + 0x34) = *(ushort *)(param_1 + 0x34) & 0xfff9 | 4;
    *(undefined4 *)(param_1 + 0xc) = 0;
    aps_secur_key_pair_set_timeout(0xffff);
    aps_secur_store_key_pair(param_1);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0x153,
                "aps_secur_key_pair_set_verified",
                "key_pair != ((void *)0) && key_pair->key_attr == APS_KEY_ATTR_UNVERIFIED");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


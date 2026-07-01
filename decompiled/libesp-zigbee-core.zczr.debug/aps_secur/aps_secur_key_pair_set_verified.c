/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_verified
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void aps_secur_key_pair_set_verified(aps_device_key_pair_t *key_pair)

{
  if ((key_pair != (aps_device_key_pair_t *)0x0) && (((key_pair->field_8).flags & 6) == 2)) {
    (key_pair->field_8).flags = (key_pair->field_8).flags & 0xfff9 | 4;
    key_pair->incoming_frame_cntr = 0;
    aps_secur_key_pair_set_timeout(key_pair,0xffff);
    aps_secur_store_key_pair(key_pair);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0x153,
                "aps_secur_key_pair_set_verified",
                "key_pair != ((void *)0) && key_pair->key_attr == APS_KEY_ATTR_UNVERIFIED");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_reset_panid_table_except
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_reset_panid_table_except(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = core_globals_get();
  iVar2 = nwk_address_get_panid_ref(param_1);
  if (iVar2 != 0xff) {
    nwk_address_reset_panid_table();
    test_and_set_bitmap(iVar2,iVar1 + 0xc48);
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x9e,
                        "nwk_address_reset_panid_table_except",&_L0);
  iVar2 = core_globals_get();
  do_lock_ref(iVar2 + 0xc4c,iVar1);
  iVar1 = *(int *)(iVar2 + 0xc50) + iVar1 * 0x12;
  if ((*(byte *)(iVar1 + 0x11) & 4) != 0) {
    do_lock_ref(iVar2 + 0xc4c,*(undefined2 *)(iVar1 + 0xe));
  }
  return;
}


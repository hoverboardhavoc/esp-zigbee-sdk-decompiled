/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_link_mngr_set_enabled(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar2 = core_globals_get();
    milli_timer_stop(iVar2 + 0xaf4);
    iVar2 = core_globals_get();
    milli_timer_stop(iVar2 + 0xae4);
  }
  else {
    iVar2 = core_globals_get();
    *(undefined2 *)(iVar2 + 0xb04) = 0;
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xb06) = 0;
    iVar2 = core_globals_get();
    iVar3 = core_globals_get();
    nwk_link_mngr_start_timer(iVar2 + 0xaf4,*(undefined1 *)(iVar3 + 0xa24),0);
    iVar2 = core_globals_get();
    uVar1 = random_noncrypto_range_u32(0,*(undefined1 *)(iVar2 + 0xa24));
    iVar2 = core_globals_get();
    nwk_link_mngr_start_timer(iVar2 + 0xae4,uVar1,0x40);
  }
  return;
}


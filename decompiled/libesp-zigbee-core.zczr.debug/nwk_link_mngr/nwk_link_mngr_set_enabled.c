/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_link_mngr_set_enabled(_Bool enable)

{
  uint8_t delay_s;
  undefined3 in_register_00002029;
  int iVar1;
  int iVar2;
  
  if (CONCAT31(in_register_00002029,enable) == 0) {
    iVar1 = core_globals_get();
    milli_timer_stop(iVar1 + 0xaf4);
    iVar1 = core_globals_get();
    milli_timer_stop(iVar1 + 0xae4);
  }
  else {
    iVar1 = core_globals_get();
    *(undefined2 *)(iVar1 + 0xb04) = 0;
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xb06) = 0;
    iVar1 = core_globals_get();
    iVar2 = core_globals_get();
    nwk_link_mngr_start_timer((milli_timer_t *)(iVar1 + 0xaf4),*(uint8_t *)(iVar2 + 0xa24),0);
    iVar1 = core_globals_get();
    delay_s = random_noncrypto_range_u32(0,*(undefined1 *)(iVar1 + 0xa24));
    iVar1 = core_globals_get();
    nwk_link_mngr_start_timer((milli_timer_t *)(iVar1 + 0xae4),delay_s,0x40);
  }
  return;
}


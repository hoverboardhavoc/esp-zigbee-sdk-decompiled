/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_dev_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ed_dev_init(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  milli_timer_init(iVar1 + 0xae4,nwk_ed_handle_keepalive_timer,0);
  iVar1 = core_globals_get();
  uVar2 = nwk_ed_get_timeout();
  iVar3 = 10;
  if (uVar2 != 0) {
    iVar3 = 0x3c << (uVar2 & 0x1f);
  }
  *(uint *)(iVar1 + 0xaf4) = (uint)(iVar3 * 1000) >> 2;
  nwk_ed_stop_keepalive();
  iVar1 = core_globals_get();
  milli_timer_init(iVar1 + 0xafc,nwk_pim_handle_poll_timer,0);
  iVar1 = core_globals_get();
  *(undefined4 *)(iVar1 + 0xb10) = 200;
  iVar1 = core_globals_get();
  *(undefined2 *)(iVar1 + 0xb14) = 0;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xb16) = *(byte *)(iVar1 + 0xb16) & 0xf0;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xb16) = *(byte *)(iVar1 + 0xb16) & 0xef;
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xb16) = *(byte *)(iVar1 + 0xb16) & 0xdf;
  return;
}


/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_dev_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_ed_dev_init(void)

{
  byte bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  
  iVar2 = core_globals_get();
  milli_timer_init(iVar2 + 0xae4,nwk_ed_handle_keepalive_timer,0);
  iVar2 = core_globals_get();
  bVar1 = nwk_ed_get_timeout();
  iVar3 = 10;
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar3 = 0x3c << (bVar1 & 0x1f);
  }
  *(uint *)(iVar2 + 0xaf4) = (uint)(iVar3 * 1000) >> 2;
  nwk_ed_stop_keepalive();
  iVar2 = core_globals_get();
  milli_timer_init(iVar2 + 0xafc,nwk_pim_handle_poll_timer,0);
  iVar2 = core_globals_get();
  *(undefined4 *)(iVar2 + 0xb10) = 200;
  iVar2 = core_globals_get();
  *(undefined2 *)(iVar2 + 0xb14) = 0;
  iVar2 = core_globals_get();
  *(byte *)(iVar2 + 0xb16) = *(byte *)(iVar2 + 0xb16) & 0xf0;
  iVar2 = core_globals_get();
  *(byte *)(iVar2 + 0xb16) = *(byte *)(iVar2 + 0xb16) & 0xef;
  iVar2 = core_globals_get();
  *(byte *)(iVar2 + 0xb16) = *(byte *)(iVar2 + 0xb16) & 0xdf;
  return;
}


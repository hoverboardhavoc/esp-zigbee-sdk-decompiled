/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_pim_handle_poll_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_pim_handle_poll_timer(void *ctx)

{
  int iVar1;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined2 uStack_1a;
  mac_poll_req_t req;
  
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xb14) << 10 < 0) {
    memset(&uStack_1b,0,0xb);
    uStack_1c = 2;
    uStack_1a = nwk_get_parent_shortaddr();
    req.coord_address.u._4_2_ = nwk_get_panid();
    iVar1 = core_globals_get();
    nwk_mm_poll_request(*(uint *)(*(int *)(iVar1 + 0xac4) + 0xc) >> 0xd & 0x1f,&uStack_1c);
    nwk_pim_schedule_next_poll(false);
    return;
  }
  log_write(2,"nwk_ed_mngr.c","Request Data poll when polling is disabled!");
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xb14) << 10 < 0) {
    iVar1 = core_globals_get();
    milli_timer_stop(iVar1 + 0xafc);
    iVar1 = core_globals_get();
    *(undefined2 *)(iVar1 + 0xb14) = 0;
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xb16) = *(byte *)(iVar1 + 0xb16) & 0xf0;
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xb16) = *(byte *)(iVar1 + 0xb16) & 0xef;
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xb16) = *(byte *)(iVar1 + 0xb16) & 0xdf;
  }
  return;
}


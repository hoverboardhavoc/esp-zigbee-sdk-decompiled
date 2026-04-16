/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_poll_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_pim_poll_parent(void)

{
  undefined2 uVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined4 uStack_1c;
  mac_poll_req_t req;
  
  iVar2 = core_globals_get();
  if ((*(uint *)(iVar2 + 0xb14) >> 0x15 & 1) == 0) {
    log_write(2,"nwk_ed_mngr.c","Request Data poll when polling is disabled!");
    nwk_pim_stop_poll();
    eVar3 = 3;
  }
  else {
    req.coord_address._0_4_ = 0;
    req.coord_address.u._2_4_ = 0;
    uStack_1c = 2;
    uVar1 = nwk_get_parent_shortaddr();
    uStack_1c = CONCAT22(uVar1,(undefined2)uStack_1c);
    uVar1 = nwk_get_panid();
    req.coord_address.u._4_2_ = uVar1;
    iVar2 = core_globals_get();
    nwk_mm_poll_request(*(uint *)(*(int *)(iVar2 + 0xac4) + 0xc) >> 0xd & 0x1f,&uStack_1c);
    nwk_pim_schedule_next_poll(false);
    eVar3 = 0;
  }
  return eVar3;
}


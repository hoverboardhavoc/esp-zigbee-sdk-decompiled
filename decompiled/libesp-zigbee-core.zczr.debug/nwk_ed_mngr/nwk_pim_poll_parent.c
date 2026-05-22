/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_pim_poll_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_pim_poll_parent(void)

{
  ezb_err_t eVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uStack_1c;
  mac_poll_req_t req;
  
  iVar3 = core_globals_get();
  if ((*(uint *)(iVar3 + 0xb14) >> 0x15 & 1) == 0) {
    eVar1 = 3;
  }
  else {
    req.coord_address._0_4_ = 0;
    req.coord_address.u._2_4_ = 0;
    uStack_1c = 2;
    uVar2 = nwk_get_parent_shortaddr();
    uStack_1c = CONCAT22(uVar2,(undefined2)uStack_1c);
    uVar2 = nwk_get_panid();
    req.coord_address.u._4_2_ = uVar2;
    iVar3 = core_globals_get();
    eVar1 = nwk_mm_poll_request(*(uint *)(*(int *)(iVar3 + 0xac4) + 0xc) >> 0xd & 0x1f,&uStack_1c);
    if (eVar1 == 0) {
      nwk_pim_schedule_next_poll(false);
      return 0;
    }
    if (eVar1 != 3) {
      log_write(2,"nwk_ed_mngr.c","Unexpected error when requesting data poll: %d",eVar1);
      nwk_pim_schedule_next_poll(true);
      return eVar1;
    }
  }
  log_write(2,"nwk_ed_mngr.c","Request Data poll when polling is disabled!");
  nwk_pim_stop_poll();
  return eVar1;
}


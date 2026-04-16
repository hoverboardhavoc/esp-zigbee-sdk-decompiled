/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_zdo_start_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_zdo_start_router(touchlink_event_start_router_t *start_router)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 auStack_12 [2];
  nwk_addr_ref_t addr_ref;
  
  if (start_router != (touchlink_event_start_router_t *)0x0) goto _L18;
  do {
    start_router = (touchlink_event_start_router_t *)__assert_func(0,0,0,0);
_L18:
    nwk_set_extended_panid(&start_router->ext_panid);
    nwk_set_pan_channel((uint)(0x20 << (start_router->channel & 0x1f)) >> 5);
    nwk_set_panid(start_router->pan_id);
    nwk_set_short_address(start_router->new_short_addr);
    uVar1 = nwk_get_extended_address();
    uVar2 = touchlink_short_address();
    iVar3 = nwk_address_update(uVar1,uVar2,auStack_12);
  } while (iVar3 != 0);
  nwk_address_lock_ref(auStack_12[0]);
  iVar3 = core_globals_get();
  *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) | 1;
  nwk_secur_set_key(start_router->nwk_key,0);
  nwk_secur_switch_key(0);
  zdo_initiate_commissioning(0x80);
  return 0;
}


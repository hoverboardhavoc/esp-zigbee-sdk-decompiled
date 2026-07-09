/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_zdo_start_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_zdo_start_router(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 auStack_12 [3];
  
  if (param_1 != 0) goto _L18;
  do {
    param_1 = __assert_func(0,0,0,0);
_L18:
    nwk_set_extended_panid(param_1 + 1);
    nwk_set_pan_channel((uint)(0x20 << (*(byte *)(param_1 + 0xc) & 0x1f)) >> 5);
    nwk_set_panid(*(undefined2 *)(param_1 + 10));
    nwk_set_short_address(*(undefined2 *)(param_1 + 0xe));
    uVar1 = nwk_get_extended_address();
    uVar2 = touchlink_short_address();
    iVar3 = nwk_address_update(uVar1,uVar2,auStack_12);
  } while (iVar3 != 0);
  nwk_address_lock_ref(auStack_12[0]);
  iVar3 = core_globals_get();
  *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) | 1;
  nwk_secur_set_key(param_1 + 0x10,0);
  nwk_secur_switch_key(0);
  zdo_initiate_commissioning(0x80);
  return 0;
}


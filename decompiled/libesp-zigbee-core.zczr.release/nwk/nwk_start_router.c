/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_start_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_start_router(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char cStack_15;
  int aiStack_14 [2];
  
  iVar3 = nwk_is_joined();
  if ((iVar3 == 0) || (iVar3 = nwk_is_device_zczr(), iVar3 == 0)) {
    uVar2 = 0x2c2;
  }
  else {
    nwk_neighbor_table_restore();
    iVar3 = nwk_is_device_zczr();
    if (iVar3 != 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      iVar3 = core_globals_get();
      *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) | 2;
      iVar3 = core_globals_get();
      cVar1 = *(char *)(iVar3 + 0xa3d);
      iVar3 = core_globals_get();
      cStack_15 = cVar1 + *(char *)(iVar3 + 0xa3e) + '\x0f';
      aiStack_14[0] = core_globals_get();
      aiStack_14[0] = aiStack_14[0] + 0xa3f;
      iVar3 = nwk_mm_set_pib_attr(0xff,0x45,aiStack_14);
    } while ((iVar3 != 0) || (iVar3 = nwk_mm_set_pib_attr(0xff,0x46,&cStack_15), iVar3 != 0));
    nwk_update_beacon_payload();
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0xac4) != 0) {
      iVar3 = core_globals_get();
      *(uint *)(*(int *)(iVar3 + 0xac4) + 0xc) =
           *(uint *)(*(int *)(iVar3 + 0xac4) + 0xc) & 0xfffffc3f | 0x80;
      iVar3 = core_globals_get();
      *(undefined4 *)(iVar3 + 0xac4) = 0;
    }
    nwk_link_mngr_set_enabled(1);
    time_ticker_register_receiver(1);
    uVar2 = 0;
  }
  return uVar2;
}


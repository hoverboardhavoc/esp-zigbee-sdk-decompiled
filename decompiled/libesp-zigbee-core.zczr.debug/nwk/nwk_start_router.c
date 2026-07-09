/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_start_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_start_router(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_18;
  char acStack_11 [5];
  
  iVar2 = nwk_is_joined();
  if ((iVar2 != 0) && (iVar2 = nwk_is_device_zczr(), iVar2 != 0)) {
    nwk_neighbor_table_restore();
    nwk_set_router_started(1);
    iVar2 = core_globals_get();
    cVar1 = *(char *)(iVar2 + 0xa3d);
    iVar2 = core_globals_get();
    acStack_11[0] = cVar1 + *(char *)(iVar2 + 0xa3e) + '\x0f';
    iStack_18 = core_globals_get();
    iStack_18 = iStack_18 + 0xa3f;
    iVar2 = nwk_mm_set_pib_attr(0xff,0x45,&iStack_18);
    if (iVar2 == 0) {
      iVar2 = nwk_mm_set_pib_attr(0xff,0x46,acStack_11);
      if (iVar2 == 0) {
        nwk_update_beacon_payload();
        iVar2 = core_globals_get();
        if (*(int *)(iVar2 + 0xac4) != 0) {
          iVar2 = core_globals_get();
          *(uint *)(*(int *)(iVar2 + 0xac4) + 0xc) =
               *(uint *)(*(int *)(iVar2 + 0xac4) + 0xc) & 0xfffffc3f | 0x80;
          iVar2 = core_globals_get();
          *(undefined4 *)(iVar2 + 0xac4) = 0;
        }
        nwk_link_mngr_set_enabled(1);
        time_ticker_register_receiver(1);
        return 0;
      }
    }
    else {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk.c",0x2d8,"nwk_start_router",
                    "(nwk_mm_set_pib_attr(0xFF, 0x45U, &beacon_payload)) == 0");
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk.c",0x2d9,"nwk_start_router",
                  "(nwk_mm_set_pib_attr(0xFF, 0x46U, &beacon_payload_length)) == 0");
    iVar2 = nwk_is_joined_and_authed();
    if ((iVar2 == 0) || (iVar2 = nwk_is_device_zed(), iVar2 == 0)) {
      uVar3 = 0x2c2;
    }
    else {
      iVar2 = core_globals_get();
      if (*(char *)(iVar2 + 0x9ee) == '\0') {
        nwk_pim_start_poll();
      }
      nwk_ed_start_keepalive();
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0x2c2;
}


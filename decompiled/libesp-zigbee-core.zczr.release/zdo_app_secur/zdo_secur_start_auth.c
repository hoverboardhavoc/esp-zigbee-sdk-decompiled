/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> zdo_secur_start_auth
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_secur_start_auth(zdo_secur_callback_t cb,void *user_ctx)

{
  ezb_err_t eVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = core_globals_get();
  if ((*(char *)(iVar2 + 0xd5c) == '\0') && (iVar2 = nwk_secur_is_authenticated(), iVar2 == 0)) {
    aps_secur_get_tc_address();
    iVar2 = aps_secur_key_pair_find_or_create();
    eVar1 = 1;
    if ((iVar2 != 0) && (eVar1 = aps_secur_joiner_setup_key_pair(), eVar1 == 0)) {
      iVar2 = core_globals_get();
      *(zdo_secur_callback_t *)(iVar2 + 0xd70) = cb;
      iVar2 = core_globals_get();
      *(void **)(iVar2 + 0xd74) = user_ctx;
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xd5c) = 1;
      iVar2 = core_globals_get();
      iVar3 = core_globals_get();
      milli_timer_start(iVar2 + 0xd60,(uint)*(byte *)(iVar3 + 0x9b4) * 1000);
      iVar2 = nwk_is_device_zed();
      if (iVar2 != 0) {
        iVar2 = core_globals_get();
        if (*(char *)(iVar2 + 0x9ee) == '\0') {
          nwk_pim_start_poll();
        }
      }
      nwk_pim_start_fast_poll(0);
    }
  }
  else {
    eVar1 = 3;
  }
  return eVar1;
}


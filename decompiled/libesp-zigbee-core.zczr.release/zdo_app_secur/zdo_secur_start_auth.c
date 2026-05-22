/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  if ((*(char *)(iVar2 + 0xcf8) == '\0') && (iVar2 = nwk_secur_is_authenticated(), iVar2 == 0)) {
    aps_secur_get_tc_address();
    iVar2 = aps_secur_key_pair_find_or_create();
    eVar1 = 1;
    if ((iVar2 != 0) && (eVar1 = aps_secur_joiner_setup_key_pair(), eVar1 == 0)) {
      iVar2 = core_globals_get();
      *(zdo_secur_callback_t *)(iVar2 + 0xd0c) = cb;
      iVar2 = core_globals_get();
      *(void **)(iVar2 + 0xd10) = user_ctx;
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xcf8) = 1;
      iVar2 = core_globals_get();
      iVar3 = core_globals_get();
      milli_timer_start(iVar2 + 0xcfc,(uint)*(byte *)(iVar3 + 0x9b4) * 1000);
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


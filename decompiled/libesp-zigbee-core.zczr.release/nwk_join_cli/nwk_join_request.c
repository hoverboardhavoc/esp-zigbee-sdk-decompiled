/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_join_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_join_request(nwk_join_req_t *req)

{
  byte bVar1;
  ezb_err_t eVar2;
  int iVar3;
  
  if (req == (nwk_join_req_t *)0x0) {
_L0:
    eVar2 = 2;
  }
  else {
    iVar3 = core_globals_get();
    eVar2 = 3;
    if (*(char *)(iVar3 + 0xac0) != '\0') goto _L0;
    iVar3 = nwk_is_joined();
    if ((iVar3 != 0) && (req->rejoin_network == '\0')) {
      eVar2 = 0x2c2;
      goto _L0;
    }
    iVar3 = core_globals_get();
    memcpy((void *)(iVar3 + 0xac8),req,0xb);
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar3 + 0xac0) = 2;
    iVar3 = core_globals_get();
    milli_timer_init(iVar3 + 0xad4,nwk_handle_attach_timer,0);
    bVar1 = req->rejoin_network;
    if (bVar1 != 2) {
      if (2 < bVar1) {
        eVar2 = 6;
        if (bVar1 == 3) goto _L0;
        __assert_func(0,0,0,0);
        goto _L0;
      }
      eVar2 = 6;
      if (bVar1 != 0) goto _L0;
    }
    eVar2 = nwk_do_attach(req);
    if (eVar2 == 0) {
      return 0;
    }
  }
_L0:
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xac0) = 0;
  return eVar2;
}


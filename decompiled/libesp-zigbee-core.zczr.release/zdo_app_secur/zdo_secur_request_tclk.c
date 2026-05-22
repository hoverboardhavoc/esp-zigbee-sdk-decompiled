/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> zdo_secur_request_tclk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_secur_request_tclk(zdo_secur_callback_t cb,void *user_ctx)

{
  ezb_err_t eVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uStack_34;
  apsme_request_key_req_t rk_req;
  
  iVar2 = core_globals_get();
  if ((*(char *)(iVar2 + 0xcf8) == '\0') && (iVar2 = nwk_secur_is_authenticated(), iVar2 != 0)) {
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x9b8) = 0;
    rk_req.dst_address.field_0.u64._4_4_ = 4;
    uStack_34 = 0;
    rk_req.dst_address.field_0.u64._0_4_ = 0;
    rk_req._8_4_ = 0;
    rk_req.partner_address.field_0.u8[3] = '\0';
    puVar3 = (undefined4 *)aps_secur_get_tc_address();
    uStack_34 = *puVar3;
    rk_req.dst_address.field_0.u64._0_4_ = puVar3[1];
    eVar1 = apsme_request_key_request(&uStack_34);
    if (eVar1 == 0) {
      iVar2 = core_globals_get();
      *(zdo_secur_callback_t *)(iVar2 + 0xd0c) = cb;
      iVar2 = core_globals_get();
      *(void **)(iVar2 + 0xd10) = user_ctx;
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xcf8) = 2;
      iVar2 = core_globals_get();
      iVar4 = core_globals_get();
      milli_timer_start(iVar2 + 0xcfc,(*(ushort *)(iVar4 + 0x9ba) & 0x1f) * 1000);
      nwk_pim_start_fast_poll(0);
    }
  }
  else {
    eVar1 = 3;
  }
  return eVar1;
}


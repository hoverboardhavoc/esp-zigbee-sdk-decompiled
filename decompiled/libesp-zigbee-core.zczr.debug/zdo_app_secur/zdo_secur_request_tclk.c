/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_secur_request_tclk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_secur_request_tclk(zdo_secur_callback_t cb,void *user_ctx)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_34;
  apsme_request_key_req_t rk_req;
  
  iVar1 = core_globals_get();
  if ((*(char *)(iVar1 + 0xd5c) == '\0') && (iVar1 = nwk_secur_is_authenticated(), iVar1 != 0)) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x9b8) = 0;
    uStack_34 = 0;
    rk_req.dst_address.field_0.u64._0_4_ = 0;
    rk_req._8_4_ = 0;
    rk_req.partner_address.field_0.u8[3] = '\0';
    rk_req.dst_address.field_0.u64._4_4_ = 4;
    puVar2 = (undefined4 *)aps_secur_get_tc_address();
    uStack_34 = *puVar2;
    rk_req.dst_address.field_0.u64._0_4_ = puVar2[1];
    iVar1 = apsme_request_key_request(&uStack_34);
    if (iVar1 == 0) {
      iVar3 = core_globals_get();
      *(zdo_secur_callback_t *)(iVar3 + 0xd70) = cb;
      iVar3 = core_globals_get();
      *(void **)(iVar3 + 0xd74) = user_ctx;
      iVar3 = core_globals_get();
      *(undefined1 *)(iVar3 + 0xd5c) = 2;
      iVar3 = core_globals_get();
      iVar4 = core_globals_get();
      milli_timer_start(iVar3 + 0xd60,(*(ushort *)(iVar4 + 0x9ba) & 0x1f) * 1000);
      nwk_pim_start_fast_poll(0);
    }
  }
  else {
    iVar1 = 3;
  }
  return iVar1;
}


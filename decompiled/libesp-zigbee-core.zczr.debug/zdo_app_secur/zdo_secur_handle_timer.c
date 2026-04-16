/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_secur_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zdo_secur_handle_timer(void)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uStack_24;
  apsme_request_key_req_t rk_req;
  
  nwk_pim_stop_fast_poll();
  iVar2 = core_globals_get();
  bVar1 = *(byte *)(iVar2 + 0xd5c);
  if (bVar1 == 1) {
    iVar2 = nwk_is_device_zed();
    if ((iVar2 != 0) && (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x9ee) == '\0')) {
      nwk_pim_stop_poll();
    }
    zdo_secur_perform_leave();
    return;
  }
  if (bVar1 < 2) {
    if (bVar1 == 0) {
      return;
    }
_L0:
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_app_secur.c",0x8f,"zdo_secur_handle_timer",
                  &_LC0);
  }
  else {
    if (1 < (byte)(bVar1 - 2)) goto _L0;
    iVar2 = core_globals_get();
    bVar1 = *(byte *)(iVar2 + 0x9b8);
    iVar2 = core_globals_get();
    if (bVar1 < *(byte *)(iVar2 + 0x9b9)) {
      iVar2 = core_globals_get();
      *(char *)(iVar2 + 0x9b8) = *(char *)(iVar2 + 0x9b8) + '\x01';
      iVar2 = core_globals_get();
      if (*(char *)(iVar2 + 0xd5c) == '\x02') {
        uStack_24 = 0;
        rk_req.dst_address.field_0.u64._0_4_ = 0;
        rk_req._8_4_ = 0;
        rk_req.partner_address.field_0.u8[3] = '\0';
        rk_req.dst_address.field_0.u64._4_4_ = 4;
        puVar3 = (undefined4 *)aps_secur_get_tc_address();
        uStack_24 = *puVar3;
        rk_req.dst_address.field_0.u64._0_4_ = puVar3[1];
        iVar2 = apsme_request_key_request(&uStack_24);
      }
      else {
        uStack_24 = 0;
        rk_req.dst_address.field_0.u64._0_4_ = 0;
        rk_req.dst_address.field_0.u64._5_3_ = (int3)((uint)rk_req.dst_address.field_0._4_4_ >> 8);
        rk_req.dst_address.field_0.u8[4] = 4;
        puVar3 = (undefined4 *)aps_secur_get_tc_address();
        uStack_24 = *puVar3;
        rk_req.dst_address.field_0.u64._0_4_ = puVar3[1];
        iVar2 = apsme_verify_key_request(&uStack_24);
      }
      if (iVar2 == 0) {
        nwk_pim_start_fast_poll(0);
        iVar2 = core_globals_get();
        iVar4 = core_globals_get();
        milli_timer_start(iVar2 + 0xd60,(*(ushort *)(iVar4 + 0x9ba) & 0x1f) * 1000);
        return;
      }
      if (iVar2 == 0) {
        return;
      }
      if (iVar2 == 0xc) {
        return;
      }
      goto _L0;
    }
  }
  iVar2 = 7;
_L0:
  zdo_secur_finish_state(iVar2);
  return;
}


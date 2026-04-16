/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> zdo_secur_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rk_req */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zdo_secur_handle_timer(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  code *UNRECOVERED_JUMPTABLE;
  code *pcStack_24;
  apsme_request_key_req_t rk_req;
  
  nwk_pim_stop_fast_poll();
  iVar2 = core_globals_get();
  bVar1 = *(byte *)(iVar2 + 0xd5c);
  if (bVar1 != 1) {
    if (bVar1 < 2) {
      return;
    }
    if ((byte)(bVar1 - 2) < 2) {
      iVar2 = core_globals_get();
      bVar1 = *(byte *)(iVar2 + 0x9b8);
      iVar2 = core_globals_get();
      if (bVar1 < *(byte *)(iVar2 + 0x9b9)) {
        iVar2 = core_globals_get();
        *(char *)(iVar2 + 0x9b8) = *(char *)(iVar2 + 0x9b8) + '\x01';
        iVar2 = core_globals_get();
        pcStack_24 = (code *)0x0;
        rk_req.dst_address.field_0.u64._0_4_ = 0;
        if (*(char *)(iVar2 + 0xd5c) == '\x02') {
          rk_req.dst_address.field_0.u64._4_4_ = 4;
          rk_req._8_4_ = 0;
          rk_req.partner_address.field_0.u8[3] = '\0';
          puVar4 = (undefined4 *)aps_secur_get_tc_address();
          pcStack_24 = (code *)*puVar4;
          rk_req.dst_address.field_0.u64._0_4_ = puVar4[1];
          iVar2 = apsme_request_key_request(&pcStack_24);
        }
        else {
          rk_req.dst_address.field_0.u8[4] = 4;
          puVar4 = (undefined4 *)aps_secur_get_tc_address();
          pcStack_24 = (code *)*puVar4;
          rk_req.dst_address.field_0.u64._0_4_ = puVar4[1];
          iVar2 = apsme_verify_key_request(&pcStack_24);
        }
        if (iVar2 == 0) {
          nwk_pim_start_fast_poll(0);
          iVar2 = core_globals_get();
          iVar3 = core_globals_get();
          milli_timer_start(iVar2 + 0xd60,(*(ushort *)(iVar3 + 0x9ba) & 0x1f) * 1000);
          return;
        }
        if (iVar2 == 0xc) {
          return;
        }
      }
      else {
        iVar2 = 7;
      }
      iVar3 = core_globals_get();
      milli_timer_stop(iVar3 + 0xd60);
      iVar3 = core_globals_get();
      *(undefined1 *)(iVar3 + 0xd5c) = 0;
      iVar3 = core_globals_get();
      if (*(int *)(iVar3 + 0xd70) == 0) {
        return;
      }
      iVar3 = core_globals_get();
      UNRECOVERED_JUMPTABLE = *(code **)(iVar3 + 0xd70);
      iVar3 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x0001006c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(iVar2,*(undefined4 *)(iVar3 + 0xd74),UNRECOVERED_JUMPTABLE);
      return;
    }
    __assert_func(0,0,0,0);
  }
  iVar2 = nwk_is_device_zed();
  if ((iVar2 != 0) && (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x9ee) == '\0')) {
    nwk_pim_stop_poll();
  }
  iVar2 = zdo_create_mgmt_req(0x34);
  if (iVar2 != 0) {
    iVar3 = zdo_mgmt_req_get_param();
    *(byte *)(iVar3 + 8) = *(byte *)(iVar3 + 8) | 2;
    iVar3 = zdo_mgmt_req_get_param(iVar2);
    *(byte *)(iVar3 + 8) = *(byte *)(iVar3 + 8) & 0xfe;
    rk_req.dst_address.field_0.u64._0_4_ = 0;
    pcStack_24 = zdo_secur_finish_state_after_leave;
    zdo_mgmt_req_set_user_ctx(iVar2,&pcStack_24);
    zdo_send_mgmt_req(iVar2,0);
  }
  return;
}


/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> zdo_secur_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_secur_handle_timer(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  code *UNRECOVERED_JUMPTABLE;
  code *pcStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  nwk_pim_stop_fast_poll();
  iVar2 = core_globals_get();
  bVar1 = *(byte *)(iVar2 + 0xcf8);
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
        uStack_20 = 0;
        if (*(char *)(iVar2 + 0xcf8) == '\x02') {
          uStack_1c = 4;
          uStack_18 = 0;
          uStack_14 = 0;
          puVar4 = (undefined4 *)aps_secur_get_tc_address();
          pcStack_24 = (code *)*puVar4;
          uStack_20 = puVar4[1];
          iVar2 = apsme_request_key_request(&pcStack_24);
        }
        else {
          uStack_1c = CONCAT31(uStack_1c._1_3_,4);
          puVar4 = (undefined4 *)aps_secur_get_tc_address();
          pcStack_24 = (code *)*puVar4;
          uStack_20 = puVar4[1];
          iVar2 = apsme_verify_key_request(&pcStack_24);
        }
        if (iVar2 == 0) {
          nwk_pim_start_fast_poll(0);
          iVar2 = core_globals_get();
          iVar3 = core_globals_get();
          milli_timer_start(iVar2 + 0xcfc,(*(ushort *)(iVar3 + 0x9ba) & 0x1f) * 1000);
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
      milli_timer_stop(iVar3 + 0xcfc);
      iVar3 = core_globals_get();
      *(undefined1 *)(iVar3 + 0xcf8) = 0;
      iVar3 = core_globals_get();
      if (*(int *)(iVar3 + 0xd0c) == 0) {
        return;
      }
      iVar3 = core_globals_get();
      UNRECOVERED_JUMPTABLE = *(code **)(iVar3 + 0xd0c);
      iVar3 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x0001006c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(iVar2,*(undefined4 *)(iVar3 + 0xd10),UNRECOVERED_JUMPTABLE);
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
    uStack_20 = 0;
    pcStack_24 = zdo_secur_finish_state_after_leave;
    zdo_mgmt_req_set_user_ctx(iVar2,&pcStack_24);
    zdo_send_mgmt_req(iVar2,0);
  }
  return;
}

